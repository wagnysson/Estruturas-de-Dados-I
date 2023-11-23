#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "jogo.h"

struct catalogo_{
    JOGO **jogos;
    int qtd_de_jogos;
};


CATALOGO *criar_catalogo(){
    CATALOGO *catalogo;
    int i = 1;

    catalogo = (CATALOGO *) malloc(sizeof(CATALOGO));
    catalogo->jogos = (JOGO **) malloc(2*sizeof(JOGO *));
    catalogo->jogos[0] = nada_encontrado();
    
     do{
        catalogo->jogos[i] = ler_jogo();
        catalogo->qtd_de_jogos = i;
        if (strcmp(get_nome(catalogo->jogos[i]), "F") != 0){
            catalogo->jogos = realloc(catalogo->jogos, ((catalogo->qtd_de_jogos)+2)*sizeof(JOGO *));
        }
        i++;
    }while(strcmp(get_nome(catalogo->jogos[i-1]), "F") != 0);
    catalogo->qtd_de_jogos -= 1;
    return catalogo;
}

void consultar_catalogo(CATALOGO *catalogo){
    char flag, *empresa_buscada, temp;
    int i, j = 0, ano_buscado;
    int *resultados, nada;

    resultados = (int *) malloc(sizeof(int));

    do{
        nada = 0;
        scanf(" %c", &flag);

        if (flag == 'A'){
            scanf("%c ", &temp);
            char *c_ano = readLine();
            ano_buscado = atoi(c_ano);
            free(c_ano);
            for (i = 1; i <= catalogo->qtd_de_jogos; i++){
                if(ano_buscado == get_ano(catalogo->jogos[i])){
                    resultados[j] = i;
                    j++;
                    resultados = (int*) realloc(resultados, (j+1)*sizeof(int));
                    nada = 1;
                }
            }
        }

        if(flag == 'E'){
            scanf("%c ", &temp);
            empresa_buscada = readLine();
            for (i = 1; i <= catalogo->qtd_de_jogos; i++){
                if (strcmp(empresa_buscada, get_empresa(catalogo->jogos[i])) == 0){
                    resultados[j] = i;
                    j++;
                    resultados = (int*) realloc(resultados, (j+1)*sizeof(int));
                    nada = 1;
                }
            }
            free(empresa_buscada);
        }
        
    
        if (nada == 0 && flag != 'F'){
            resultados[j] = 0;
            j++;
            resultados= (int*) realloc(resultados, (j+1)*sizeof(int));
        }
        
    } while (flag != 'F');
    
    for (i = 0; i < j; i++){
        printf("%s\n", get_nome(catalogo->jogos[resultados[i]])); 
    }
    
    free(resultados);
    
    return;
};

void liberar_catalogo(CATALOGO *catalogo){
    int i;
    free(catalogo->jogos[0]);
    for (i = 1; i <= catalogo->qtd_de_jogos; i++){
        liberar_jogo(catalogo->jogos[i]);
    }
    liberar_nome(catalogo->jogos[i]);
    free(catalogo->jogos[i]);
    
    free(catalogo->jogos);
    free(catalogo);
};
