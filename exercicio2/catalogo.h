#ifndef _CATALOGO_H_
#define _CATALOGO_H_


typedef struct catalogo_ CATALOGO;


CATALOGO *criar_catalogo();
void consultar_catalogo();
void liberar_catalogo(CATALOGO *catalogo);

#endif