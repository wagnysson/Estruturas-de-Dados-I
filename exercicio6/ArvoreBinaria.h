#ifndef TADGENERICO_ARVOREBINARIA_H
#define TADGENERICO_ARVOREBINARIA_H

#include "Util.h"
#include "Cliente.h"

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct node_st NODE;


ARVORE_BINARIA *arvore_binaria_criar();
void arvore_binaria_pre_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_em_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_pos_ordem(ARVORE_BINARIA *arvoreBinaria);
boolean arvore_binaria_inserir(ARVORE_BINARIA *T, CLIENTE *item, int lado, int chave);
boolean arvore_binaria_remover(ARVORE_BINARIA *T, long int chave);
void arvore_binaria_imprimir(ARVORE_BINARIA *T);
boolean abb_inserir (ARVORE_BINARIA *T, CLIENTE *item);
CLIENTE *abb_busca(ARVORE_BINARIA *T, long int chave);
NODE *get_raiz(ARVORE_BINARIA *T);

ARVORE_BINARIA *ler_registros(int n);
CLIENTE *realizar_operacao(char operacao, ARVORE_BINARIA *arvore);
void printar_resultado(char operacao, ARVORE_BINARIA *arvore, CLIENTE *cliente);
void liberar_memoria(ARVORE_BINARIA *arvore);

#endif //TADGENERICO_ARVOREBINARIA_H
