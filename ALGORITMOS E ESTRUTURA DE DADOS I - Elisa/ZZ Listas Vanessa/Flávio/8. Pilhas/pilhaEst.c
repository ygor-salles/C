#include <stdio.h>
#include <stdlib.h>
#include "pilhaEst.h"


struct pilha{
    int arranjo[tamMax];
    int topo;
};

pilha *criaPilha()
{
    pilha *p;
    p = (pilha*)malloc(sizeof(pilha));
    if(!p)
    {
        printf("erro ao alocar memoria\n");
        exit(1);
    }
    p->topo = -1;
    return p;
}

void push(pilha *p, int elemento)
{
    if(p->topo < tamMax -1)
    {
        p->topo = p->topo + 1;
        p->arranjo[p->topo] = elemento;
    }
    else
    {
        printf("\nPilha Cheia\n");
    }
    return;
}

int pop(pilha *p)
{
    int aux;
    if (p->topo > -1)
    {
        aux = p->arranjo[p->topo];
        p->topo = p->topo - 1;
        return aux;
    }
    else
    {
        printf("\nPilha Vazia\n");
    }
}

int topo(pilha *p)
{
    if (p->topo > -1)
    {
        return (p->arranjo[p->topo]);
    }
    else
    {
        printf("\nPilha Vazia\n");
    }
}

void esvaziaRetornando(pilha *p)
{
    while(p->topo > -1)
    {
        printf("%d\n", pop(p));
    }
    return;
}

void esvazia(pilha *p)
{
    p->topo = -1;
    return;
}

int pilhaVazia(pilha *p)
{
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int pilhaCheia(pilha *p)
{
    if (p->topo == tamMax - 1)
        return 1;
    else
        return 0;
}

