#ifndef _BIGNUMBER_H_
#define _BIGNUMBER_H_

#include "ListaEncadeada.h"

typedef struct bignumber_ BIGNUMBER;

char *readLine();
BIGNUMBER *ler_bignumber();
BIGNUMBER *soma(BIGNUMBER *bn1, BIGNUMBER *bn2);
int realizar_operacao(char *operacao, BIGNUMBER *bn1, BIGNUMBER *bn2);
void printar_soma(BIGNUMBER *resultado);
void printar_resultado(char *operacao, int resultado);
void liberar_memoria(char *operacao, BIGNUMBER *bn1, BIGNUMBER *bn2, BIGNUMBER *resultado);
#endif