#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carta.h"
#include "Pilha.h"

struct carta_{
    char *nipe;
    char *simbolo;
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
    } while((currentInput != '\n') && (currentInput != EOF) && (currentInput != ' '));
    string[index - 1] = '\0';

    return string;
}

CARTA *set_carta(CARTA *carta){
    carta = (CARTA *) malloc(sizeof(CARTA));
    carta->nipe = readLine();
    carta->simbolo = readLine();

    return carta;
}

char *get_nipe(CARTA *carta){
    return carta->nipe;
}

char *get_simbolo(CARTA *carta){
    return carta->simbolo;
}

void carta_apagar(CARTA *carta){
    free(carta->nipe);
    carta->nipe = NULL;
    free(carta->simbolo);
    carta->simbolo = NULL;
    free(carta);
    carta = NULL;
}