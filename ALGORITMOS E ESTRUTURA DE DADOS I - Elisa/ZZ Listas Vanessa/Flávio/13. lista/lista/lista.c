#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

struct n{
    int valor;
    no *prox;
};

struct lis{
    no inicio;
    int qtd;
};

lista *crialista(){
    lista *l;
    l = (lista*) malloc(sizeof(lista));
    if(!l) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    lis->qtd=0;
    lis->inicio=NULL;
    return l;
}

void InsereOrdenado(lista *l, int valor) {
    no *novono, *aux;
    novono = (no*) malloc(sizeof(no));
    if(!novono) {
        printf("Erro ao alocar\n");
        exit(1);
    }  
    novono->valor = valor;
    novono->prox = NULL;
    
    
    //lista vazia
    if(l->inicio==NULL) {
        l->inicio = novono;
        l->qtd++;
        return ;
    }
    
    //elemento é o primeiro da lista
    else if(l->inicio->valor > valor) {
        novono->prox = l->inicio;
        l->inicio = novono;;
        l->qtd++;
        return ;
    }
    
    //inserir em outra posição da lista
    else {
        aux= l->inicio;
        while((aux->prox != NULL) && (aux->prox->valor < valor)){
            aux = aux->prox;
        }
        novono->valor = aux->prox;
        aux->prox = novono;
        l->qtd++;
        return ;
    }
}