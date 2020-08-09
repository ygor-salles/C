#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

struct habitantes
{
    char sexo, olho, cabelo;
    int idade;
};

Habitantes *aloca(int n)
{
    Habitantes *h;
    h = (Habitantes*) malloc(n*sizeof(Habitantes));
    if (!h){
        printf ("MEMORIA INSUFICIENTE");
        exit(1);
    }
    return h;
}

void funcaoA (int n, Habitantes *h)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite o sexo(F/M): ");
        scanf (" %c",&h[i].sexo);
        printf ("Digite a cor dos olhos(A/C): ");
        scanf (" %c",&h[i].olho);
        printf ("Digite a cor do cabelo(L/P/C): ");
        scanf (" %c",&h[i].cabelo);
        printf ("Digite a idade: ");
        scanf ("%d",&h[i].idade);
        printf ("\n");
    }
    return ;
}

void funcaoB (int n, Habitantes *h, float *media)
{
    int cont=0, i;
    for (i=0; i<n; i++){
        if ((h[i].olho=='c' || h[i].olho=='C') && (h[i].cabelo=='p' || h[i].cabelo=='P')){
            *media = *media+h[i].idade;
            cont++;
        }
    }
    if (cont>0)
        *media = *media/(float)cont;
    else
        *media = 0;

    return ;
}

int funcaoC (int n, Habitantes *h)
{
    int i, maior_idade;
    maior_idade = h[0].idade;
    for (i=0; i<n; i++)
        if (i>0)
            if (h[i].idade > maior_idade)
                maior_idade = h[i].idade;

    return maior_idade;
}

void funcaoD (int n, Habitantes *h, int *individuo)
{
    int i;
    for (i=0; i<n; i++)
        if ((h[i].sexo=='f' || h[i].sexo=='F') && (h[i].idade>=18 && h[i].idade<=35) && (h[i].olho=='a' || h[i].olho=='A') && (h[i].cabelo=='l' || h[i].cabelo=='L'))
            ++(*individuo);
    return ;
}

void funcaoE (int n, Habitantes *h, int **mat)
{
    int j, i;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++){
            if (i == j)
                mat[i][j] = h[i].idade;
            else
                mat[i][j] = 0;
        }

    return ;
}
