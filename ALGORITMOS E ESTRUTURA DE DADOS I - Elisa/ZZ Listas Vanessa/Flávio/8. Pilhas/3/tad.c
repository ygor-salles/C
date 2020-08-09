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

void pop(pilha *p) {
    if (p->topo > -1) {
        p->topo--;
    } else {
        printf("\nPilha vazia\n");
    }
}

void preenche(pilha *p, pilha *n) {
    int i, aux;
    for(i=0; i<10; i++) {
        printf("Digite um número: ");
        scanf("%d", &aux);
        if (aux>0) {
            push(p,aux);
        }
        else if(aux<0) {
            push(n,aux);
        }
        else if(aux==0) {
            pop(p);
            pop(n);
        }
    }
}

void imprime(pilha *p, pilha *n) {
    int aux;
    printf("\nPilha P: \n");
    while(p->topo > -1) {
        printf("%d\n", p->elementos[p->topo]);
        pop(p);
    }
    printf("\n");
    printf("Pilha N: \n");
    while(n->topo > -1) {
        printf("%d\n",n->elementos[n->topo]);
        pop(n);
    }
    printf("\n");    
}
