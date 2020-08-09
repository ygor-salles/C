#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

//DEFINIÇÃO DE CORES - PRETO 0 E VERMEHLO 1
#define RED 1
#define BLACK 0

// definição do struct elemento
struct no{
  int chave;
  char nome[20];
  struct no *esq;
  struct no *dir;
  int cor;
};

/****************************************************************************/
int cor (No* h)
{
    if (h == NULL) return BLACK;
    else return h->cor;
}

/****************************************************************************/
void troca_cor (No* h)
{
    //INVERTE A COR DO PAI E DE SEUS FILHOS - A EXCLAMAÇÃO FAZ A INVERSÃO
    h->cor = !h->cor;
    if (h->esq != NULL)
        h->esq->cor = !h->esq->cor;
    else if (h->dir != NULL)
        h->dir->cor = !h->dir->cor;
}

/****************************************************************************/
No* rotaciona_esquerda (No* raiz)
{
    No *aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;

    aux->cor = RED;
    return aux;
}

/****************************************************************************/
No* rotaciona_direita (No* raiz)
{
    No *aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;

    aux->cor = RED;
    return aux;
}

/****************************************************************************/
No* move2_esq_RED (No* h)
{
    //RECEBE UM NÓ H E TROCA AS CORES DELE E DE SEUS FILHOS
    troca_cor(h);

    //SE O FILHO A ESQUERDA DO FILHO DIREITO É VERMELHO,
    //APLICAR UMA ROTAÇÃO A DIREITA NO FILHO DIREITO E UMA ROTAÇÃO A ESQUERDA NO PAI
    if (cor(h->dir->esq) == RED){
        h->dir = rotaciona_direita(h->dir);
        h = rotaciona_esquerda(h);
        //TROCA AS CORES DO NO PAI E DE SEUS FILHOS
        troca_cor(h);
    }
    return h;
}

/****************************************************************************/
No* move2_dir_RED (No* h)
{
    //RECEBER UM NÓ H E TROCA AS CORES DE SEUS FILHOS
    troca_cor(h);

    //SE O FILHO A ESQUERDA DO FILHO ESQUERDO É VERMELHO, APLICAR A ROTAÇÃO DIREITA NO PAI
    if (cor(h->esq->esq) == RED){
        h = rotaciona_direita(h);
        //TROCA AS CORES DO NÓ PAI E SEUS FILHOS
        troca_cor(h);
    }
    return h;
}

/****************************************************************************/
No* balancear (No* h)
{
    //NÓ VERMELHO É SEMPRE FILHO A ESQUERDA, ENTÃO SE FILHO DA DIREITA FOR VERMELHO DEVE ROTACIONAR
    if (cor(h->dir) == RED)
        h = rotaciona_esquerda(h);

    //FILHO DA DIREITA E NETO DA ESQUERDA SÃO VERMELHOS
    if (h->esq != NULL && cor(h->dir)==RED && cor(h->esq->esq)==RED)
        h = rotaciona_direita(h);

    //SE DOIS FILHOS VERMELHOS: TROCA A COR
    if (cor(h->esq)==RED && cor(h->dir)==RED)
        troca_cor(h);

    return h;
}

/****************************************************************************/
Pno* criar()
{
  Pno *raiz = (Pno*) malloc(sizeof(Pno));

  if(raiz != NULL)
    *raiz = NULL;

  return raiz;
}

/****************************************************************************/
// funcao para desalocar memoria de um nó da arvore
void liberar_no(No *no)
{
  if(no == NULL)
    return;

  liberar_no(no->esq);
  liberar_no(no->dir);
  free(no);
  no = NULL;
}

int liberar(Pno *raiz)
{
  if(raiz == NULL)
    return 0;

  liberar_no(*raiz); //libera cada no
  free(raiz); // libera a raiz

  return 1;
}

/****************************************************************************/
int quantidade_nos(Pno *raiz)
{
  // se o ponteiro for nulo ou se a arvore estiver vazio
  if(raiz == NULL || *raiz == NULL)
    return 0;

  // calcula o numero de nos na subarvore esquerda
  int total_esq = quantidade_nos(&((*raiz)->esq));

  // calcula o numero de nos na subarvore direita
  int total_dir = quantidade_nos(&((*raiz)->dir));

  // total é a quantidade de nos das subarvores mais a raiz
  return (total_esq + total_dir + 1);
}


/****************************************************************************/
int altura(Pno *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 0;

  // calcula a altura da subarvore esquerda
  int alt_esq = altura(&((*raiz)->esq));

  // calcula a altura da subarvore direita
  int alt_dir = altura(&((*raiz)->dir));

  // altura da arvore é a altura da maior subarvore mais a raiz
  if(alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

/****************************************************************************/
int esta_vazia(Pno *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 1;

  return 0;
}

/****************************************************************************/
//FUNÇÃO DE GERENCIAMENTO DA INSERÇÃO - GARANTIR QUE A RAIZ SEMPRE SEJA PRETA
int inserir(Pno* raiz, int chave, char nome[])
{
  int resp;
    //FUNÃO INSERENO É RESPONSÁVEL PELA BUSCA LOCAL DA INSERÇÃO DO NÓ
    *raiz = insereNO(*raiz, chave, nome, &resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;

    return resp;
}

No* insereNO(No* h, int chave, char nome[], int *resp)
{
    if (h==NULL){
        No *novo;
        novo = (No*) malloc(sizeof(No));
        if (novo == NULL){
            *resp = 0;
            return NULL;
        }

        novo->chave = chave;
        strcpy(novo->nome, nome);
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }

    if (chave == h->chave) *resp=0;
    else{
        if(chave < h->chave)
            h->esq = insereNO(h->esq, chave, nome, resp);
        else
            h->dir = insereNO(h->dir, chave, nome, resp);
    }

    h = balancear(h);
    return h;
}


/****************************************************************************/
//FUNÇÃO DE GERENCIAMENTO DA REMOÇÃO - GARANTIR QUE A RAIZ SEMPRE SEJA PRETA
int remover(Pno *raiz, int chave)
{
  if (consultar(raiz, chave)){
        No* h = *raiz;
        //FUNÃO INSERENO É RESPONSÁVEL PELA BUSCA LOCAL DA REMOÇÃO DO NÓ
        *raiz = removeNO(h, chave);
        if (*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }
    else
        return -1;
}

No* removeNO (No* h, int chave)
{
    if (chave < h->chave){
        if (cor(h->esq) == BLACK && cor(h->esq->esq) == BLACK)
            h = move2_esq_RED(h);
        h->esq = removeNO(h->esq, chave);
    }
    else{
        if(cor(h->esq) == RED)
            h = rotaciona_direita(h);

        if (chave == h->chave && (h->dir == NULL)){
            free(h);
            return NULL;
        }

        if (cor(h->dir) == BLACK && cor(h->dir->esq) == BLACK)
            h = move2_dir_RED(h);

        if(chave == h->chave){
            No *x = proucura_menor(h->dir);
            h->chave = x->chave;
            h->dir = removerMenor (h->dir);
        }
        else
            h->dir = removeNO(h->dir, chave);
    }
    return balancear(h);
}

No* removerMenor (No* h)
{
    if (h->esq == NULL){
        free(h); return NULL;
    }
    if (cor(h->esq) == BLACK && cor(h->esq->esq) == BLACK)
        h = move2_esq_RED(h);

    h->esq = removerMenor(h->esq);
    return balancear(h);
}

No* proucura_menor(No* atual)
{
    No *no1 = atual;
    No *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

/****************************************************************************/
int consultar(Pno *raiz, int chave)
{
  if(raiz == NULL)
    return 0;

  No *atual = *raiz;

  // percorre a arvore binaria até encontrar o chave desejado
  while(atual != NULL){

    // retorna 1 quando encontra o chave
    if(chave == atual->chave){
      return 1;
    }

    // identifica a subarvore pela qual irá percorrer
    if(chave < atual->chave){
      atual = atual->esq;
    }else{
      atual = atual->dir;
    }
  }

  return 0;
}

/****************************************************************************/
void percorrer_em_ordem(Pno *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_em_ordem(&((*raiz)->esq));
    printf(" %d %s\n", (*raiz)->chave, (*raiz)->nome);
    percorrer_em_ordem(&((*raiz)->dir));
  }
}

// função para percorrer a arvore binaria em pré ordem
void percorrer_pre_ordem(Pno *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    printf(" %d %s\n", (*raiz)->chave, (*raiz)->nome);
    percorrer_pre_ordem(&((*raiz)->esq));
    percorrer_pre_ordem(&((*raiz)->dir));
  }
}

// função para percorrer a arvore binaria em pós ordem
void percorrer_pos_ordem(Pno *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_pos_ordem(&((*raiz)->esq));
    percorrer_pos_ordem(&((*raiz)->dir));
    printf(" %d %s\n", (*raiz)->chave, (*raiz)->nome);
  }
}

void print_arvore(Pno *raiz)
{
  if(raiz == NULL) return;
  printf("(%d %s, ", (*raiz)->chave, (*raiz)->nome);
  print_arvore(&((*raiz)->esq));
  printf(", ");
  print_arvore(&((*raiz)->dir));
  printf(")");
}
