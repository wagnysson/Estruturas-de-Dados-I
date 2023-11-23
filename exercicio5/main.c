#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"
#include "BigNumber.h"
#include "Util.h"


int main() {
    int n, i, resultado;
    char *operacao;
    BIGNUMBER *BigNumber1, *BigNumber2, *res_soma;

    scanf("%d ", &n);

    for (i = 0; i < n; i++){
        operacao = readLine();
        BigNumber1 = ler_bignumber();
        BigNumber2 = ler_bignumber();

        if (strcmp(operacao, "soma") == 0){
            res_soma = soma(BigNumber1, BigNumber2);
            printar_soma(res_soma);
        }else{
            resultado = realizar_operacao(operacao, BigNumber1, BigNumber2);
            printar_resultado(operacao, resultado);
        }
        liberar_memoria(operacao, BigNumber1, BigNumber2, res_soma);
    }


    return 0;
}