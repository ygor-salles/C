#ifndef _TAD_H
#define _TAD_H

struct Elemento
{
  int num;
  struct Elemento *prox;
};
struct Lista
{
    struct Elemento *ponteiro;
};

typedef struct Elemento Elemento;
typedef struct Lista Lista;

Lista* criar_lista();

int inserir_lista_inicio(Lista *li, int num);

int inserir_lista_fim(Lista *li, int num);

int inserir_lista_ordenada(Lista *li, int num);

int imprimir_lista(Lista *li);

int remover_elemento_inicio(Lista *li);

int remover_elemento_fim(Lista *li);

int remover_elemento_dado(Lista *li, int num);

int buscar_lista_posicao(Lista *li, int pos);

int buscar_lista_dado(Lista *li, int num);

int tamanho_lista(Lista *li);

int lista_vazia(Lista *li);

int esvaziar_lista(Lista *li);

#endif
