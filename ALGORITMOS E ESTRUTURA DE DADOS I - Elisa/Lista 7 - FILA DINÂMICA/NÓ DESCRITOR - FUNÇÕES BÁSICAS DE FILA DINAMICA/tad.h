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
struct Fila
{
    struct Elemento *inicio;
    struct Elemento *fim;
};

typedef struct Aluno Aluno;
typedef struct Elemento Elemento;
typedef struct Fila Fila;

Fila* criar_fila();

int esvazia_fila(Fila* fi);

int tamanho_fila(Fila* fi);

int fila_cheia(Fila* fi);

int fila_vazia(Fila* fi);

int enfileirar(Fila* fi, Aluno dados_aluno);

int desenfileirar(Fila* fi);

int consulta_fila(Fila* fi, Aluno *dados_aluno);

int imprimir_fila(Fila* fi);

#endif
