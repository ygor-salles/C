#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore um programa que leia um número inteiro n e escreva todos os números inteiros
entre 1 e este número (inclusive).*/

int main ()
{
    int n, i;
    printf ("Digite um valor inteiro para N: ");
    scanf ("%d",&n);
    for (i=1; i<=n; i++){
        printf ("\n %d\n",i);
    }
    return 0;
}
