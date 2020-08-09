#include<stdio.h>

/*1. Elabore um algoritmo que transforme a temperatura fornecida em C para a
correspondente em F (F = 1.8C + 32). Escreva a nova temperatura.*/

int main ()
{
    int c, f;
    printf ("Digite a temperatura em Celsius: ");
    scanf ("%d",&c);
    f = 1.8*c+32;
    printf ("\nA temperatura em farenheit eh: %d\n",f);
    return 0;
}
