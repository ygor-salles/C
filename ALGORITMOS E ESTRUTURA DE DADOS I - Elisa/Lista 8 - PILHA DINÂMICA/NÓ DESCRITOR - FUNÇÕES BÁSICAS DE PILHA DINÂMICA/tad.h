#ifndef _TAD_H
#define _TAD_H

struct Aluno
{
    int matricula;
    char nome[30];
    float n1;
};
struct Elemento
{
    struct Aluno dados;
    struct Elemento *prox;
};
struct Pilha
{
    struct Elemento *topo;
};
typedef struct Aluno Aluno;
typedef struct Elemento Elemento;
typedef struct Pilha Pilha;

Pilha* criar_Pilha();

int empilhar(Pilha* pi, Aluno dados_aluno);

int desempilhar(Pilha* pi);

int tamanho_Pilha(Pilha* pi);

int Pilha_vazia(Pilha* pi);

int consulta_topo_Pilha(Pilha* pi, Aluno *dados_aluno);

int imprimir_Pilha(Pilha* pi);

int esvazia_Pilha(Pilha* pi);

int Pilha_cheia(Pilha* pi);

#endif
