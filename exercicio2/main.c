#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "catalogo.h"

int main() {
    CATALOGO *C = criar_catalogo();
    consultar_catalogo(C);
    liberar_catalogo(C);
    return 0;
}