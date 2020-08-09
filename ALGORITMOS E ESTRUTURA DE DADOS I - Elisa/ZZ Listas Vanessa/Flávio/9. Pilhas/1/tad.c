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

void preenchepilha(pilha *p) {
    int i, aux;
    printf("\nDigite os valores ordenados de forma decrescente: \n");
    for(i=0; i<5; i++) {
        printf("%d: ", i+1);
        scanf("%d", &aux);
        push(p,aux);
    }
    printf("\n");
    return ;
}

void juntapilha(pilha *p, pilha *n, pilha *q) {
    int aux1, aux2, i;
    
    for(i=0; i<10; i++) {
        aux1 = topo(p);
        aux2 = topo(n);
        
        if(aux1 == -1) {
            push(q,aux2);
            pop(n);
        }
        else if(aux2 == -1) {
            push(q,aux1);
            pop(p);        
        }
        else if(aux1 > aux2) {
            push(q,aux2);
            pop(n);
        }
        else if(aux2 > aux1) {
            push(q,aux1);
            pop(p);
        }
        else if (aux2 == aux1) {
            push(q,aux1);
            pop(p);
        }
    }
}

void imprimepilha(pilha *p) {
    printf("\n\n");
    while(p->topo > -1) {
        printf("%d\n", pop(p));
    }
    printf("\n");
}

int topo(pilha *p) {
    int aux;
    if (p->topo > -1) {
        aux = p->elementos[p->topo];
        return aux;
    } 
    else {
        return -1; 
    }
}