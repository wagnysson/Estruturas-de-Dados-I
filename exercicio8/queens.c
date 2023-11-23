#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles) {
    
    int queenAttack = 0;
    int i;
    if(k == 0){
        int auxc, auxr;
        queenAttack = 2*(n-1); //linha e coluna
        //dp embaixo
        auxc = c_q+1;
        auxr = r_q-1;
        while (auxc != (n+1) && auxr != 0) {
            queenAttack++;
            auxr--;
            auxc++;
        }
        //dp em cima
        auxc = c_q-1;
        auxr = r_q+1;
        while (auxc != 0 && auxr != (n+1)) {
            queenAttack++;
            auxr++;
            auxc--;
        }
        //ds embaixo
        auxc = c_q-1;
        auxr = r_q-1;
        while (auxc != 0 && auxr != 0) {
            queenAttack++;
            auxr--;
            auxc--;
        }
        //ds em cima
        auxc = c_q+1;
        auxr = r_q+1;
        while (auxc != (n+1) && auxr != (n+1)) {
            queenAttack++;
            auxr++;
            auxc++;
        }
        return queenAttack;
    }
    //checando a linha da rainha
    //indices menores que o da rainha
    
    int auxc = c_q-1;
    int auxr = r_q;
    while (auxc > 0) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        // printf("i = %d\n", i);
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxc = 0;
        }else {
            auxc--;
        }
    }
    printf("queeattack1: %d\n", queenAttack);

    // printf("queenAttac na passada de antes: %d\n", queenAttack);
    //indices maiores que o da rainha
    auxc = c_q+1;
    
    while (auxc <= n) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxc = n+1;
        }else {
            auxc++;
        }
    }
    // printf("queenAttac na passada de depois: %d", queenAttack);
    printf("queeattack2: %d\n", queenAttack);
    
    
    //checando a coluna da rainha
    //indices menores
    auxc = c_q;
    auxr = r_q-1;
    // printf("coluna r: %d, linha r: %d", auxc, auxr);
    while (auxr > 0) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxr = 0;
        }else {
            auxr--;
        }
    }
    // printf("queenAttac na passada de antes: %d\n", queenAttack);
    printf("queeattack3: %d\n", queenAttack);
    
    //indices maiores
    auxr = r_q+1;
    
    while (auxr <= n) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        // printf("i = %d\n", i);
        
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxr = n+1;
        }else {
            auxr++;
        }
    }
    // printf("queenAttac na passada de depois: %d", queenAttack);
    printf("queeattack4: %d\n", queenAttack);
    
    //diagonal principal
    //embaixo
    auxc = c_q+1;
    auxr = r_q-1;
    while (auxc != (n+1) && auxr != 0) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxc = n+1;
        }else {
            auxr--;
            auxc++;
        }
    }
    printf("queeattack5: %d\n", queenAttack);

    //em cima
    auxc = c_q-1;
    auxr = r_q+1;
    while (auxc != 0 && auxr != (n+1)) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        // printf("i = %d\n", i);
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxc = 0;
        }else {
            auxr++;
            auxc--;
        }
    }
    printf("queeattack6: %d\n", queenAttack);
    
    //diagonal secundaria
    //embaixo
    auxc = c_q-1;
    auxr = r_q-1;
    while (auxc != 0 && auxr != 0) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxc = 0;
        }else {
            auxr--;
            auxc--;
        }
    }
    printf("queeattack7: %d\n", queenAttack);

    //em cima
    auxc = c_q+1;
    auxr = r_q+1;
    while (auxc != (n+1) && auxr != (n+1)) {
        for (i = 0; i<k; i++) {
            if(auxr == obstacles[i][0] && auxc == obstacles[i][1]){
                i = k;
            }
        }
        // printf("i = %d\n", i);
        if (i == k) {
            queenAttack++;
        }
        if(i == k+1){
            auxc = n+1;
        }else {
            auxr++;
            auxc++;
        }
    }
    printf("queeattack8: %d\n", queenAttack);
    
    return queenAttack;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    printf("ponteiro: %p", fptr);
    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** second_multiple_input = split_string(rtrim(readline()));

    int r_q = parse_int(*(second_multiple_input + 0));

    int c_q = parse_int(*(second_multiple_input + 1));

    int** obstacles = malloc(k * sizeof(int*));

    for (int i = 0; i < k; i++) {
        *(obstacles + i) = malloc(2 * (sizeof(int)));

        char** obstacles_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++) {
            int obstacles_item = parse_int(*(obstacles_item_temp + j));

            *(*(obstacles + i) + j) = obstacles_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, k, 2, obstacles);

    printf("%d\n", result);
    // fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
