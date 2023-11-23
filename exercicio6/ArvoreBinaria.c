#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArvoreBinaria.h"
#include "Util.h"

#define COUNT 8

struct node_st
{
    CLIENTE *item;
    NODE *direita;
    NODE *esquerda;
};

struct arvore_binaria
{
    NODE* raiz;
    int profundidade;
};

static void pre_ordem_recursao(NODE *raiz);
static void em_ordem_recursao(NODE *raiz);
static void pos_ordem_recursao(NODE *raiz);
static NODE* cria_no(CLIENTE* item);
static void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant);
static boolean ehMaior(const NODE *raiz, CLIENTE *item);
static boolean ehMenor(const NODE *raiz, CLIENTE *item);
static boolean abb_remover_aux (NODE **raiz, long int chave);

CLIENTE *remover_cliente(ARVORE_BINARIA *arvore);
CLIENTE *buscar_cliente(ARVORE_BINARIA *arvore);

int findCount(long int n)
{
    int count = 0;
  
    // Remove last digit from number
    // till number is 0
    while (n != 0) {
  
  //Increment count
        count++;
        n /= 10;
    }
  
    // return the count of digit
    return count;
}

ARVORE_BINARIA *arvore_binaria_criar()
{
    ARVORE_BINARIA *arvore;
    arvore = (ARVORE_BINARIA *) malloc(sizeof(ARVORE_BINARIA));
    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

static NODE* cria_no(CLIENTE *item)
{
    NODE *novoNode = (NODE *) malloc(sizeof(NODE));
    if (novoNode != NULL) {
        novoNode->item = item;
        novoNode->direita = NULL;
        novoNode->esquerda = NULL;
    }
    return novoNode;
}

static void pre_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        if(findCount(get_chave(raiz->item))<11){
            for (int i = 0; i < (11-findCount(get_chave(raiz->item))); i++)
            {
                printf("0");
            }
            imprimir_chave(raiz->item);
        }else{
            imprimir_chave(raiz->item);
        }
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
    }
}

static void em_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        em_ordem_recursao(raiz->esquerda);
        imprimir_chave(raiz->item);
        em_ordem_recursao(raiz->direita);
    }
}

static void pos_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pos_ordem_recursao(raiz->esquerda);
        pos_ordem_recursao(raiz->direita);
        imprimir_chave(raiz->item);
    }
}

void arvore_binaria_pre_ordem(ARVORE_BINARIA *arvoreBinaria)
{
    pre_ordem_recursao(arvoreBinaria->raiz);
}

void arvore_binaria_em_ordem(ARVORE_BINARIA *arvoreBinaria)
{
    em_ordem_recursao(arvoreBinaria->raiz);
}

void arvore_binaria_pos_ordem(ARVORE_BINARIA *arvoreBinaria)
{
    pos_ordem_recursao(arvoreBinaria->raiz);
}


NODE *ab_inserir_no(NODE *raiz, CLIENTE *item,
                    int lado, int chave) {
    if (raiz != NULL) {
        raiz->esquerda = ab_inserir_no(raiz->esquerda, item, lado, chave);
        raiz->direita = ab_inserir_no(raiz->direita, item, lado, chave);
        if (chave == get_chave(raiz->item)){
            if (lado == FILHO_ESQ)
            {
                raiz->esquerda = cria_no(item);
            }
            else if (lado == FILHO_DIR)
            {
                raiz->direita = cria_no(item);
            }
        }
    }
    return raiz;
}

boolean arvore_binaria_inserir(ARVORE_BINARIA *T, CLIENTE *item, int lado, int chave){
    if (T->raiz == NULL)
        return((T->raiz = cria_no(item)) != NULL);
    else
        return((T->raiz = ab_inserir_no(T->raiz, item, lado, chave)) != NULL);
}

int ab_profundidade(NODE *no) {
    if (no == NULL)
        return -1;
    int e = ab_profundidade(no->esquerda);
    int d = ab_profundidade(no->direita);
    return ((e > d) ? e : d) + 1;
}

void apagar_arvore(NODE **raiz) {
    if (*raiz != NULL) {
        apagar_arvore(&(*raiz)->esquerda);
        apagar_arvore(&(*raiz)->direita);
        apagar_cliente((*raiz)->item);
        free(*raiz);
        *raiz = NULL;
    }
}
void ab_apagar_arvore(ARVORE_BINARIA **T) {
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

NODE *abb_inserir_no(NODE *raiz, CLIENTE *item){
    if (raiz == NULL)
        raiz = cria_no(item);
    else if(ehMaior(raiz, item))
        raiz->direita = abb_inserir_no(raiz->direita,item);
    else if(ehMenor(raiz, item))
        raiz->esquerda = abb_inserir_no(raiz->esquerda,item);
    return raiz;
}

boolean ehMenor(const NODE *raiz, CLIENTE *item) {
    return get_chave(item) < get_chave(raiz->item);
}

boolean ehMaior(const NODE *raiz, CLIENTE *item) {
    return get_chave(item) > get_chave(raiz->item);
}

boolean abb_inserir (ARVORE_BINARIA *T, CLIENTE *item){
    return((T->raiz = abb_inserir_no(T->raiz, item)) != NULL);
}

CLIENTE *abb_busca_no(NODE *raiz, long int chave){
    if(raiz == NULL)
        return NULL;
    if(chave == get_chave(raiz->item))
        return (raiz->item);
    if(chave < get_chave(raiz->item))
        return (abb_busca_no(raiz->esquerda, chave));
    else
        return (abb_busca_no(raiz->direita, chave));
}
CLIENTE *abb_busca(ARVORE_BINARIA *T, long int chave){
    return(abb_busca_no(T->raiz, chave));
}


static boolean abb_remover_aux (NODE **raiz, long int chave){
    NODE *noRemovido;
    if(*raiz == NULL)
    {
        return FALSE;
    }
    if(chave == get_chave((*raiz)->item))
    {
        if ((*raiz)->esquerda == NULL|| (*raiz)->direita == NULL)
        {/*Caso 1 se resume ao caso 2: há um filho ou nenhum*/
            noRemovido = *raiz;
            if((*raiz)->esquerda == NULL) {
                *raiz = (*raiz)->direita;
            }
            else {
                *raiz = (*raiz)->esquerda;
            }
            free(noRemovido);
            noRemovido = NULL;
        }
        else /*Caso 3: há ambos os filhos*/
        {
            troca_max_esq((*raiz)->direita, (*raiz), (*raiz));
        }
        return TRUE;
    }
    else
    {
        if(chave < get_chave((*raiz)->item))
            return abb_remover_aux (&(*raiz)->esquerda, chave);
        else
            return abb_remover_aux (&(*raiz)->direita, chave);
    }
}

boolean arvore_binaria_remover(ARVORE_BINARIA *T, long int chave){
    if (T != NULL)
        return abb_remover_aux(&T->raiz, chave);
    return FALSE;
}

static void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant)
{
    if(troca->esquerda != NULL)
    {
        troca_max_esq(troca->esquerda, raiz, troca);
        return;
    }
    if(raiz == ant) {
        ant->direita = troca->direita;
    }
    else {
        ant->esquerda = troca->esquerda;
    }
    raiz->item = troca->item;
    free(troca);
    troca = NULL;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
static void print2DUtil(NODE *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->direita, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%ld\n", get_chave(root->item));

    // Process left child
    print2DUtil(root->esquerda, space);
}

// Wrapper over print2DUtil()
void arvore_binaria_imprimir(ARVORE_BINARIA *root)
{
    // Pass initial space count as 0
    print2DUtil(root->raiz, 0);
}

NODE *get_raiz(ARVORE_BINARIA *T){
    return T->raiz;
}


ARVORE_BINARIA *ler_registros(int n){
    int i;
    CLIENTE *cliente;
    ARVORE_BINARIA *arvore;

    arvore = arvore_binaria_criar();

    for (i = 0; i < n; i++){
        //lendo os clientes
        cliente = ler_cliente();

        //inserindo o cliente na arvore
        abb_inserir(arvore, cliente);
    }
    return arvore;
}

CLIENTE *remover_cliente(ARVORE_BINARIA *arvore){
    long int chave_remover;
    char *cpf_remover;
    CLIENTE *cliente;

    getchar();
    cpf_remover = readLine();
    chave_remover = cpf_to_int(cpf_remover);
    cliente = abb_busca(arvore, chave_remover);  
    arvore_binaria_remover(arvore, chave_remover);
    free(cpf_remover);
    return cliente;
}

CLIENTE *buscar_cliente(ARVORE_BINARIA *arvore){
    CLIENTE *cliente;
    char *cpf_buscado;
    long int chave;

    getchar();
    cpf_buscado = readLine();
    chave = cpf_to_int(cpf_buscado);
    cliente = abb_busca(arvore, chave);
    free(cpf_buscado);
    return cliente;
}

CLIENTE *realizar_operacao(char operacao, ARVORE_BINARIA *arvore){
    CLIENTE *cliente;
    //insercao
    if(operacao == 'I'){
        cliente = ler_cliente();
        abb_inserir(arvore, cliente);
        return NULL;
    }
    //remocao
    if(operacao == 'R'){
        cliente = remover_cliente(arvore);
        return cliente;
    }
    //busca
    if(operacao == 'B'){
        cliente = buscar_cliente(arvore);
        return cliente;
    }
    return NULL;
}

void printar_resultado(char operacao, ARVORE_BINARIA *arvore, CLIENTE *cliente){
    if(operacao == 'I'){
        printf("Preorder\n");
        arvore_binaria_pre_ordem(arvore);
        printf("\n");
        return;
    }

    //remocao
    if(operacao == 'R'){
        if (cliente == NULL){
            printf("Pessoa nao encontrada.");
        }else{
            printar_cliente(cliente);
        }
        printf("Preorder\n");
        arvore_binaria_pre_ordem(arvore);
        printf("\n");
        apagar_cliente(cliente);
        return;
    }

    //busca
    if(operacao == 'B'){
        if (cliente == NULL){
            printf("Pessoa nao encontrada.");
        }else{
            printar_cliente(cliente);
            printf("\n");
        }
        return;
    }
}

void liberar_memoria(ARVORE_BINARIA *arvore){
    ab_apagar_arvore(&arvore);
}