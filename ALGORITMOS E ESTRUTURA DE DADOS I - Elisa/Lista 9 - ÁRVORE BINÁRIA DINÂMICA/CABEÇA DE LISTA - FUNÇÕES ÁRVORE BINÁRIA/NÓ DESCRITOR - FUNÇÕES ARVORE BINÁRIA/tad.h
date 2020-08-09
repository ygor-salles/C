#ifndef _ARVORE_BIN_DE
#define _ARVORE_BIN_DE

struct No
{
  int valor;
  struct No *esq;
  struct No *dir;
};
struct ArvoreBin
{
    struct No *arv;
};

typedef struct No No;
typedef struct ArvoreBin ArvoreBin;

ArvoreBin* criar_arvore_binaria();

int liberar_arvore_binaria(ArvoreBin *raiz);

int quantidade_nos_arvore_binaria(ArvoreBin *raiz);

int altura_arvore_binaria(ArvoreBin *raiz);

int esta_vazia_arvore_binaria(ArvoreBin *raiz);

int inserir_arvore_binaria(ArvoreBin *raiz, int valor);

int remover_arvore_binaria(ArvoreBin *raiz, int valor);

int consultar_arvore_binaria(ArvoreBin *raiz, int valor);

void percorrer_em_ordem_arvore_binaria(ArvoreBin *raiz);

void percorrer_pre_ordem_arvore_binaria(ArvoreBin *raiz);

void percorrer_pos_ordem_arvore_binaria(ArvoreBin *raiz);

#endif
