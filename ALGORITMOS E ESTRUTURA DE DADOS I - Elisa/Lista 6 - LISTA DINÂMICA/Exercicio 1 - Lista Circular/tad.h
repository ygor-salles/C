#ifndef _TAD_H
#define _TAD_H

struct Produto
{
  int codigo;
  char descricao[30];
  float preco;
  int qtd;
};
struct Elemento
{
  struct Produto *produto;
  struct Elemento *prox;
};
struct Lista
{
    struct Elemento *ponteiro;
};

typedef struct Produto Produto;
typedef struct Elemento Elemento;
typedef struct Lista Lista;

int imprimir_produto(Produto *produto);
int criar_produto(Produto **produto);

Lista* criar_lista();
int liberar_lista(Lista *li);

int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

int inserir_lista_inicio(Lista *li, Produto *produto);
int inserir_lista_final(Lista *li, Produto *produto);
int inserir_lista_ordenada(Lista *li, Produto *produto);

int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int codigo);

Produto *buscar_lista_posicao(Lista *li, int pos);
Produto *buscar_lista_dado(Lista *li, int codigo);

int imprimir_lista(Lista *li);


#endif
