#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha.h"
#include "carta.h"
#include "Util.h"

#define ERRO -1

struct node_st{
    CARTA *carta;
    NODE *anterior;
};

struct pilha_{
    NODE *topo;
    int tamanho;
};

void pilha_remove_tudo(PILHA **pilha);

void pilha_remove_topo(PILHA **pilha);

PILHA *pilha_criar(){
    PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));
    if(pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

boolean pilha_vazia(const PILHA *pilha){
    if(pilha != NULL)
    {
        return pilha->tamanho == 0;
    }
    return ERRO_PILHA;
}

boolean pilha_cheia(const PILHA *pilha){
    if(pilha != NULL)
    {
        return FALSE;
    }
    return ERRO_PILHA;
}

int pilha_tamanho(const PILHA *pilha){
    if(pilha != NULL)
    {
        return pilha->tamanho;
    }
    return ERRO_PILHA;
}

int pilha_empilhar(PILHA *pilha, CARTA *carta){
    if (pilha!=NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if(novoNode != NULL)
        {
            novoNode->carta = carta;
            novoNode->anterior = pilha->topo;
            pilha->topo = novoNode;
            pilha->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

CARTA *pilha_topo(const PILHA *pilha){
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        return pilha->topo->carta;
    }
    return NULL;
}

CARTA *pilha_desempilhar(PILHA *pilha){
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        NODE *desempilhado = pilha->topo;
        CARTA *carta = pilha->topo->carta;
        pilha->topo = pilha->topo->anterior;
        desempilhado->anterior = NULL;
        free(desempilhado);
        desempilhado = NULL;
        pilha->tamanho--;
        return carta;
    }
    return NULL;
}

boolean pilha_apagar(PILHA **pilha){
    if ((*pilha != NULL) && (!pilha_vazia(*pilha)))
    {
        pilha_remove_tudo(pilha);
        free(*pilha);
        *pilha = NULL;
        return TRUE;
    }
    return FALSE;
}

void pilha_remove_tudo(PILHA **pilha){
    while((*pilha)->topo != NULL)
    {
        pilha_remove_topo(pilha);
    }
}

void pilha_remove_topo(PILHA **pilha){
    NODE *temporaryNode;

    temporaryNode = (*pilha)->topo;
    (*pilha)->topo = (*pilha)->topo->anterior;
    carta_apagar(temporaryNode->carta);
    temporaryNode->anterior = NULL;
    free(temporaryNode);
    temporaryNode = NULL;
}

PILHA *ler_baralho(PILHA *pilha){
    int i;
    CARTA *carta;

    for (i = 0; i < 52 ; i++)
    {
        carta = set_carta(carta);
        pilha_empilhar(pilha, carta);
    }
    return pilha;
}

int contagem(PILHA *pilha){
    int soma = 0;
    CARTA *carta;

    while(soma<21){
        carta = pilha_topo(pilha);
        if((strcmp(get_simbolo(carta), "V") == 0)||(strcmp(get_simbolo(carta), "R") == 0)||(strcmp(get_simbolo(carta), "D") == 0)){
            soma += 10;
        }else{
            soma += atoi(get_simbolo(carta));
        }
        carta_apagar(pilha_desempilhar(pilha));
    }
    return soma;
}

void libera_memoria(PILHA *baralho){
    pilha_remove_tudo(&baralho);
    pilha_apagar(&baralho);
};