#ifndef _TAD_H
#define _TAD_H

struct Transacao
{
   char nome[50], tipo[30];
   int cod;
};
struct Elemento
{
    struct Transacao dados;
    struct Elemento *prox;
};
struct Lista
{
    struct Elemento *inicio;
    struct Elemento *fim;
};

typedef struct Transacao Transacao;
typedef struct Elemento Elemento;
typedef struct Lista Lista;

Lista* criar_lista();

int inserir_lista_fim(Lista *li, Transacao dados);

int imprimir_lista(Lista *li);

int remover_elemento_dado(Lista *li, int codigo);

int tamanho_lista(Lista *li);

int esvaziar_lista(Lista *li);

#endif // _TAD_H
