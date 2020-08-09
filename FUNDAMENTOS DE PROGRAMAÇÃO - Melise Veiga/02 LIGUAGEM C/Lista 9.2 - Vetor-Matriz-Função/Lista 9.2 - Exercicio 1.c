#include<stdio.h>
#include<stdlib.h>

/* 1. Elabore uma função que receba um vetor de inteiros e o tamanho do vetor e retorne o vetor com todos os números negativos substituídos por 0. */

void zero (int v[], int i, int n)
{
    for (i=0; i<n; i++){
        if (v[i]<0){
            v[i] = 0;
        }
    }
    return ;
}

int main ()
{
    int n, i;
    printf ("Digite o valor de N: ");
    scanf ("%d",&n);
    int v[n];

    for (i=0; i<n; i++){
        printf ("Digite num: ");
        scanf ("%d",&v[i]);
    }

    zero (v, i, n);
    printf ("\nValores trocados:\n");
    for (i=0; i<n; i++){
        printf (" %d",v[i]);
    }
    printf ("\n");

    return 0;
}
