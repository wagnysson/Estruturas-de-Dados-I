#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int *vetor, int tamanho, char elementoProcurado) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == elementoProcurado) {
            return i;
        }
    }

    return -1;
}
