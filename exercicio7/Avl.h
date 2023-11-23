#ifndef TADGENERICO_AVL_H
#define TADGENERICO_AVL_H

#include "jogo.h"

typedef int boolean;

#define max(a, b) ((a > b) ? a : b)
typedef struct avl AVL;

void avl_apagar(AVL **arvore);
AVL *avl_criar();
boolean avl_inserir(AVL *arvore, JOGO *item);
AVL *gerar_avl();
void remover_jogos(AVL *arvore);

#endif //TADGENERICO_AVL_H
