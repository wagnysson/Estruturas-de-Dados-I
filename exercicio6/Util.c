#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

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
    } while((currentInput != '\n') && (currentInput != EOF) && (currentInput != ';'));
    string[index - 1] = '\0';

    return string;
}


