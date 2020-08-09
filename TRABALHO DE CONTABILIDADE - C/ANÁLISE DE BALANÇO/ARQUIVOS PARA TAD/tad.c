#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int inserir_lista_fim(Lista *li, Transacao dados)
{
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = dados;
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
int imprimir_lista(Lista *li)
{
    if (li == NULL) return 0;
    if (li->inicio == NULL) printf("Lista vazia!");

    else{
        Elemento *no = li->inicio;
        do{
            printf("\nTipo: %s",no->dados.tipo);
            printf ("\nTransação: %s",no->dados.nome);
            printf ("\nCódigo: %d\n",no->dados.cod);

            no = no->prox;
        } while(no!=NULL);
    }
    return 1;
}

/****************************************************************************/
int remover_elemento_dado(Lista *li, int codigo)
{
    int achou;
    if(li->inicio == NULL) printf("Lista Vazia!");

    else{
        Elemento *no, *anterior;
        no = li->inicio;
        anterior = NULL;
        achou = 0;
        do{
            if(no->dados.cod == codigo){
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

        if(achou == 0){
            printf("Transação nao encontrada!"); return -1;
        }
    }
    return 1;
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
