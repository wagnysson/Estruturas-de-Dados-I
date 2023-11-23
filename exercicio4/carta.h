#ifndef _CARTA_H_
#define _CARTA_H_

typedef struct carta_ CARTA;

char *readLine();
CARTA *set_carta(CARTA *carta);
char *get_nipe(CARTA *carta);
char *get_simbolo(CARTA *carta);
void carta_apagar(CARTA *carta);

#endif