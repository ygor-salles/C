#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "tad.h"

int imprimir_produto(Produto *produto)
{
  printf("\n\n   Código: %d", produto->codigo);
  printf("\n   Descrição: %s", produto->descricao);
  printf("\n   Preço: %.2f", produto->preco);
  printf("\n   Quantidade: %d", produto->qtd);

  return 1;
}

/****************************************************************************/
int criar_produto(Produto **produto)
{
  *produto = (Produto*) malloc(sizeof(Produto));

  printf("\n Código: ");
  scanf("%d", &(*produto)->codigo);

  printf(" Descrição: ");
  scanf(" %[^\n]", (*produto)->descricao);

  printf(" Preço: ");
  scanf("%f", &(*produto)->preco);

  printf(" Quantidade: ");
  scanf("%d", &(*produto)->qtd);

  return 1;
}

/****************************************************************************/
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));

  if(li != NULL){
    li->ponteiro = NULL;
  }else{
    return NULL;
  }

  return li;
}

/****************************************************************************/
int liberar_lista(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  if(li->ponteiro != NULL){
    Elemento *no, *aux;
    no = li->ponteiro;

    while( no->prox !=  li->ponteiro ){
      aux = no;
      no = no-> prox;
      free(aux);
    }
    free(no);

    free(li);
  }

  return 1;
}

/****************************************************************************/
int tamanho_lista(Lista *li)
{
  if(li == NULL || li->ponteiro == NULL){
    return 0;
  }

  int cont = 0;

  Elemento *no;
  no = li->ponteiro;

  do{
    cont++;
    no = no->prox;
  }while(no != li->ponteiro);

  return cont;
}

/****************************************************************************/
int lista_vazia(Lista *li)
{
  if(li == NULL)
    return -1;

  if(li->ponteiro == NULL)
    return 1;

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
int inserir_lista_inicio(Lista *li, Produto *produto)
{
  if(li == NULL){
    return 0;
  }

  Elemento *no;
  no = criar_elemento();

  no->produto = produto;

  if(li->ponteiro == NULL){
    no->prox = no;
    li->ponteiro = no;
  }else{
    Elemento *aux;
    aux = li->ponteiro;

    while(aux->prox != li->ponteiro){
      aux = aux->prox;
    }
    aux->prox = no;
    no->prox = li->ponteiro;
    li->ponteiro = no;
  }

  return 1;
}

/****************************************************************************/
int inserir_lista_final(Lista *li, Produto *produto)
{
  if(li == NULL){
    return 0;
  }

  Elemento *no;
  no = criar_elemento();

  no->produto = produto;

  if( li->ponteiro == NULL ){
    no->prox = no;
    li->ponteiro = no;
  }else{
    Elemento *aux;
    aux = li->ponteiro;
    while(aux->prox != li->ponteiro){
      aux = aux->prox;
    }

    aux->prox = no;
    no->prox = li->ponteiro;
  }

  return 1;
}

/****************************************************************************/
int inserir_lista_ordenada(Lista *li, Produto *produto)
{
  if(li == NULL){
    return 0;
  }

  Elemento *no;
  no = criar_elemento();

  no->produto = produto;

  if( li->ponteiro == NULL ){
    no->prox = no;
    li->ponteiro = no;
  }else{
    if(li->ponteiro->produto->codigo > produto->codigo){
      Elemento *aux;
      aux = li->ponteiro;
      while(aux->prox != li->ponteiro){
        aux = aux->prox;
      }

      aux->prox = no;
      no->prox = li->ponteiro;
      li->ponteiro = no;
    }

    Elemento *anterior, *atual;

    anterior = li->ponteiro;
    atual = anterior->prox;

    while(atual != li->ponteiro && atual->produto->codigo < produto->codigo){
      anterior = atual;
      atual = atual->prox;
    }

    anterior->prox = no;
    no->prox = atual;
  }

  return 1;
}

/****************************************************************************/
int remover_lista_inicio(Lista *li)
{
  if(li == NULL)
    return 0;

  if(li->ponteiro == NULL)
    return 0;

  if (li->ponteiro->prox == li->ponteiro){
    free(li->ponteiro);
    li->ponteiro = NULL;
    return 1;
  }

  Elemento *no, *aux;
  no = li->ponteiro;
  aux = li->ponteiro;

  while(aux->prox != li->ponteiro){
    aux = aux->prox;
  }

  aux->prox = no->prox;
  li->ponteiro = no->prox;

  free(no);

  return 1;
}

/****************************************************************************/
int remover_lista_final(Lista *li)
{
  if(li == NULL)
    return 0;

  if(li->ponteiro == NULL)
    return 0;

  if (li->ponteiro->prox == li->ponteiro){
    free(li->ponteiro);
    li->ponteiro = NULL;
    return 1;
  }

  Elemento *anterior, *no;
  no = li->ponteiro;

  while(no->prox != li->ponteiro){
    anterior = no;
    no = no->prox;
  }
  anterior->prox = no->prox;
  free(no);

  return 1;
}

/****************************************************************************/
int remover_lista_meio(Lista *li, int codigo)
{
  if(li == NULL)
    return 0;

  if(li->ponteiro == NULL)
    return 0;

  Elemento *no;
  no = li->ponteiro;

  if(no->produto->codigo == codigo){
    if (no->prox == no){
      li->ponteiro = NULL;
      free(no);
      return 1;
    }
    else{
      Elemento *ultimo;
      ultimo = li->ponteiro;

      while(ultimo->prox != li->ponteiro)
        ultimo = ultimo->prox;

      ultimo->prox = no->prox;
      li->ponteiro = no->prox;
      free(no);

      return 1;
    }
  }

  Elemento *anterior;
  anterior = no;
  no = no->prox;

  while(no != li->ponteiro && no->produto->codigo != codigo){
    anterior = no;
    no = no->prox;
  }

  if(no == li->ponteiro)
    return 0;

  anterior->prox = no->prox;

  free(no);

  return 1;
}

/****************************************************************************/
Produto *buscar_lista_posicao(Lista *li, int pos)
{
  if(li == NULL || li->ponteiro == NULL || pos <= 0)
    return NULL;

  int i = 1;
  Elemento *no;
  no = li->ponteiro;

  while( no->prox != li->ponteiro && i < pos){
    no = no->prox;
    i++;
  }

  if(i != pos)
    return NULL;

  return no->produto;
}

/****************************************************************************/
Produto *buscar_lista_dado(Lista *li, int codigo)
{
  if(li == NULL || li->ponteiro == NULL)
    return NULL;

  int i = 1;
  Elemento *no;
  no = li->ponteiro;

  while( no->prox != li->ponteiro && no->produto->codigo != codigo){
    no = no->prox;
    i++;
  }

  if(no->produto->codigo != codigo)
    return NULL;

  return no->produto;
}

/****************************************************************************/
int imprimir_lista(Lista *li)
{
  if(li == NULL)
    return 0;

  if(li->ponteiro == NULL)
    printf(" Lista vazia!");

  Elemento *no;
  no = li->ponteiro;

  while(no->prox != li->ponteiro){
    imprimir_produto(no->produto);
    no = no->prox;
  }

  imprimir_produto(no->produto);

  return 1;
}
