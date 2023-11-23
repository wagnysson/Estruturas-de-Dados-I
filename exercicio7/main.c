#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "Avl.h"


int main() {
    int impressao;
    AVL *arvore;

    scanf("%d", &impressao);
    arvore = gerar_avl();
    remover_jogos(arvore);
    // printar_arvore();
    // liberar_memoria();


    return 0;
}