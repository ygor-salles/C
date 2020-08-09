#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila7.h"

struct proc {
    int codigo;
    char tipo;
};

struct n{
    processo dado;
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
    f->fim = novono;
    
     //caso a fila esteja vazia   
    if(f->inicio == NULL) { 
        f->inicio = novono; 
    }
    //caso a fila esteja com nós
    else {
        f->fim->prox = novono; 
    }
    //ajustar a quantidade
    f->qtd ++;
    
    return ;
}

void desinfileirar(fila *f, no *res) {
    no *aux;
    aux = (no*) malloc(sizeof(no));
    aux = f->inicio;
    if(f->inicio != NULL) {
        res->dado->codigo = f->inicio->dado->codigo;
        res-> = f->inicio->dado->tipo;
        res->prox = NULL;
        f->inicio = f->inicio->prox;
    }
    if(f->inicio ==NULL) {
        f->fim = NULL;
    }
    free(aux);
    f->qtd --;
    return ;
}

int comecofila(fila *f) {
    return f->inicio->dado;
}

void esvazia(fila*f) {
    f->inicio == NULL;
    return ;
}

int filavazia(fila *f) {
    return (f->inicio == NULL);
}

int tamanhofila(fila *f) {
    return f->qtd;
}



