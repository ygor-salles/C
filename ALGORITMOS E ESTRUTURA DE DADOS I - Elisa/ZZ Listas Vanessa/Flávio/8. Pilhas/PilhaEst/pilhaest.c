#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilhaest.h"

struct pilhaa {
    int arranjo[tamMax];
    int topo;
};

pilha *criapilha() {
    pilha *p;
    p = (pilha*) malloc(sizeof (pilha));
    if (!p) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    p->topo = -1;
    return p;
}

void push(pilha *p, int elemento) {
    p->topo++;
    if (p->topo < tamMax) {
        p->arranjo[p->topo] = elemento;
    } else {
        printf("\nPilha Cheia\n");
    }
    return;
}

int pop(pilha *p) {
    int aux;
    if (p->topo > -1) {
        aux = p->arranjo[p->topo];
        p->topo--;
        return aux;
    } else {
        printf("\nPilha vazia\n");
    }
}

int topo(pilha *p) {
    int aux;
    if (p->topo > -1) {
        aux = p->arranjo[p->topo];
        return aux;
    } else {
        printf("\nPilha vazia\n");
    }
}

void esvazia(pilha *p) {
    p->topo = -1;
    return ;
}

void esvaziaretornando(pilha *p){
    while(p->topo >-1) {
        printf("%d\n", pop(p));
    }
    return ;
}

int pilhavazia(pilha *p) {
    if (p->topo == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int pilhacheia(pilha *p) {
        if (p->topo == tamMax) {
        return 1;
    }
    else {
        return 0;
    }
}