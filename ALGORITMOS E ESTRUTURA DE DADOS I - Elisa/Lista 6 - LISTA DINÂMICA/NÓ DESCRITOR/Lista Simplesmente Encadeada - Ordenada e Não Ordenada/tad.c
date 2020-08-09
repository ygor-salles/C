#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

/****************************************************************************/
Lista* criar_lista()
{
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL){
        li->inicio = NULL;
        li->fim = NULL;
    }
    return li;
}

/****************************************************************************/
int inserir_lista_inicio(Lista *li, int num)
{
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->num = num;
    if (li->inicio == NULL){
        li->inicio = no;
        li->fim = no;
        no->prox = NULL;
    }
    else{
        no->prox = li->inicio;
        li->inicio = no;
    }
    return 1;
}

/****************************************************************************/
int inserir_lista_fim(Lista *li, int num)
{
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->num = num;
    if (li->inicio == NULL){
        li->inicio = no;
        li->fim = no;
        no->prox = NULL;
    }
    else{
        li->fim->prox = no;
        li->fim = no;
        li->fim->prox = NULL;
    }
    return 1;
}

/****************************************************************************/
int inserir_lista_ordenada(Lista *li, int num)
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

  no->num = num;
  if( li->inicio == NULL ){
    no->prox = NULL;
    li->inicio = no;
  }
  else{
    Elemento *anterior, *atual;
    atual = li->inicio;

    while(atual != NULL && atual->num < num){
      anterior = atual;
      atual = atual->prox;
    }

    if( atual == li->inicio ){
      no->prox = li->inicio;
      li->inicio = no;
    }
    else{
      no->prox = atual;
      anterior->prox = no;
    }
  }
  return 1;
}

/****************************************************************************/
int imprimir_lista(Lista *li)
{
    if (li == NULL) return 0;
    if (li->inicio == NULL) printf("Lista vazia!");

    else{
        Elemento *no = li->inicio;
        do{
            printf (" %d",no->num);
            no = no->prox;
        } while(no!=NULL);
    }
    return 1;
}

/****************************************************************************/
int remover_elemento_inicio(Lista *li)
{
    if (li == NULL) return 0;
    if (li->inicio == NULL) printf("Lista vazia!");

    else{
        Elemento *no = li->inicio;
        li->inicio = li->inicio->prox;
        if (li->inicio == NULL)
            li->fim = NULL;
        free(no);
    }
    return 1;
}

/****************************************************************************/
int remover_elemento_fim(Lista *li)
{
    if (li == NULL) return 0;
    if (li->inicio == NULL) printf("Lista vazia!");

    else{
        Elemento *no, *anterior;
        no = li->inicio;

        do{
            anterior = no;
            no = no->prox;
        } while(no->prox!=NULL);

        if (no == li->inicio)
            li->inicio = no->prox;
        else
            anterior->prox = no->prox;
        free(no);
    }
    return 1;
}

/****************************************************************************/
int remover_elemento_dado(Lista *li, int num)
{
    int achou;
    if(li->inicio == NULL) printf("Lista Vazia!");

    else{
        Elemento *no, *anterior;
        no = li->inicio;
        anterior = NULL;
        achou = 0;
        do{
            if(no->num == num){
                achou++;
                if(no == li->inicio){
                    li->inicio = no ->prox;
                    free(no);
                    no = li->inicio;
                }
                else if (no == li->fim){
                    anterior->prox = NULL;
                    li->fim = anterior;
                    free(no);
                    no = NULL;
                }
                else{
                    anterior->prox = no->prox;
                    free(no);
                    no = anterior -> prox;
                }
            }
            else{
                anterior = no;
                no = no -> prox;
            }
        }while(no != NULL);

        if(achou == 0)
            printf("Numero nao encontrado!");
        else
            printf("Numero removido %d vez(es)",achou);
    }
    return 1;
}

/****************************************************************************/
int buscar_lista_posicao(Lista *li, int pos)
{
    int i=1;
    Elemento *no;
    if (li == NULL) return 0;
    if (li->inicio == NULL) printf("Lista vazia!");

    no = li->inicio;
    while(no->prox != li->inicio && i<pos){
        no = no->prox;
        i++;
    }

  if(i!=pos)
    return 0;
  return no->num;
}

/****************************************************************************/
void buscar_lista_dado(Lista *li, int num)
{
    if (li == NULL) printf("Lista vazia!");
    if (li->inicio == NULL) printf("Lista vazia!");

    int i=1;
    Elemento *no = li->inicio;
    while(no->prox != li->inicio && no->num!=num){
        no = no->prox;
        i++;
    }

    if(no->num!=num)
        printf ("\nNumero não encontrado!");
    else
        printf("\nA posição do número %d é %d\n",num, i);
}

/****************************************************************************/
int tamanho_lista(Lista *li)
{
    int cont=0;
    if(li == NULL) return 0;
    if (li->inicio == NULL) printf ("Lista Vazia!");

    else{
        Elemento *no = li->inicio;
        do{
            cont++;
            no = no->prox;
        } while(no!=NULL);
    }
    return cont;
}

/****************************************************************************/
int lista_vazia(Lista *li)
{
    if(li == NULL) return 1;
    if(li->inicio == NULL) return 1;
    return 0;
}

/****************************************************************************/
int esvaziar_lista(Lista *li)
{
    if (li == NULL) return 0;
    if (li->inicio == NULL) printf("Lista vazia!");

    else{
        Elemento *no = li->inicio;
        do{
            li->inicio = li->inicio->prox;
            free(no);
            no = li->inicio;
        } while(no!=NULL);
    }
    return 1;
}



