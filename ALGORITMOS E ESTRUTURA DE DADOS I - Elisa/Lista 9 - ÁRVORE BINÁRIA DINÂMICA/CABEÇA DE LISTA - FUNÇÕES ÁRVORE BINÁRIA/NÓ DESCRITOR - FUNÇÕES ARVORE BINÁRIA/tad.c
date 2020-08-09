#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

/****************************************************************************/
ArvoreBin* criar_arvore_binaria()
{
  ArvoreBin *raiz = (ArvoreBin*) malloc(sizeof(ArvoreBin));
  if(raiz != NULL)
    raiz->arv = NULL;

  return raiz;
}

/****************************************************************************/
void liberar_no(No *no)
{
  if(no == NULL) return;

  liberar_no(no->esq);
  liberar_no(no->dir);
  free(no);
  no = NULL;
}

/****************************************************************************/
int liberar_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL) return 0;

  liberar_no(raiz->arv);
  free(raiz);

  return 1;
}

/****************************************************************************/
int quantidade_nos_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL || raiz->arv == NULL) return 0;

  int total_esq = quantidade_nos_arvore_binaria(&(raiz->arv->esq));

  int total_dir = quantidade_nos_arvore_binaria(&(raiz->arv->dir));

  return (total_esq + total_dir + 1);
}

/****************************************************************************/
int altura_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL || raiz->arv == NULL) return 0;

  int alt_esq = altura_arvore_binaria(&(raiz->arv->esq));

  int alt_dir = altura_arvore_binaria(&(raiz->arv->dir));

  if(alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

/****************************************************************************/
int esta_vazia_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL || raiz->arv == NULL) return 1;

  return 0;
}

/****************************************************************************/
int inserir_arvore_binaria(ArvoreBin *raiz, int valor)
{
  if(raiz == NULL) return 0;

  No *novo = (No*) malloc(sizeof(No));

  if(novo == NULL) return 0;

  novo->valor = valor;
  novo->esq = NULL;
  novo->dir = NULL;

  if(raiz->arv == NULL)
    raiz->arv = novo;

  else{
    No *atual = raiz->arv;
    No *ant = NULL;

    while(atual != NULL){
      ant = atual;
      if(valor == atual->valor){
        free(novo);
        return 0;
      }
      if(valor < atual->valor)
        atual = atual->esq;
      else
        atual = atual->dir;

    }

    if(valor < ant->valor)
      ant->esq = novo;
    else
      ant->dir = novo;
  }

  return 1;
}

/****************************************************************************/
int remover_no(No *atual)
{
  No *no1, *no2;
  if(atual->esq == NULL){
    no2 = atual->dir;
    free(atual);
     return no2;
  }

  no1 = atual;
  no2 = atual->esq;
  while(no2->dir != NULL){
    no1 = no2;
    no2 = no2->dir;
  }

  if(no1 != atual){
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }
  no2->dir = atual->dir;
  free(atual);
  return no2;
}

/****************************************************************************/
int remover_arvore_binaria(ArvoreBin *raiz, int valor)
{
  if(raiz == NULL) return 0;

  No *ant = NULL;
  No *atual = raiz->arv;

  while(atual != NULL){
    if(valor == atual->valor){
      if(atual == raiz->arv)
        raiz->arv = remover_no(atual);
      else{
        if(ant->dir == atual)
          ant->dir = remover_no(atual);
        else
          ant->esq = remover_no(atual);
      }
      return 1;
    }

    ant = atual;

    if(valor > atual->valor)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return 0;
}

/****************************************************************************/
int consultar_arvore_binaria(ArvoreBin *raiz, int valor)
{
  if(raiz == NULL) return 0;

  No *atual = raiz->arv;

  while(atual != NULL){
    if(valor == atual->valor)
        return 1;
    if(valor < atual->valor)
      atual = atual->esq;
    else
      atual = atual->dir;
  }
  return 0;
}

/****************************************************************************/
void percorrer_em_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL) return;

  if(raiz->arv != NULL){
    percorrer_em_ordem_arvore_binaria(&(raiz->arv->esq));
    printf("%d\n", raiz->arv->valor);
    percorrer_em_ordem_arvore_binaria(&(raiz->arv->dir));
  }
}

/****************************************************************************/
void percorrer_pre_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL) return;

  if(raiz->arv != NULL){
    printf("%d\n", raiz->arv->valor);
    percorrer_pre_ordem_arvore_binaria(&(raiz->arv->esq));
    percorrer_pre_ordem_arvore_binaria(&(raiz->arv->dir));
  }
}

/****************************************************************************/
void percorrer_pos_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL) return;

  if(raiz->arv != NULL){
    percorrer_pos_ordem_arvore_binaria(&(raiz->arv->esq));
    percorrer_pos_ordem_arvore_binaria(&(raiz->arv->dir));
    printf("%d\n", raiz->arv->valor);
  }
}
