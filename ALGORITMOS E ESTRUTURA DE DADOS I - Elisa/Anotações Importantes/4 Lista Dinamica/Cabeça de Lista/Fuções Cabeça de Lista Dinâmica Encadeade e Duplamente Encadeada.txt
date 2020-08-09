//TAD Lista Encadeada

#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

struct elemento{
  int dado;
  struct elemento *prox;
};

typedef struct elemento Elemento;
typedef Elemento* Lista;

/****************************************************************************/
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));

  if(li != NULL)
    *li = NULL;
  else
    return NULL;
  
  return li;
}

/****************************************************************************/
void liberar_lista(Lista *li)
{
  if(li != NULL){
    Elemento *no;
    while( (*li) != NULL ){
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

/****************************************************************************/
int tamanho_lista(Lista *li)
{
  if(li == NULL)
    return 0;

  int cont = 0;
  Elemento *no = *li;

  while(no != NULL){
    cont++;
    no = no->prox;
  }
  return cont;
}

/****************************************************************************/
int lista_vazia(Lista *li)
{
  if(li == NULL)
    return 1;

  if(*li == NULL)
    return 1;
  
  return 0;
}

/****************************************************************************/
int lista_cheia(Lista *li)
{
  return 0;
}

/****************************************************************************/
Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));
  if(no == NULL)
    return 0;

  return no;
}

/****************************************************************************/
int inserir_lista_inicio(Lista *li, int dado)
{
  if(li == NULL)
    return 0;

  Elemento *no;
  no = criar_elemento();

  no->dado = dado;
  no->prox = NULL;
  *li = no;

  return 1;
}

/****************************************************************************/
int inserir_lista_final(Lista *li, int dado)
{
  if(li == NULL)
    return 0;

  Elemento *no;
  no = criar_elemento();

  no->dado = dado;
  no->prox = NULL;

  if( (*li) == NULL )
    *li = no;
  else{
    Elemento *aux;
    aux = *li;
    
    while(aux->prox != NULL)
      aux = aux->prox;
    
    aux->prox = no;
  }

  return 1;
}

/****************************************************************************/
int inserir_lista_ordenada(Lista *li, int dado)
{
  if(li == NULL)
    return 0;

  Elemento *no;
  no = criar_elemento();

  no->dado = dado;
  if( (*li) == NULL ){
    no->prox = NULL;
    *li = no;
  }
  else{
    Elemento *anterior, *atual;
    atual = *li;

    while(atual != NULL && atual->dado < dado){
      anterior = atual;
      atual = atual->prox;
    }
    
    if( atual == (*li) ){
      no->prox = (*li);
      *li = no;
    }
    else{
      no->prox = atual;
      anterior->prox = no;
    }
  }

  return 1;
}

/****************************************************************************/
int remover_lista_inicio(Lista *li)
{
  if(li == NULL){
    return 0;

  if((*li) == NULL)
    return 0;

  Elemento *no;
  no = *li;
  *li = no->prox;

  free(no);
  return 1;
}

/****************************************************************************/
int remover_lista_final(Lista *li)
{
  if(li == NULL)
    return 0;

  if((*li) == NULL)
    return 0;

  Elemento *anterior, *no;
  no = *li;

  while(no->prox != NULL){
    anterior = no;
    no = no->prox;
  }

  if(no == (*li))
    *li = no->prox;
  else
    anterior->prox = no->prox;

  free(no);
  return 1;
}

/****************************************************************************/
int remover_lista_meio(Lista *li, int dado)
{
  if(li == NULL)
    return 0;
  
  if((*li) == NULL)
    return 0;

  Elemento *anterior, *no;
  no = *li;

  while(no != NULL && no->dado != dado){
    anterior = no;
    no = no->prox;
  }

  if(no == NULL)
    return 0;

  if(no == (*li))
    *li = no->prox;
  else
    anterior->prox = no->prox;

  free(no);
  return 1;
}

/****************************************************************************/
int buscar_lista_posicao(Lista *li, int pos)
{
  if(li == NULL || (*li) == NULL || pos <= 0)
    return -1;  
    
  int i = 1;
  Elemento *no;
  no = *li;
  
  while( no->prox != (*li) && i < pos){
    no = no->prox;
    i++;
  }

  if(i != pos)
    return -1;

  return no->dado;
}

/****************************************************************************/
int buscar_lista_dado(Lista *li, int dado)
{
  if(li == NULL || (*li) == NULL)
    return -1;  
  
  int i = 1;
  Elemento *no;
  no = *li;

  while( no->prox != (*li) && no->dado != dado){
    no = no->prox;
    i++;
  }

  if(no->dado != dado)
    return -1;

  return i;
}

/****************************************************************************/
int imprimir_lista(Lista *li)
{
  if(li == NULL)
    return 0;

  if((*li) == NULL)
    printf(" Lista vazia!");

  Elemento *no;
  no = (*li);

  while(no->prox != (*li)){
    printf(" %d", no->dado);
    no = no->prox;
  }

  printf(" %d", no->dado);
  
  return 1;
}
