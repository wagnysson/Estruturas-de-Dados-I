#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "catalogo.h"

struct jogo_{
    char *nome;
    char *empresa;
    int ano;
};

JOGO *ler_jogo(char *nome, char *empresa, int ano){
    JOGO *jogo;

    jogo = (JOGO *) malloc(sizeof(JOGO));
    jogo->nome = nome;
    jogo->empresa = empresa;
    jogo->ano = ano;

    return jogo;
};

char *get_nome(JOGO *jogo){
    return jogo->nome;
};

char *get_empresa(JOGO *jogo){
    return jogo->empresa;
}

int get_ano(JOGO *jogo){
    return jogo->ano;
};

JOGO *nada_encontrado(){
    JOGO *nada;
    nada = (JOGO *) malloc(sizeof(JOGO));
    nada->nome = "Nada encontrado";
    nada->empresa = "";
    nada->ano = 0;
    return nada;
}

void liberar_jogo(JOGO *jogo){
    free(jogo->nome);
    free(jogo->empresa);
    free(jogo);
}

void liberar_nome(JOGO *jogo){
    free(jogo->nome);
}