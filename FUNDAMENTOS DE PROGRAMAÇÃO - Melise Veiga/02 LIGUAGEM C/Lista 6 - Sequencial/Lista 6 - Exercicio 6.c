#include<stdio.h>

/* 6. Escreva um algoritmo para calcular e exibir a média ponderada de 2 notas dadas.
(nota 1 tem peso 6 e nota 2 tem peso 4) */

int main ()
{
    float n1, n2, media;
    printf ("Digite a N1: ");
    scanf ("%f",&n1);
    printf ("Digite a N2: ");
    scanf ("%f",&n2);

    media = (n1*6+n2*4)/10;

    printf ("\nA media eh: %.1f\n",media);
}
