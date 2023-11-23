#include <stdio.h>
#include <stdlib.h>
#include "caminho.h"
#include "ponto.h"

int main() {
    CAMINHO *caminho = ler_caminho();
    printf("%.2f\n", distancia_caminho(caminho));
    free_caminho(caminho);
    return 0;
}