#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilhaenc.h"

struct n{
    int dado;
    no *prox;
};

struct pil{
    no *topo;
};

pilha *criaPilha() {
    pilha *p;
    p = (pilha*) malloc(sizeof(pilha));
    if (!p) {
        printf("Erro ao alocar a memória\n");
        exit(1);
    }
    p->topo = NULL;
    return p;
}

void push(pilha *p, int elemento) {
    no *novoNo;
    novoNo = (no*) malloc(sizeof(no));
    //iniciarlizar o nó
    novoNo->dado = elemento;
    novoNo->prox = p->topo;
    //atualizar o topo da pilha
    p->topo = novoNo;
    return ;
}

int pop(pilha *p) {
    no *noAux;
    int res = -1;
    if(p->topo !=NULL) {// a pilha não está vazia 
        noAux = p->topo;
        res = p->topo->dado;
        p->topo = p->topo->prox;
        free(noAux);
    }
    return res;
}

int topo(pilha *p) {
    int res = -1;
    if(p->topo !=NULL){ //a pilha não está vazia
        res = p->topo->dado;
    }
    return res;
}

void esvazia(pilha *p) {
    no *noAux;
    while (p->topo !=NULL) {
        noAux = p->topo;
        p->topo = p->topo->prox;
        free(noAux);
    }
    return;
}

void esvaziaRetornando(pilha *p) {
    no *noAux;
    int res = -1;
    if(p->topo !=NULL) {// a pilha não está vazia 
        noAux = p->topo;
        res = p->topo->dado;
        p->topo = p->topo->prox;
        free(noAux);
    }
    printf("%d\n", res);
}

int pilhaVazia(pilha *p) {
    return (p->topo == NULL);
}
