#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

struct No
{
    int cod, qtd;
    float preco;
    struct No *prox;
};

struct Lista
{
    struct No *inicio;
    struct No *fim;
};

No *aux;
No *anterior;

Lista *cria_lista ()
{
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL){
        li->inicio = NULL;
        li->fim = NULL;
    }
    return li;
}

void insere_produto (Lista *li)
{
    No *novo = (No*) malloc(sizeof(No));

    printf ("Digite o código: "); scanf ("%d",&novo->cod);
    printf ("Digite a quantidade: "); scanf ("%d",&novo->qtd);
    printf ("Digite o preço: "); scanf ("%f",&novo->preco);

    if (li->inicio == NULL){
        li->inicio = novo;
        li->fim = novo;
        li->fim->prox = NULL;
    }
    else{
        li->fim->prox = novo;
        li->fim = novo;
        li->fim->prox = NULL;
    }
    printf ("\nProduto inserido com sucesso!");
    return ;
}

void aplica_taxa (Lista *li, float taxa)
{
    if (li->inicio == NULL)
        printf ("\nLista vazia!");
    else{
        aux = li->inicio;
        do{
            aux->preco = aux->preco - aux->preco * (taxa/100);
            aux = aux->prox;
        } while (aux != NULL);
        printf ("\nTaxa aplicada com sucesso!");
    }
    return ;
}

void imprime_relatorio (Lista *li)
{
    if (li->inicio == NULL)
        printf ("\nLista vazia!");
    else{
        int qtd = 0;
        aux = li->inicio;
        do{
            printf("\nCodigo do produto %d ", aux->cod);
            printf("\nPreco do produto %.2f \n\n", aux->preco);
            if(aux->qtd > 500)
                qtd++;
            aux = aux->prox;
        }while(aux != NULL);
        printf("\nQuantidade de produtos com quantidade estocada superior a 500: %d\n", qtd);
    }
    return ;
}

void esvaziar_lixeira (Lista *li)
{
    if (li->inicio == NULL)
        printf ("\nLista Vazia!\n");
    else{
        aux = li->inicio;
        do {
            li->inicio = li->inicio->prox;
            free(aux);
            aux = li->inicio;
        } while (aux != NULL);
        printf ("\nLista Vazia!\n");
    }
    return ;
}



