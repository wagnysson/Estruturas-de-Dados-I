#ifndef _JOGO_H_
#define _JOGO_H_

typedef struct jogo_ JOGO;

char *readLine();
JOGO *ler_jogo();
char *get_nome(JOGO *jogo);
char *get_empresa(JOGO *jogo);
int get_ano(JOGO *jogo);
JOGO *nada_encontrado();
void liberar_jogo(JOGO *jogo);
void liberar_nome(JOGO *jogo);
void liberar_struct_jogo(JOGO *jogo);

#endif