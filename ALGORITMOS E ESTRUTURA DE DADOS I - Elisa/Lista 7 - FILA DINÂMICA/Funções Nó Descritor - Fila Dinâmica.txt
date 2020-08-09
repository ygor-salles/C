#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

/****************************************************************************/
Fila* criar_fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if (fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

/****************************************************************************/
int enfileirar(Fila* fi, Aluno dados_aluno)
{
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = dados_aluno;
    no->prox = NULL;
    if (fi->inicio == NULL){
        fi->inicio = no;
        fi->fim = no;
    }
    else{
        fi->fim->prox = no;
        fi->fim = no;
    }
    return 1;
}

/****************************************************************************/
int desenfileirar(Fila* fi)
{
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) printf("Fila Vazia!");

    else{
        Elemento *no = fi->inicio;
        fi->inicio = fi->inicio->prox;
        if (fi->inicio == NULL)
            fi->fim = NULL;
        free(no);
    }
    return 1;
}

/****************************************************************************/
int tamanho_fila(Fila* fi)
{
    int cont=0;
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) printf("Fila Vazia!");

    else{
        Elemento *no = fi->inicio;
        while (no != NULL){
            cont++;
            no = no->prox;
        }
    }
    return cont;
}

/****************************************************************************/
int fila_vazia(Fila* fi)
{
    if (fi == NULL) return 1;
    if (fi->inicio == NULL) return 1;

    return 0;
}

/****************************************************************************/
int consulta_fila(Fila* fi, Aluno *dados_aluno)
{
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) printf("Fila vazia!");

    else
        *dados_aluno = fi->inicio->dados;

    return 1;
}

/****************************************************************************/
int imprimir_fila(Fila* fi)
{
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) printf("Fila Vazia!");

    else{
        Elemento *no;
        no = fi->inicio;
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
int esvazia_fila(Fila* fi)
{
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) printf ("Fila Vazia!");

    else{
        Elemento *no;
        no= fi->inicio;
        do{
            fi->inicio = fi->inicio->prox;
            free(no);
            no=fi->inicio;
        } while (no != NULL);
        printf ("Fila Esvaziada!");
    }
    return 1;
}

/****************************************************************************/
int fila_cheia(Fila* fi)
{
    return 0;
}



