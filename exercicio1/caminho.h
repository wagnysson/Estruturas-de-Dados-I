#ifndef _CAMINHO_H_
#define _CAMINHO_H_

#include "ponto.h"

typedef struct _caminho CAMINHO;


CAMINHO *ler_caminho();
float distancia_caminho(CAMINHO *caminho);
void free_caminho(CAMINHO *caminho);

#endif