#include <stdio.h>
#include <stdlib.h>

int busca_binaria_rec (int elem_buscado, int vetor[], int e, int d)
{
   int meio = (e + d)/2;
   if (vetor[meio] == elem_buscado)
      return meio;
   if (e >= d)
      return -1; // não encontrado
   else
      if (vetor[meio] < elem_buscado)
         return busca_binaria_rec(elem_buscado, vetor, meio+1, d);
      else
         return busca_binaria_rec(elem_buscado, vetor, e, meio-1);
}

int main() {
    int vetor[5];
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 5;
    printf("%d", busca_binaria_rec(4, vetor, 0, 4));

    return 0;
}