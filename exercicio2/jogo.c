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

char *readLine(){
    char *string = NULL;
    char currentInput;
    int index = 0;

    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';

    return string;
}

JOGO *ler_jogo(){
    JOGO *jogo;
   
    jogo = (JOGO *) malloc(sizeof(JOGO));

    jogo->nome = readLine();
    if (strcmp(jogo->nome, "F") == 0){
        jogo->ano = 0;
        jogo->empresa = "";
        return jogo;
    }
    jogo->empresa = readLine();
    char *c_ano = readLine();
    jogo->ano = atoi(c_ano);
    free(c_ano);
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