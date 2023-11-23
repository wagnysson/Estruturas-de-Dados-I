#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int elem_buscado, int *vetor, int tamanho){
    int inicio = 0, meio, final;
    
    final = tamanho-1;

    do{
        meio = (inicio+final)/2;
        if (elem_buscado == vetor[meio]){
            return meio;
        }else{
            if(elem_buscado>vetor[meio]){
                inicio = meio+1;
            }else{
                final = meio-1;
            }
        }
        
        
    }while(inicio <= final);

    return -1;
}

int main() {
    int vetor[5];
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 5;
    printf("%d", busca_binaria(5, vetor, 5));

    return 0;
}