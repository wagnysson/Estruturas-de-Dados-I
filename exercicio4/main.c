#include <stdio.h>
#include <stdlib.h>
#include "carta.h"
#include "Pilha.h"

int main() {
    int resultado;
    PILHA *baralho;
    baralho = pilha_criar();
    baralho = ler_baralho(baralho);
    resultado = contagem(baralho);
    if(resultado == 21){
        printf("Ganhou ;)");
    }else{
        printf("Perdeu :(\n");
        printf("Soma :: %d", resultado);
    }
    libera_memoria(baralho);
    return 0;
}