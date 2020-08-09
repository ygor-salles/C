#ifndef _ARVORE_BIN_DE
#define _ARVORE_BIN_DE

typedef struct no No;
typedef No* Pno;

Pno* criar_arvore_binaria();
void liberar_no(No *no);
int liberar_arvore_binaria(Pno *raiz);

int quantidade_nos_arvore_binaria(Pno *raiz);
int altura_arvore_binaria(Pno *raiz);
int esta_vazia_arvore_binaria(Pno *raiz);

int inserir_arvore_binaria(Pno *raiz, int chave);

No* remover_no(No *atual);
int remover_arvore_binaria(Pno *raiz, int chave);

int consultar_arvore_binaria(Pno *raiz, int chave);

void percorrer_em_ordem_arvore_binaria(Pno *raiz);
void percorrer_pre_ordem_arvore_binaria(Pno *raiz);
void percorrer_pos_ordem_arvore_binaria(Pno *raiz);

#endif
