#include<stdio.h>
#include<math.h>

/* 7. Escreva um algoritmo para calcular e exibir o comprimento de uma circunfer�ncia,
sendo dado o valor de seu raio. Considere que o raio fornecido ser� sempre maior
que 0.

C = 2 (p) R */

int main ()
{
    float c, r, pi=3.14159265;
    printf ("Digite o valor do Raio: ");
    scanf ("%f",&r);

    c = 2 * pi * r;

    printf ("\nO valor da circunferencia eh: %.2f\n",c);
}
