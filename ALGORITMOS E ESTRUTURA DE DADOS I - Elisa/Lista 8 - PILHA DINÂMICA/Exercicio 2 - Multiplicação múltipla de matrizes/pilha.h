// TAD para Lista Dinâmica Encadeada Circular

#ifndef _PILHA_DEC
#define _PILHA_DEC

struct elemento{
	int *m;
	struct elemento *prox;
};

struct pilha{
    struct elemento *topo; /*aponta para o elemento do topo da fila*/
    int tamanho;
};

// definição de tipos abstratos
typedef struct elemento Elemento;
typedef struct pilha Pilha;

Pilha *criar_pilha();

int liberar_pilha(Pilha *li);

int empilhar(Pilha *pi, int *m);

int* desempilhar(Pilha *pi);
int desempilhar2(Pilha *pi);

int imprimir(Pilha *t1);

#endif
