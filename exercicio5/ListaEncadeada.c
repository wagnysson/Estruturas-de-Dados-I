#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaEncadeada.h"

void swap(char *x, char *y);
char* reverse(char *buffer, int i, int j);
char* itoa(int value, char* buffer, int base);

struct node_st{
    int item;
    NODE* proximo;
};

struct lista{
    NODE* inicio;
    NODE* fim;
    int tamanho;
};

void swap(char *x, char *y){
    char t = *x; *x = *y; *y = t;
}
 
// Função para reverter `buffer[i…j]`
char* reverse(char *buffer, int i, int j){
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}
 
// Função iterativa para implementar a função `itoa()` em C
char* itoa(int value, char* buffer, int base){
    // entrada inválida
    if (base < 2 || base > 32) {
        return buffer;
    }
 
    // considera o valor absoluto do número
    int n = abs(value);
 
    int i = 0;
    while (n) {
        int r = n % base;
 
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }
 
        n = n / base;
    }
 
    // se o número for 0
    if (i == 0) {
        buffer[i++] = '0';
    }
 
    // Se a base for 10 e o valor for negativo, a string resultante
    // é precedido por um sinal de menos (-)
    // Com qualquer outra base, o valor é sempre considerado sem sinal
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }
 
    buffer[i] = '\0'; // string de terminação nula
 
    // inverte a string e retorna
    return reverse(buffer, 0, i - 1);
}

LISTA *lista_criar()
{
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
    if(lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

boolean lista_vazia(const LISTA *lista)
{
    if(lista != NULL)
    {
        return lista->inicio == NULL;
    }
    return ERRO;
}

int lista_tamanho(const LISTA *lista) {
    if(lista != NULL)
    {
        return lista->tamanho;
    }
    return ERRO;
}

int lista_inserir(LISTA *lista, int item)
{
    if(lista != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->proximo = NULL;
            if(lista_vazia(lista))
            {
                lista->inicio = novoNode;
            }
            else
            {
                lista->fim->proximo = novoNode;
            }
            lista->fim = novoNode;
            lista->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

NODE *get_inicio(LISTA *lista){
    return lista->inicio;
}

NODE *get_fim(LISTA *lista){
    return lista->fim;
}

int get_item(NODE *no){
    return no->item;
}

NODE *set_item(NODE *no, int item){
    no->item = item;
    return no;
}
NODE *get_proximo(NODE *no){
    return no->proximo;
}

void apagar_lista(LISTA *lista){
    int i, counter;
    NODE *nodeAtual;

    counter = lista->tamanho;
        while (counter > 0){
            nodeAtual = lista->inicio;
            counter--;
            for (i = 0; i < counter; i++){
                nodeAtual = nodeAtual->proximo;
                // printf("passou 1 vez\n");
            }
            free(nodeAtual);
        }
        
    free(lista);
}