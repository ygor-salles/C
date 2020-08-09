#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

struct n{
    int dado;
    no *prox;
};

struct fil {
    no *inicio;
    no *fim;
    int qtd;
};

fila *criafila() {
    fila *f;
    f = (fila*) malloc(sizeof(fila));
    if(!f) {
        printf("Erro ao alocar a fila\n");
        exit(1);
    }
    f->fim = NULL;
    f->inicio = NULL;
    f->qtd = 0;
    return f;
}

void enfileirar(fila *f, int elemento) {
    //alocar memoria e inicializar o novo nó
    no *novono;
    
    novono = (no*)malloc(sizeof(no));
    if(!novono) {
        printf("Erro ao alocar\n");
    }
    novono->dado = elemento;
    novono->prox = NULL;
     //caso a fila esteja vazia   
    if(f->inicio == NULL) { 
        f->inicio = novono; 
        f->fim = novono;
    }
    //caso a fila esteja com nós
    else {
        f->fim->prox = novono; 
        f->fim = novono;
    }
    //ajustar a quantidade
    f->qtd ++;
    
    return ;
}

int desinfileirar(fila *f) {
    no *aux;
    int res = -1; 
    
    if(f->inicio != NULL) {
        aux = f->inicio;
        res = f->inicio->dado;
        f->inicio = f->inicio->prox;
        if (f->inicio ==NULL) {
            f->fim = NULL;
        }
        f->qtd --;
        free(aux);
    }
    
    return res;
}

int comecofila(fila *f) {
    return f->inicio->dado;
}

void esvazia(fila*f) {
    
}

int filavazia(fila *f) {
    return (f->inicio == NULL);
}

int tamanhofila(fila *f) {
    return f->qtd;
}

void imprimefila(fila *f) {
    int x;
    x = filavazia(f);
    if(x==1) {
        printf("A fila está vazia\n");
        return;
    }
    printf("\n");
    while(f->inicio !=NULL) {
        printf("%d\n",desinfileirar(f));
        }
}
