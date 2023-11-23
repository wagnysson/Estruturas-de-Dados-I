#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "jogo.h"
#include "Avl.h"
#include "Util.h"

typedef struct node_st NODE;

static void avl_apagar_aux(NODE **raiz);
static NODE *avl_inserir_no_e_rotacionar(NODE *raiz, JOGO *item);

static bool DesbalanceamentoEhNegativo(NODE *raiz);

static bool DesbalanceamentoEhPositivo(NODE *raiz);

static bool ItemEhMaior(const NODE *raiz, JOGO *item);

static bool ItemEhMenor(const NODE *raiz, JOGO *item);

static NODE *selecionar_e_executar_rotacao(NODE *raiz, JOGO *item);

static NODE *inserir_no(NODE *raiz, JOGO *item);

static void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant);
static boolean avl_remover_aux (NODE **raiz, int chave);

struct node_st
{
    JOGO *item;
    NODE *direita;
    NODE *esquerda;
    int altura;
};

struct avl
{
    NODE* raiz;
    int profundidade;
};

AVL *avl_criar() {
    AVL *arvore = (AVL *) malloc(sizeof(AVL));
    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

static void avl_apagar_aux(NODE **raiz) {
    if (*raiz != NULL) {
        avl_apagar_aux(&((*raiz)->esquerda));
        avl_apagar_aux(&((*raiz)->direita));
        liberar_jogo((*raiz)->item);
        free(*raiz);
    }
}

void avl_apagar(AVL **arvore) {
    avl_apagar_aux(&(*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}

int avl_altura_no(NODE* raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        return raiz->altura;
    }
}

NODE *avl_cria_no(JOGO *item) {
    NODE *no = (NODE *) malloc(sizeof (NODE));
    if (no != NULL) {
        no->altura = 0;
        no->direita = NULL;
        no->esquerda = NULL;
        no->item = item;
    }
    return no;
}

NODE *rodar_direita(NODE *a) {
    NODE *b = a->esquerda;
    a->esquerda = b->direita;
    b->direita = a;

    a->altura = max(avl_altura_no(a->esquerda),
                    avl_altura_no(a->direita)) + 1;
    b->altura = max(avl_altura_no(b->esquerda),
                    a->altura) + 1;
    return b;
}

NODE *rodar_esquerda(NODE *a) {
    NODE *b = a->direita;
    a->direita = b->esquerda;
    b->esquerda = a;

    a->altura = max(avl_altura_no(a->esquerda),
                    avl_altura_no(a->direita)) + 1;
    b->altura = max(avl_altura_no(b->direita),
                    a->altura) + 1;
    return b;
}

NODE *rodar_esquerda_direita(NODE *a)   {
    a->esquerda = rodar_esquerda(a->esquerda);
    return rodar_direita(a);
}

NODE *rodar_direita_esquerda(NODE *a)   {
    a->direita = rodar_direita(a->direita);
    return rodar_esquerda(a);
}

static NODE *avl_inserir_no_e_rotacionar(NODE *raiz, JOGO *item) {
    raiz = inserir_no(raiz, item);

    raiz->altura = max(avl_altura_no(raiz->esquerda),
                       avl_altura_no(raiz->direita)) + 1;

    raiz = selecionar_e_executar_rotacao(raiz, item);

    return raiz;
}

//TODO: resolver problema do item const
static NODE *inserir_no(NODE *raiz, JOGO *item) {
    if (raiz == NULL) {
        raiz = avl_cria_no(item);
    }
    else if (ItemEhMaior(raiz, item)) {
        raiz->direita = avl_inserir_no_e_rotacionar(raiz->direita, item);
    }
    else if (ItemEhMenor(raiz, item)) {
        raiz->esquerda = avl_inserir_no_e_rotacionar(raiz->esquerda, item);
    }
    return raiz;
}

static NODE *selecionar_e_executar_rotacao(NODE *raiz, JOGO *item) {
    if (DesbalanceamentoEhNegativo(raiz)) {
        if (ItemEhMaior(raiz->direita, item)) {
            raiz = rodar_esquerda(raiz);
        }
        else {
            raiz = rodar_direita_esquerda(raiz);
        }
    }

    if (DesbalanceamentoEhPositivo(raiz)) {
        if (ItemEhMenor(raiz->esquerda, item))
            raiz = rodar_direita(raiz);
        else
            raiz = rodar_esquerda_direita(raiz);
    }
    return raiz;
}

static bool ItemEhMenor(const NODE *raiz, JOGO *item) {
    return get_ano(item) < get_ano(raiz->item);
}

static bool ItemEhMaior(const NODE *raiz, JOGO *item) {
    return get_ano(item) > get_ano(raiz->item);
}

static bool DesbalanceamentoEhPositivo(NODE *raiz) {
    return avl_altura_no(raiz->esquerda)
               - avl_altura_no(raiz->direita) == 2;
}

static bool DesbalanceamentoEhNegativo(NODE *raiz) {
    return avl_altura_no(raiz->esquerda)
               - avl_altura_no(raiz->direita) == -2;
}

boolean avl_inserir(AVL *arvore, JOGO *item) {
    arvore->raiz = avl_inserir_no_e_rotacionar(arvore->raiz, item);
    return arvore->raiz != NULL;
}

static boolean avl_remover_aux (NODE **raiz, int chave){
    NODE *noRemovido;
    if(*raiz == NULL)
    {
        return FALSE;
    }
    if(chave == get_ano((*raiz)->item))
    {
        if ((*raiz)->esquerda == NULL|| (*raiz)->direita == NULL)
        {/*Caso 1 se resume ao caso 2: há um filho ou nenhum*/
            noRemovido = *raiz;
            if((*raiz)->esquerda == NULL) {
                *raiz = (*raiz)->direita;
            }
            else {
                *raiz = (*raiz)->esquerda;
            }
            free(noRemovido);
            noRemovido = NULL;
        }
        else /*Caso 3: há ambos os filhos*/
        {
            troca_max_esq((*raiz)->esquerda, (*raiz), (*raiz));
        }
        return TRUE;
    }
    else
    {
        if(chave < get_ano((*raiz)->item))
            return avl_remover_aux (&(*raiz)->esquerda, chave);
        else
            return avl_remover_aux (&(*raiz)->direita, chave);
    }
}

boolean avl_remover(AVL *T, int chave){
    if (T != NULL)
        return avl_remover_aux(&T->raiz, chave);
    return FALSE;
}

static void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant)
{
    if(troca->direita != NULL)
    {
        troca_max_esq(troca->direita, raiz, troca);
        return;
    }
    if(raiz == ant) {
        ant->esquerda = troca->esquerda;
    }
    else {
        ant->direita = troca->esquerda;
    }
    raiz->item = troca->item;
    free(troca);
    troca = NULL;
}


AVL *gerar_avl(){
    AVL *arvore;
    FILE *jogos = fopen("CSV-TodosJogos.csv", "r");
    char *nome, *empresa;
    int ano, count = 0; 
    JOGO *jogo;

    arvore = avl_criar();

    char line[256];
    //fgets() le a linha ate encontrar uma quebra de linha (\n) ou ate chegar em 256 caracteres e guarda a linha inteira em line
    //no while ele vai fazer isso ateh o fim do arquivo
    while (fgets(line, 256, jogos) != NULL){ 
        //strtok() le a linha e define que vai tokenizar (quebrar em pedacos menores) sempre que encontrar ";" e guardar em value
        char *value = strtok(line, ";"); 
        //isso vai ocorrer ate que o fgets chegue em uma linha vazia, assim o value vai ser NULL
        while (value != NULL){ 
        //em cada iteracao do while o strtok pega a string que tem antes do ; e guarda em value entao usamos um contador 
        //pra ele pegar cada coisa em sua devida iteracao e guardar nos lugares corretos
            if (count % 3 == 0)
                nome = value;
            else
                if (count % 3 == 1)
                    ano = atoi(value);
                else
                    if(count % 3 == 2)
                        empresa = value;
            
            // printf("%d----------\n", count);
            // printf("nome: %s\n", nome);
            // printf("ano: %d\n", ano);
            // printf("empresa: %s\n", empresa);

            //sempre que ocorrem 3 iteracoes um jogo eh guardado na variavel jogo
            if(count % 3 == 0 && count>0){
                jogo = ler_jogo(nome, ano, empresa);
                avl_inserir(arvore, jogo);
            }
            count +=1;

            //strtok() so precisa ser chamado uma vez com a variavel line, as outras vezes ele eh chamado com NULL apenas para
            //continuar a leitura e pegar a string antes do proximo ;
            value = strtok(NULL, ";");
        }
    }

    // fecha o arquivo de jogos para desalocar a memoria que foi guardada para ele
    fclose(jogos);

    return arvore;
}

void remover_jogos(AVL *arvore){
    char *ano_do_jogo;
    int temp, flag = 0;
    
    while (flag == 0){
        ano_do_jogo = readLine();
        if(strcmp(ano_do_jogo, "F") == 0){
            return;
        }else{
            temp = atoi(ano_do_jogo);
            avl_remover(arvore, temp);
        }
    }
}



