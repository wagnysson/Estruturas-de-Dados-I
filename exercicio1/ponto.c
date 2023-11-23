#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct _ponto{
    float x;
    float y;
};

PONTO *ler_ponto(){
    PONTO *ponto = NULL;
    float x, y;
    
    ponto = (PONTO *) malloc(sizeof(PONTO));
    

    scanf("%f", &x);
    scanf("%f", &y);

    ponto->x = x;
    ponto->y = y;
    
    return ponto;
};

float distancia_pontos(PONTO *a, PONTO *b){
    return sqrt(pow((b->x - a->x), 2) + pow((b->y - a->y), 2));
};


