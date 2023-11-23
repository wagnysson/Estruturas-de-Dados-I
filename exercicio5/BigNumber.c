#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BigNumber.h"
#include "ListaEncadeada.h"
#include "Util.h"

struct bignumber_{
    LISTA *numero;
    int sinal;
};

void cortar_numero(char *numero, LISTA *lista);
int igual(BIGNUMBER *bn1, BIGNUMBER *bn2);
int maior(BIGNUMBER *bn1, BIGNUMBER *bn2);
int abs_maior(BIGNUMBER *bn1, BIGNUMBER *bn2);
int somar_itens(BIGNUMBER *bn1, BIGNUMBER *bn2, NODE *node1, NODE *node2);

BIGNUMBER *ler_bignumber(){
    BIGNUMBER *BigNumber = (BIGNUMBER*) malloc(sizeof(BIGNUMBER));
    char *temp;

    temp = readLine();
    if(temp[0] == '-'){
        BigNumber->sinal = NEGATIVO;
    }else{
        BigNumber->sinal = POSITIVO;
    }
    BigNumber->numero = lista_criar();
    cortar_numero(temp, BigNumber->numero);

    free(temp);

    return BigNumber;
}

void cortar_numero(char *numero, LISTA *BigNumber){
    int i, j, tam = strlen(numero);
    char *temp = (char *) malloc(5*sizeof(char));

    //coloca os algarismos do numero de 4 em 4 na lista, isso do fim ao inicio do número.
    while (tam>4){
        i = 0;
        for (j = tam-4 ; j < tam; j++){
            temp[i] = numero[j];
            i++;
        }
        temp[4] = '\0';
        if(strlen(temp) == 4){
            lista_inserir(BigNumber, atoi(temp));
        }
        tam -= 4;
    }

    //caso em que o número é negativo e o - (string) é armazenado sozinho em um item, ele se torna '0' quando convertido para inteiro,
    //então faço com que ele não seja inserido porque atrapalha nas comparações do igual, soma, maior e menor
    if ((tam == 1) && (numero[0] == '-')){
        free(temp);
        return;
    }

    //se não for esse caso do número negativo, a inserção ocorre normalmente
    for (i = 0; i < tam; i++){
            temp[i] = numero[i];
    }
    temp[i] = '\0';
    lista_inserir(BigNumber, atoi(temp));
    free(temp);
}


int igual(BIGNUMBER *bn1, BIGNUMBER *bn2){
    NODE *nodeAtual1, *nodeAtual2;

    if(lista_tamanho(bn1->numero) != lista_tamanho(bn2->numero)){
        return FALSE;
    }else{
        nodeAtual1 = get_inicio(bn1->numero);
        nodeAtual2 = get_inicio(bn2->numero);
        while((nodeAtual1 != NULL)){
            if(get_item(nodeAtual1) != get_item(nodeAtual2)){ 
                return FALSE;
            }else{
                nodeAtual1 = get_proximo(nodeAtual1);
                nodeAtual2 = get_proximo(nodeAtual2);
            }
        }
        return TRUE;
    }
}

int maior(BIGNUMBER *bn1, BIGNUMBER *bn2){

    if ((bn1->sinal == 0) && (bn2->sinal == 1)){
        return TRUE;
    }
    if ((bn1->sinal == 1) && (bn2->sinal == 0)){
        return FALSE;
    }
    if (bn1->sinal == bn2->sinal){
        return abs_maior(bn1, bn2);
    }
    return ERRO; 

}

int abs_maior(BIGNUMBER *bn1, BIGNUMBER *bn2){
    int counter, i;
    NODE *nodeAtual1, *nodeAtual2;

    if(lista_tamanho(bn1->numero)>lista_tamanho(bn2->numero)){
        return TRUE;
    }
    if (lista_tamanho(bn1->numero)<lista_tamanho(bn2->numero)){
        return FALSE;
    }
    if (lista_tamanho(bn1->numero)==lista_tamanho(bn2->numero)){
        counter = lista_tamanho(bn1->numero);
        nodeAtual1 = get_fim(bn1->numero);
        nodeAtual2 = get_fim(bn2->numero);
        while (counter > 0){
            if (get_item(nodeAtual1) > get_item(nodeAtual2)){
                return TRUE;
            }
            if (get_item(nodeAtual1) < get_item(nodeAtual2)){
                return FALSE;
            }
            if (get_item(nodeAtual1) == get_item(nodeAtual2)){
                nodeAtual1 = get_inicio(bn1->numero);
                nodeAtual2 = get_inicio(bn2->numero);
                counter--;
                for (i = 0; i < counter-1; i++){
                    nodeAtual1 = get_proximo(nodeAtual1);
                    nodeAtual2 = get_proximo(nodeAtual2);
                }
            }
        }
    }
    return -1; //os numeros são iguais
}

int somar_itens(BIGNUMBER *bn1, BIGNUMBER *bn2, NODE *node1, NODE *node2){
    int temp;
    if (bn1->sinal != bn2->sinal){ //se o sinal for diferente sempre pegamos o menor item e subtraimos do maior
        if (get_item(node1)>get_item(node2)){
            temp = get_item(node1) - get_item(node2);
        }
        if (get_item(node1)<get_item(node2)){
            temp = get_item(node2) - get_item(node1);
        }
    }

    if (bn1->sinal == bn2->sinal){ //se o sinal for igual somamos normalmente
        temp = get_item(node1) + get_item(node2);
    }
    return temp;
}

BIGNUMBER *soma(BIGNUMBER *bn1, BIGNUMBER *bn2){
    int counter, temp, flag = 0;
    NODE *nodeAtual1, *nodeAtual2;
    BIGNUMBER *novobn = (BIGNUMBER*) malloc(sizeof(BIGNUMBER));

    novobn->numero = lista_criar();

    if(lista_tamanho(bn1->numero) == lista_tamanho(bn2->numero)){
        counter = lista_tamanho(bn1->numero);
        nodeAtual1 = get_inicio(bn1->numero);
        nodeAtual2 = get_inicio(bn2->numero);
        while (counter > 0){
            if(abs_maior(bn1, bn2) == 2){
                if(bn1->sinal == 0){
                    novobn->sinal = 0;
                }else{
                    novobn->sinal = 1;
                }
            }
            if(abs_maior(bn1,bn2) == 3){
                if(bn2->sinal == 0){
                    novobn->sinal = 0;
                }else{
                    novobn->sinal = 1;
                }
            }
            temp = somar_itens(bn1, bn2, nodeAtual1, nodeAtual2);
            
            if(temp>10000){
                if(get_proximo(nodeAtual1) == NULL && flag == 0){
                    lista_inserir(bn1->numero, 0);
                    lista_inserir(bn2->numero, 0);
                    counter++;
                    flag = 1;
                }
                set_item(get_proximo(nodeAtual1), get_item(get_proximo(nodeAtual1))+1);
                temp = (get_item(nodeAtual1) + get_item(nodeAtual2))%10000;
            }
            lista_inserir(novobn->numero, temp);
            if (get_proximo(nodeAtual1) != NULL && get_proximo(nodeAtual2) != NULL){
                nodeAtual1 = get_proximo(nodeAtual1);
                nodeAtual2 = get_proximo(nodeAtual2);
            }
            
            counter--;
        }
    }
    
    if(lista_tamanho(bn1->numero) != lista_tamanho(bn2->numero)){
        if (lista_tamanho(bn1->numero) > lista_tamanho(bn2->numero)){
            counter = lista_tamanho(bn1->numero);
        }
        // printf("o contador usado é: %d\n", counter);
        if (lista_tamanho(bn1->numero) < lista_tamanho(bn2->numero)){
            counter = lista_tamanho(bn2->numero);
        }
        nodeAtual1 = get_inicio(bn1->numero);
        nodeAtual2 = get_inicio(bn2->numero);
        while (counter > 0){
            if(abs_maior(bn1, bn2) == 2){
                if(bn1->sinal == 0){
                    novobn->sinal = 0;
                }else{
                    novobn->sinal = 1;
                }
            }
            if(abs_maior(bn1,bn2) == 3){
                if(bn2->sinal == 0){
                    novobn->sinal = 0;
                }else{
                    novobn->sinal = 1;
                }
            }
            temp = somar_itens(bn1, bn2, nodeAtual1, nodeAtual2);
            if(lista_tamanho(bn1->numero) > lista_tamanho(bn2->numero)){
                if(get_proximo(nodeAtual1) != NULL && get_proximo(nodeAtual2) == NULL){
                    lista_inserir(bn2->numero, 0);
                }
            }
            if(lista_tamanho(bn1->numero) < lista_tamanho(bn2->numero)){
                if(get_proximo(nodeAtual2) != NULL && get_proximo(nodeAtual1) == NULL){
                    lista_inserir(bn1->numero, 0);
                }
            }
            if(temp>10000){
                set_item(get_proximo(nodeAtual1), (get_item(get_proximo(nodeAtual1))+1));
                temp = (get_item(nodeAtual1) + get_item(nodeAtual2))%10000;
            }
            
            lista_inserir(novobn->numero, temp);
            if (get_proximo(nodeAtual1) != NULL && get_proximo(nodeAtual2) != NULL){
                nodeAtual1 = get_proximo(nodeAtual1);
                nodeAtual2 = get_proximo(nodeAtual2);
            }
            counter--;
        }
    }
    return novobn;
} 

int realizar_operacao(char *operacao, BIGNUMBER *bn1, BIGNUMBER *bn2){
    int resultado;
    
    if(strcmp(operacao, "igual") == 0){
        resultado = igual(bn1, bn2);
    }

    if(strcmp(operacao, "maior") == 0){
        resultado = maior(bn1, bn2);
    }

    if(strcmp(operacao, "menor") == 0){
        resultado = maior(bn1, bn2);
    }
    return resultado;
}

void printar_soma(BIGNUMBER *resultado){
    int i, j, counter;
    NODE *nodeAtual = get_fim(resultado->numero);

    printf("Resultado :: ");
    if (resultado->sinal == 1){
        printf("-");
    }
    counter = lista_tamanho(resultado->numero);
    while (counter > 0){
        j = 1000;
        while ((get_item(nodeAtual)<j) && (j>1) && (get_proximo(nodeAtual) != NULL) ){
            printf("0");
            j=j/10;
        }
        printf("%d", get_item(nodeAtual));
        
        nodeAtual = get_inicio(resultado->numero);
        counter--;
        for (i = 0; i < counter-1; i++){
            nodeAtual = get_proximo(nodeAtual);
        }

    }
    printf("\n");
    
}

void printar_resultado(char *operacao, int resultado){
    if (strcmp(operacao, "menor") == 0){
        if(resultado == 3){
        printf("Resultado :: True\n");
        }
        if (resultado == 2){
            printf("Resultado :: False\n");
        }
    }else{
        if(resultado == 2){
            printf("Resultado :: True\n");
        }
        if (resultado == 3){
            printf("Resultado :: False\n");
        }
    }

    if(resultado == -1){
        printf("Resultado :: False\n");
    }
}

void liberar_memoria(char *operacao, BIGNUMBER *bn1, BIGNUMBER *bn2, BIGNUMBER *resultado){
    apagar_lista(bn1->numero);
    free(bn1);

    apagar_lista(bn2->numero);
    free(bn2);

    if(strcmp(operacao, "soma") == 0 ){
        apagar_lista(resultado->numero);
        free(resultado);
    }

    free(operacao);
}