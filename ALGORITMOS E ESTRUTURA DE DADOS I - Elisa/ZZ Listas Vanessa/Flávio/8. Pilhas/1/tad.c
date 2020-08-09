#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

struct pil {
    int topo;
    int elementos[tammax];
};

pilha *criapilha() {
    pilha *p;
    p = (pilha*) malloc(sizeof (pilha));
    if (!p) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    p->topo = -1;
    return p;
}

void push(pilha *p, int elemento) {
    p->topo++;
    if (p->topo < tammax) {
        p->elementos[p->topo] = elemento;
    } else {
        printf("\nPilha cheia\n");
    }
    return;
}

int pop(pilha *p) {
    int aux;
    if (p->topo > -1) {
        aux = p->elementos[p->topo];
        p->topo--;
        return aux;
    } else {
        printf("\nPilha vazia\n");
    }
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
    if (p->topo == tammax) {
        return 1;
    }
    else {
        return 0;
    }
}

int top(pilha *p) {
    int aux;
    if (p->topo > -1) {
        aux = p->elementos[p->topo];
        return aux;
    }
    else {
        printf("\nPilha vazia\n");
    }
}

void listadados(pilha *p) {
    int aux;
    if (p->topo == -1) {
        printf("\nPilha vazia\n");
    }
    while(p->topo > -1) {
        aux = pop(p);
        printf("%d\n", aux);
    }
}


