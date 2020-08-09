#include<stdio.h>

/*3. Escreva um algoritmo que receba dois inteiros, A e B, e realize a troca destes
valores. Mostrar o novo valor de A e de B depois de trocados.*/

int main ()
{
    int a, b, aux;
    printf ("Digite valor de A: ");
    scanf ("%d",&a);
    printf ("Digite valor de B: ");
    scanf ("%d",&b);
    aux = a;
    a = b;
    b = aux;
    printf ("\nValor de A: %d | Valor de B: %d\n",a, b);
    return 0;
}

