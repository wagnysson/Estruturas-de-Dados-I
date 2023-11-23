#ifndef LISTA_H
#define LISTA_H

#include "Util.h"

#define ERRO (-32000)

typedef struct lista LISTA;
typedef struct node_st NODE;

LISTA* lista_criar();
int lista_inserir(LISTA *lista, int item);
int lista_tamanho(const LISTA *lista);
boolean lista_vazia(const LISTA* lista);
NODE *get_inicio(LISTA *lista);
NODE *get_fim(LISTA *lista);
int get_item(NODE *no);
NODE *set_item(NODE *no, int item);
NODE *get_proximo(NODE *no);
void apagar_lista(LISTA *lista);
#endif //LISTA_H

