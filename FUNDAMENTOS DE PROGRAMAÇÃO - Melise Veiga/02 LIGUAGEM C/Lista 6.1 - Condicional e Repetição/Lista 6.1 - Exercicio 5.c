#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore um programa que leia um n�mero inteiro n e escreva todos os n�meros inteiros
entre 1 e este n�mero (inclusive).*/

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
