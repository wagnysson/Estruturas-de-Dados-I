#ifndef _CLIENTE_H_
#define _CLIENTE_H_


typedef struct cliente_ CLIENTE;

CLIENTE *ler_cliente();
long int cpf_to_int(char *cpf);
char *get_nome(CLIENTE *cliente);
char *get_cpf(CLIENTE *cliente);
int get_idade(CLIENTE *cliente);
float get_saldo(CLIENTE *cliente);
long int get_chave(CLIENTE *cliente);
void apagar_cliente(CLIENTE *cliente);
void imprimir_chave(CLIENTE *cliente);
void printar_cliente(CLIENTE *cliente);
#endif