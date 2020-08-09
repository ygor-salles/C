#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

struct pil {
    int elemento[tammax];
    int topo ;
};

pilha *criapilha() {
    pilha *p;
    p = (pilha*) malloc(sizeof(pilha));
    if (!p) {
        printf("Erro ao alocar a pilha\n");
        exit (1);
    }
    p->topo = -1;
    return p;
}

void push(pilha *p, int elemento) {
    p->topo ++;
    if (p->topo < tammax) {
        p->elemento[p->topo] = elemento;
    }
    else {
        printf("\nA pilha está cheia\n");
    }
    return ;
}

int pop(pilha *p) {
    int aux;
    if (p->topo > -1) {
        aux = p->elemento[p->topo];
        p->topo --;
        return aux;
    }
    else {
        printf("\nA pilha está vazia\n");
        exit(1);
    }
    
}

void divisao(pilha *p, int d) {
    if (d==0) {
        push(p,0);
    }
    while (d!=0) {
        push(p,(d%2));
        
        if(d==0) {
            break;
        }
        d=d/2;
    }  
    return ;
}

void imprime (pilha* p) {
    int aux;
    printf("\nNúmero binário: ");
    while(p->topo > -1) {
        printf("%d", pop(p));
    }
    printf("\n");
}