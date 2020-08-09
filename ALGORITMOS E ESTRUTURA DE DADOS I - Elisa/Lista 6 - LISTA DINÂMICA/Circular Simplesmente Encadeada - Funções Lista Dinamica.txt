#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "tad.h"

/****************************************************************************/
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL)
    li->ponteiro = NULL;

  return li;
}

/****************************************************************************/
int inserir_lista_inicio(Lista *li, int num)
{
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->num = num;
    if(li->ponteiro == NULL){
        no->prox = no;
        li->ponteiro = no;
    }
    else{
        Elemento *aux;
        aux = li->ponteiro;

        while(aux->prox != li->ponteiro)
            aux = aux->prox;

        aux->prox = no;
        no->prox = li->ponteiro;
        li->ponteiro = no;
    }
    return 1;
}

/****************************************************************************/
int inserir_lista_fim(Lista *li, int num)
{
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->num = num;
    if(li->ponteiro == NULL){
        no->prox = no;
        li->ponteiro = no;
    }
    else{
        Elemento *aux;
        aux = li->ponteiro;

        while(aux->prox != li->ponteiro)
            aux = aux->prox;

        aux->prox = no;
        no->prox = li->ponteiro;
    }
    return 1;
}

/****************************************************************************/
int inserir_lista_ordenada(Lista *li, int num)
{
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->num = num;
    if(li->ponteiro == NULL){
        no->prox = no;
        li->ponteiro = no;
    }
    else{
        if(li->ponteiro->num > num){
            Elemento *aux;
            aux = li->ponteiro;
            while(aux->prox != li->ponteiro)
                aux = aux->prox;
            aux->prox = no;
            no->prox = li->ponteiro;
            li->ponteiro = no;
        }

        Elemento *anterior, *atual;
        anterior = li->ponteiro;
        atual = anterior->prox;

        while(atual != li->ponteiro && atual->num < num){
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = no;
        no->prox = atual;
    }
    return 1;
}

/****************************************************************************/
int imprimir_lista(Lista *li)
{
    if (li == NULL) return 0;
    if (li->ponteiro == NULL) printf("Lista vazia!");

    else{
        Elemento *no = li->ponteiro;
        do{
            printf (" %d",no->num);
            no = no->prox;
        } while(no!=li->ponteiro);
    }
    return 1;
}

/****************************************************************************/
int remover_elemento_inicio(Lista *li)
{
    if (li->ponteiro == NULL || li == NULL) {
        printf("Lista vazia!");
        return 0;
    }

    else{
        if (li->ponteiro->prox == li->ponteiro){
            free(li->ponteiro);
            li->ponteiro = NULL;
            return 1;
        }
        Elemento *no, *aux;
        no = li->ponteiro;
        aux = li->ponteiro;

        while(aux->prox != li->ponteiro)
            aux = aux->prox;

        aux->prox = no->prox;
        li->ponteiro = no->prox;

        free(no);
    }
    return 1;
}

/****************************************************************************/
int remover_elemento_fim(Lista *li)
{
    if (li->ponteiro == NULL || li == NULL) {
        printf("Lista vazia!");
        return 0;
    }

    else{
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
    }
    return 1;
}

/****************************************************************************/
int remover_elemento_dado(Lista *li, int num)
{
    if (li->ponteiro == NULL || li == NULL) {
        printf("Lista vazia!");
        return 0;
    }

    else{
        Elemento *no = li->ponteiro;

        if(no->num == num){
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

        while(no != li->ponteiro && no->num != num){
            anterior = no;
            no = no->prox;
        }
        if(no == li->ponteiro) return 0;

        anterior->prox = no->prox;
        free(no);
    }
    return 1;
}

/****************************************************************************/
int buscar_lista_posicao(Lista *li, int pos)
{
    if (li->ponteiro == NULL || li == NULL) {
        printf("Lista vazia!");
        return 0;
    }

    else{
        int i = 1;
        Elemento *no = li->ponteiro;
        while(no->prox != li->ponteiro && i < pos){
            no = no->prox;
            i++;
        }
        if(i != pos) return 0;
        return no->num;
    }
}

/****************************************************************************/
int buscar_lista_dado(Lista *li, int num)
{
    if (li->ponteiro == NULL || li == NULL) {
        printf("Lista vazia!");
        return 0;
    }

    else{
        int i = 1;
        Elemento *no = li->ponteiro;
        while( no->prox != li->ponteiro && no->num != num){
            no = no->prox;
            i++;
        }
        if(no->num != num) return 0;
        return i;
    }

}

/****************************************************************************/
int tamanho_lista(Lista *li)
{
    int cont = 0;
    if (li->ponteiro == NULL || li == NULL) {
        printf("Lista vazia!");
        return 0;
    }

    else{
        Elemento *no = li->ponteiro;
        do{
            cont++;
            no = no->prox;
        }while(no != li->ponteiro);
    }
    return cont;
}

/****************************************************************************/
int lista_vazia(Lista *li)
{
  if(li == NULL) return 1;
  if(li->ponteiro == NULL) return 1;
  return 0;
}

/****************************************************************************/
int esvaziar_lista(Lista *li)
{
    if (li->ponteiro == NULL || li == NULL) {
        printf("Lista vazia!");
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


