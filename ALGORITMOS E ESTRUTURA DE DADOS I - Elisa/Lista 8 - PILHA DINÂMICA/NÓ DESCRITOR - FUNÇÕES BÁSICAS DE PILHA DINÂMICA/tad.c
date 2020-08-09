#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

/****************************************************************************/
Pilha* criar_Pilha()
{
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
  if (pi != NULL)
    pi->topo = NULL;
  return pi;
}

/****************************************************************************/
int empilhar(Pilha *pi, Aluno dados_aluno)
{
  Elemento* no = (Elemento*) malloc(sizeof(Elemento));
  if (no == NULL) return 0;

  no->dados = dados_aluno;
  no->prox = pi->topo;
  pi->topo = no;

  return 1;
}

/****************************************************************************/
int desempilhar(Pilha* pi)
{
    if (pi == NULL) return 0;
    if (pi->topo == NULL)  printf("Pilha vazia!");

    else{
        Elemento *no = pi->topo;
        pi->topo = pi->topo->prox;
        free(no);
    }
    return 1;
}

/****************************************************************************/
int tamanho_Pilha(Pilha *pi)
{
  int cont=0;
  if (pi == NULL) return 0;
  if (pi->topo == NULL) printf("Pilha vazia!");

  else{
    Elemento* no = pi->topo;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
  }
  return cont;
}

/****************************************************************************/
int Pilha_vazia(Pilha *pi)
{
  if (pi == NULL) return 1;
  if (pi->topo == NULL) return 1;
  return 0;
}

/****************************************************************************/
int consulta_topo_Pilha (Pilha* pi, Aluno *dados_aluno)
{
    if (pi == NULL) return 0;

    if (pi->topo == NULL) {
        printf("Pilha vazia!");
        return 0;
    }
    else
        *dados_aluno = pi->topo->dados;

    return 1;
}

/****************************************************************************/
int imprimir_Pilha(Pilha* pi)
{
    if (pi == NULL) return 0;
    if (pi->topo == NULL) printf("Pilha vazia!");

    else{
        Elemento *no = pi->topo;
        do {
            printf (" \n%s",no->dados.nome);
            printf (" \n%d",no->dados.matricula);
            printf (" \n%.2f\n",no->dados.n1);
            no = no->prox;
        } while(no != NULL);
    }
    return 1;
}

/****************************************************************************/
int esvazia_Pilha(Pilha* pi)
{
  if (pi == NULL) return 0;
  if (pi->topo == NULL) printf("Pilha vazia!");

  else{
    Elemento *no;
    while (pi->topo != NULL){
      no = pi->topo;
      pi->topo = pi->topo->prox;
      free(no);
    }
    free(pi);
    printf("Pilha Esvaziada!");
  }
  return 1;
}

/****************************************************************************/
int Pilha_cheia(Pilha *pi)
{
  return 0;
}

