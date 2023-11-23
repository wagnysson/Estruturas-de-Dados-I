#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "ArvoreBinaria.h"


int main() {
    int n;
    char operacao;
    CLIENTE *cliente;
    ARVORE_BINARIA *arvore;

    scanf("%d", &n);
    arvore = ler_registros(n);
    scanf(" %c", &operacao);
    cliente = realizar_operacao(operacao, arvore);
    printar_resultado(operacao, arvore, cliente);
    liberar_memoria(arvore);

    return 0;
}