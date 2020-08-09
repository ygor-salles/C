#ifndef TUBOS_FILA_H
#define TUBOS_FILA_H

typedef struct descritor Pilha;

Pilha* criar_pilha();

void libera_pilha(Pilha *pi);

int empilhar(Pilha *pi, char vogal);

char desempilhar(Pilha *pi);

void consulta_pilha(Pilha *pi, Pilha *pi2, Pilha *pi3);

int tamanhoPilha(Pilha *pi);

char pegaVogal(Pilha *pi);

int verificaCerto(Pilha *pi);

#endif
