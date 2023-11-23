#ifndef PILHA_H
#define PILHA_H

#define TAM 100
#define ERRO_PILHA (-300)

#include "Util.h"
#include "carta.h"

typedef struct pilha_ PILHA;
typedef struct node_st NODE;

PILHA* pilha_criar();
boolean pilha_vazia(const PILHA *pilha);
boolean pilha_cheia(const PILHA *pilha);
int pilha_tamanho(const PILHA *pilha);
int pilha_empilhar(PILHA *pilha, CARTA *carta);
CARTA* pilha_topo(const PILHA *pilha);
CARTA* pilha_desempilhar(PILHA *pilha);
boolean pilha_apagar(PILHA **pilha);
void pilha_remove_tudo(PILHA **pilha);
void pilha_remove_topo(PILHA **pilha);
PILHA *ler_baralho(PILHA *pilha);
int contagem(PILHA *pilha);
void libera_memoria(PILHA *baralho);

#endif //PILHA_H