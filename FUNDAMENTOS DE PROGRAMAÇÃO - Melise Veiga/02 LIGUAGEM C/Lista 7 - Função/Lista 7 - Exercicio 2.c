#include<stdio.h>

/* Fa�a uma fun��o que receba 2 valores inteiros e imprima-os de forma
ordenada. Utilize a fun��o no programa principal */

void ordena (int a, int b)
{
    if (a>b)
        printf ("\n %d %d \n", b, a);
    else
        printf ("\n %d %d \n", a, b);
}

int main ()
{
    int a, b;
    printf ("Digite o valor de A e B: \n");
    scanf ("%d %d", &a, &b);
    ordena (a, b);
}