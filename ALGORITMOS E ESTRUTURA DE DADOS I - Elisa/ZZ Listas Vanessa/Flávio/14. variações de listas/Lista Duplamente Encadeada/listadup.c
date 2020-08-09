#include <stdio.h>
#include <stdlib.h>
#include "listadup.h"

struct no {
    int valor;
    struct no *prox;
    struct no *ant;
    
};

struct lista{
    struct no *inicio;
    struct no *fim;
    int tam;
};

lista * crialista()
{
    lista *l;
    l=(lista*)malloc(sizeof(no*));
    if(!l)
    {
        printf("\n Erro ao alocar !");
        exit(1);
    }
    
    //Inicializando lista
    l->inicio=NULL;
    l->fim=NULL;
    l->tam=0;
    
    return l;
}

void insereordenado(lista *l, int valor)
{
    no *novoNo;
    no *aux;
    
    novoNo=(no*)malloc(sizeof(no));
    if(!novoNo)
    {
        printf("\n Erro ao alocar !");
        exit(1);
    }
    //Inicializando novoNo
    novoNo->valor=valor;
    novoNo->prox=NULL;
    novoNo->ant=NULL;
    aux = l->inicio;
    
    //Verificar se a lista esta vazia
    if(aux== NULL)
    {
        l->inicio=novoNo;
        l->fim=novoNo;
        l->tam++;
        return;
    }
    
    // Vereficar se o inicio da fila é maior que o valor digitado
    if(aux->valor > valor)
    {
        aux->ant = novoNo;
        novoNo->prox=l->inicio;
        l->inicio=novoNo;
        l->tam++;
        return;
    }
    
    // Inserir valor ordenado
    while((aux->prox != NULL)&&(aux->prox->valor < valor))
    {
        aux = aux->prox;
    }
    novoNo->prox=aux->prox;
    aux->prox=novoNo;
    if(novoNo->prox != NULL) {
        novoNo->prox->ant = novoNo;
    }
    else {
        l->fim = novoNo;
    }
    l->tam++;
    
    return;

}

void imprimelista(lista *l)
{
    no *aux=l->inicio;
    
    while(aux != NULL)
    {
        printf(" %d ",aux->valor);
        aux=aux->prox;
    }
    return;
}

void imprimelistadec(lista *l)
{
    no *aux=l->fim;
    
    while(aux != NULL)
    {
        printf(" %d ",aux->valor);
        aux=aux->ant;
    }
    return;
}

void removeelemento(lista *l,int valor)
{
    no *aux=l->inicio;
    //Verificando se a lista esta vazia
    if(l->inicio == NULL)
    {
        printf("\n Lista vazia !");
        return;
    }
    //Verificando se o valor que vou remover é o inicio da lista
    if(valor == aux->valor)
    {
        l->inicio = aux->prox;
        if(l->inicio == NULL) 
            l->fim = NULL;
        else 
            l->inicio->ant = NULL;
        l->tam--;
        free(aux);
        return;
    }
    
    //Buscando a referencia do proximo valor que vai ser removido
    while((aux != NULL)&&(aux->valor < valor))
    {
        aux=aux->prox;
    } 
    //verificando se o numero existe na lista
    if(aux == NULL)
    {
        printf("\n Elemento não encontrado!\n");
    }
    else 
    {  
        if (aux->valor != valor){
            printf("\n Elemento não encontrado!\n");
        }
        else {
            l->fim = aux->ant;
        }
        aux->ant->prox = aux->prox;
        l->tam--;
        free(aux);
    }
    return ;
}



int consultaelemento(lista *l,int valor)
{
    no *aux=l->inicio;
    
    if(l->inicio->valor == valor)
    {
        return 1;
    }
    
    while((aux->prox != NULL)&&(aux->prox->valor < valor))
    {
        aux=aux->prox;
    }
    
    if((aux->prox == NULL) || (aux->prox->valor != valor))
    {
        return 0;
    }else return 1;
    
}

void esvazia(lista *l)
{
    no *aux;
    
    while(l->inicio != NULL)
    {
        aux=l->inicio;
        l->inicio=l->inicio->prox;
        l->tam--;
        free(aux);
        
    }
    return;
}

int listavazia(lista *l)
{
    if(l->inicio == NULL) return 0;
    else return 1;
}

int tamanholista(lista *l)
{
    return l->tam;
}