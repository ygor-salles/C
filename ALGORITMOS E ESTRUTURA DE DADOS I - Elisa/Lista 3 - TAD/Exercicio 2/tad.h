#ifndef TAD_H
#define TAD_H

typedef struct produto Produto;

Produto *aloca_atribui(int n);

float maior_preco(int n, Produto *dados);

void aumenta_preco(int n, Produto *dados);

int maior_quantidade(int n, Produto *dados);

void imprimir_produto(int n, Produto *dados);

void imprimir_vetor (int n, Produto *dados);

#endif
