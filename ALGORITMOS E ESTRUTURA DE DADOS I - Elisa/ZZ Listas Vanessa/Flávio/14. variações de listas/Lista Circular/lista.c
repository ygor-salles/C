#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    int valor;
    struct no *prox;
    
};

struct lista{
    struct no *inicio;
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
    l->tam=0;
    
    return l;
}

void insereordenado(lista *l, int valor)
{
    no *novono;
    no *aux;
    
    novono=(no*)malloc(sizeof(no));
    if(!novono)
    {
        printf("\n Erro ao alocar !");
        exit(1);
    }
    //Inicializando novoNo
    novono->valor=valor;
    novono->prox=NULL;
    aux=l->inicio;
    
    if ((aux == NULL) || (aux->valor > valor)) {
        novono->prox = aux;
        l->tam++;
        //se mudou o início da lista, precisa mudar
        if(aux == NULL){
            novono->prox = novono;
            l->inicio = novono;
            return;
        }
        while (aux->prox != l->inicio) {
            aux = aux->prox;
        }
        aux->prox = novono;
        l->inicio = novono;
        return;
    }
    while ((aux->prox != l->inicio) && (aux->prox->valor < valor)) {
        aux = aux->prox;
    }
    novono->prox = aux->prox;
    aux->prox = novono;
    l->tam++;
    return;
}

void imprimelista(lista *l)
{
    no *aux =l->inicio;
    if(listavazia(l) == -1) {
        printf("A lista esta vazia\n");
        return;
    } 
    while(aux->prox != l->inicio)
    {
        printf(" %d ",aux->valor);
        aux=aux->prox;
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
    if(valor == l->inicio->valor)
    {
        while(aux->prox != l->inicio)  {
            aux = aux->prox;
        }
        aux->prox = l->inicio->prox;
        aux = l->inicio;
        l->inicio = aux->prox;
        free(aux);
        return;
    }
    
    //Buscando a referencia do proximo valor que vai ser removido
    while((aux->prox != NULL)&&(aux->prox->valor < valor))
    {
        aux=aux->prox;
    }

    //verificando se o numero existe na lista
    if((aux->prox == NULL)||(aux->prox->valor != valor))
    {
        printf("\n Este numero nao exite !");
        return;
    }
    else
    {
        
        
        no *temp=aux->prox;
        
        aux->prox=aux->prox->prox;
        l->tam--;
        free(temp);
        
        return;
    }

}



no* consultaelemento(lista *l,int valor)
{
    no *aux=l->inicio;
    
    if (aux == NULL) {
        printf("Lista vazia\n");
        return NULL;
    }
    while (aux->prox != l->inicio && aux->valor < valor) {
        aux = aux->prox;
    }
    if ((aux == l->inicio) || (aux->valor != valor)) {
        return NULL;
    }
    else
        return aux;
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

int tamanhocalc(lista *l, no *pos) {
    int tam=0;
    no *aux = pos;
    if(!aux) 
        return 0;
    while(aux->prox != pos) {
        tam ++;
        aux = aux->prox;
    }
    return tam;
}