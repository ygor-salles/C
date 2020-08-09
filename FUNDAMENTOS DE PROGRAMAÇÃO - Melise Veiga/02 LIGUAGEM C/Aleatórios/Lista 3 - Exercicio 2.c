#include <stdio.h>

//Elabore um algoritmo que receba dois valores e troque seus valores entre si.

int main ()
{
    int a, b, aux;
    printf ("Digite o valor de A e B: \n");
    scanf ("%d %d", &a, &b);

    aux=b;
    b=a;
    a=aux;

    printf ("\nO valor de A eh %d e B %d\n",a,b);
}
