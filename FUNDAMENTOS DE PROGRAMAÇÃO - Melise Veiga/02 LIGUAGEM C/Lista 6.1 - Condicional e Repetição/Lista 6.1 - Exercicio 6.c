#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Elabore um programa que leia dois números n e m (m>=n) e escreva todos os números
pares entre n e m.*/

int main ()
{
    int n, m, i;
    printf ("Digite o valor de N: ");
    scanf (" %d",&n);
    printf ("DIgite o valor de M: ");
    scanf (" %d",&m);
    if (m>=n){
    for (i=n; i<=m; i++){
        if (i%2==0) {
            printf ("\n %d\n",i);
        }
    }
    }
}
