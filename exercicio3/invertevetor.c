#include <stdio.h>
#include <stdlib.h>

int *inverte_vetor(int *vetor, int tamanho){
    int i, temp, final;
    
    final = tamanho-1;

    for (i = 0; i < tamanho/2; i++){
        temp = vetor[i];
        vetor[i] = vetor[final-i];
        vetor[final-i] = temp;
    }
    return vetor;
}

int main() {
    int vetor[5], i;
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 5;
    inverte_vetor(vetor, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d", vetor[i]);
    }

    return 0;
}