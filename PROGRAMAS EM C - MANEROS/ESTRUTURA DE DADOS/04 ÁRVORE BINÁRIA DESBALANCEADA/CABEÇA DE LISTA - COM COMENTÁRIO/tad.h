// TAD para Árvore Dinâmica Encadeada

#ifndef _ARVORE_BIN_DE
#define _ARVORE_BIN_DE

// definição de tipos abstratos
typedef struct no No;
typedef No* Pno;

// funções para alocar e desalocar memória
Pno* criar_arvore_binaria();
int liberar_arvore_binaria(Pno *raiz);

// funções para obter informações da arvore binaria
int quantidade_nos_arvore_binaria(Pno *raiz);
int altura_arvore_binaria(Pno *raiz);
int esta_vazia_arvore_binaria(Pno *raiz);

// função para inserção de elementos da arvore binaria
int inserir_arvore_binaria(Pno *raiz, int chave);

// função para remoção de elementos da arvore binaria
int remover_arvore_binaria(Pno *raiz, int chave);

// função para buscar elementos na arvore binaria
int consultar_arvore_binaria(Pno *raiz, int chave);

// funções para percorrer a arvore binaria
void percorrer_em_ordem_arvore_binaria(Pno *raiz);
void percorrer_pre_ordem_arvore_binaria(Pno *raiz);
void percorrer_pos_ordem_arvore_binaria(Pno *raiz);

#endif
