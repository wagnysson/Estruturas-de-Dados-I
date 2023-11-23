#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "caminho.h"
#include "ponto.h"

struct _caminho{
    int qtd_pontos;
    PONTO **pontos;
};


CAMINHO *ler_caminho(){
    CAMINHO *caminho = NULL;
    int i, N;

    scanf("%d", &N);

    caminho = (CAMINHO *) malloc(sizeof(CAMINHO));
    caminho->pontos = (PONTO **) malloc(N*sizeof(PONTO *));
    caminho->qtd_pontos = N;


    for ( i = 0; i < N; i++)
    {
        caminho->pontos[i] = ler_ponto();
    }
    
    return caminho;
};

float distancia_caminho(CAMINHO *caminho){
    int i;
    float distancia_total = 0;

    for ( i = 0; i < caminho->qtd_pontos-1; i++)
    {
        distancia_total += distancia_pontos(caminho->pontos[i], caminho->pontos[i+1]);
    }

    

    return distancia_total;
};

void free_caminho(CAMINHO *caminho){
    int i;

    for ( i = 0; i < caminho->qtd_pontos; i++)
    {
        free(caminho->pontos[i]);
    };
    free(caminho->pontos);
    free(caminho);
    return;
}

