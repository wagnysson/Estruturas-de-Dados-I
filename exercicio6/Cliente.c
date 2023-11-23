#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Util.h"

struct cliente_{
    char *nome;
    char *cpf;
    int idade;
    float saldo_atual;
    long int chave;
};

CLIENTE *ler_cliente(){
    CLIENTE *cliente = (CLIENTE*) malloc(sizeof(CLIENTE));
    int i, j = 0, tamanho_str;

    //ler dados do registro de clientes
    getchar();
    cliente->cpf = readLine();
    cliente->nome = readLine();
    scanf(" %d", &cliente->idade);
    getchar();
    scanf(" %f", &cliente->saldo_atual);


    //lendo a chave (convertendo a string cpf pra int)
    char *temp = (char*) calloc(12, sizeof(char)); //cpf tem 11 digitos
    tamanho_str = strlen(cliente->cpf);
    for (i = 0; i < tamanho_str; i++){
        if(cliente->cpf[i] != '.' && cliente->cpf[i] != '-'){
            temp[j] = cliente->cpf[i]; 
            j++;
        }
    }
    cliente->chave = atol(temp);
    free(temp);
    return cliente;
}
char *get_nome(CLIENTE *cliente){
    return cliente->nome;
}
char *get_cpf(CLIENTE *cliente){
    return cliente->cpf;
}
int get_idade(CLIENTE *cliente){
    return cliente->idade;
}
float get_saldo(CLIENTE *cliente){
    return cliente->saldo_atual;
}
long int get_chave(CLIENTE *cliente){
    return cliente->chave;
}
void apagar_cliente(CLIENTE *cliente){
    free(cliente->nome);
    free(cliente->cpf);
    free(cliente);
}
long int cpf_to_int(char *cpf){
    int i, j = 0, tamanho_str;
    long int result;
    char *temp = (char*) calloc(12, sizeof(char));
    tamanho_str = strlen(cpf);
    for (i = 0; i < tamanho_str; i++){
        if(cpf[i] != '.' && cpf[i] != '-'){
            temp[j] = cpf[i];
            j++;
        }
    }
    
    result = atoll(temp);
    free(temp);
    return result;
}

void imprimir_chave(CLIENTE *cliente){
    printf("%ld\n", cliente->chave);
}

void printar_cliente(CLIENTE *cliente){
    printf("Conta :: %s\n", cliente->nome);
    printf("CPF :: %s\n", cliente->cpf);
    printf("Idade :: %d\n", cliente->idade);
    printf("Saldo atual :: R$ %.2f\n", cliente->saldo_atual);
}