#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

struct complexo
{
    float a, b, c, d;
};

Complexo *criar(float a, float b, float c, float d)
{
    Complexo *dados;
    dados = (Complexo*) malloc(sizeof(Complexo));
    if (!dados){
        printf ("MEMORIA INSUFICIENTE");
        exit(1);
    }
    dados->a = a;
    dados->b = b;
    dados->c = c;
    dados->d = d;

    return dados;
}

void somar (float *x, float *y, Complexo *dados)
{
    *x =(dados->a + dados->c);
    *y =(dados->b + dados->d);

    return ;
}

void subtrair (float *x, float *y, Complexo *dados)
{
    *x =(dados->a - dados->c);
    *y =(dados->b - dados->d);

    return ;
}

void multiplicar (float *x, float *y, Complexo *dados)
{
    *x =(dados->a*dados->c - dados->b*dados->d);
    *y =(dados->b*dados->c + dados->a*dados->d);

    return ;
}

void dividir (float *x, float *y, Complexo *dados)
{
    *x =((dados->a*dados->c + dados->b*dados->d)/(dados->c*dados->c + dados->d*dados->d));
    *y =((dados->b*dados->c - dados->a*dados->d)/(dados->c*dados->c + dados->d*dados->d));

    return ;
}

void liberar (Complexo *dados)
{
    free(dados);
    return ;
}
