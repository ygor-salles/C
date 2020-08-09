#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct no{
  int chave;
  struct no *esq;
  struct no *dir;
};

/****************************************************************************/
Pno* criar_arvore_binaria()
{
  Pno* raiz = (Pno*) malloc(sizeof(Pno));
  if(raiz != NULL)
    *raiz = NULL;

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

int liberar_arvore_binaria(Pno *raiz)
{
  if(raiz == NULL) return 0;

  liberar_no(*raiz); //libera cada nó
  free(raiz); //libera raiz

  return 1;
}

/****************************************************************************/
int quantidade_nos_arvore_binaria(Pno *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 0;

  int total_esq = quantidade_nos_arvore_binaria(&((*raiz)->esq));
  int total_dir = quantidade_nos_arvore_binaria(&((*raiz)->dir));

  return (total_esq + total_dir + 1);
}

/****************************************************************************/
int altura_arvore_binaria(Pno *raiz)
{
  if(raiz == NULL) return 0;
  if(*raiz == NULL) return 0;

  int alt_esq = altura_arvore_binaria(&((*raiz)->esq));
  int alt_dir = altura_arvore_binaria(&((*raiz)->dir));

  if(alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

/****************************************************************************/
int esta_vazia_arvore_binaria(Pno *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 1;

  return 0;
}

/****************************************************************************/
int inserir_arvore_binaria(Pno *raiz, int chave)
{
  if(raiz == NULL) return 0;

  No *novo = (No*) malloc(sizeof(No));
  if(novo == NULL) return 0;

  novo->chave = chave;
  novo->esq = NULL;
  novo->dir = NULL;

  if(*raiz == NULL)
    *raiz = novo;

  else{
    No *atual = *raiz;
    No *ant = NULL;

    while(atual != NULL){
      ant = atual;

      if(chave == atual->chave){
        free(novo);
        return 0;  //Elemento já existe
      }

      if(chave > atual->chave)
        atual = atual->dir;
      else
        atual = atual->esq;
    }

    if(chave > ant->chave)
      ant->dir = novo;
    else
      ant->esq = novo;

  }
  return 1;

}

/****************************************************************************/
No* remover_no(No *atual)
{
  No *no1, *no2;

  if(atual->esq == NULL){
    no2 = atual->dir;
    free(atual); // libera memória do nó atual

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

int remover_arvore_binaria(Pno *raiz, int chave)
{
  if(raiz == NULL)
    return 0;

  No *ant = NULL;
  No *atual = *raiz;

  while(atual != NULL){
    if(chave == atual->chave){

      if(atual == *raiz)
        *raiz = remover_no(atual);
      else{
        if(ant->dir == atual)
          ant->dir = remover_no(atual); // remove o nó e atualiza a arvore
        else
          ant->esq = remover_no(atual); // remove o nó e atualiza a arvore
      }

      return 1;
    }
    ant = atual;

    if(chave > atual->chave)
      atual = atual->dir;
    else
      atual = atual->esq;
  }

  return 0;
}

/****************************************************************************/
int consultar_arvore_binaria(Pno *raiz, int chave)
{
  if(raiz == NULL)
    return 0;

  No *atual = *raiz;

  while(atual != NULL){
    if(chave == atual->chave) return 1;

    if(chave < atual->chave)
      atual = atual->esq;
    else
      atual = atual->dir;
  }

  return 0;
}

/****************************************************************************/
void percorrer_em_ordem_arvore_binaria(Pno *raiz)
{
  if(raiz == NULL) return;

  if(*raiz != NULL){
    percorrer_em_ordem_arvore_binaria(&((*raiz)->esq));
    printf("%d\n", (*raiz)->chave);
    percorrer_em_ordem_arvore_binaria(&((*raiz)->dir));
  }
}

/****************************************************************************/
void percorrer_pre_ordem_arvore_binaria(Pno *raiz)
{
  if(raiz == NULL) return;

  if(*raiz != NULL){
    printf("%d\n", (*raiz)->chave);
    percorrer_pre_ordem_arvore_binaria(&((*raiz)->esq));
    percorrer_pre_ordem_arvore_binaria(&((*raiz)->dir));
  }
}

/****************************************************************************/
void percorrer_pos_ordem_arvore_binaria(Pno *raiz)
{
  if(raiz == NULL) return;

  if(*raiz != NULL){
    percorrer_pos_ordem_arvore_binaria(&((*raiz)->esq));
    percorrer_pos_ordem_arvore_binaria(&((*raiz)->dir));
    printf("%d\n", (*raiz)->chave);
  }
}
