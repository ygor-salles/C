#ifndef TAD_H
#define TAD_H

typedef struct No No;

typedef struct Lista Lista;

Lista* cria_lista ();

void insere_produto (Lista *li);

void aplica_taxa (Lista *li, float taxa);

void imprime_relatorio (Lista *li);

void esvaziar_lixeira (Lista *li);

#endif
