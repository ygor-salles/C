#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore um programa que leia uma lista de números inteiros até que um número negativo
seja digitado. Para cada número lido, verificar se o número é divisor de 10 ou não.*/

int main ()
{
    int num;
    printf ("Digite um numero inteiro: ");
    scanf ("%d",&num);
    while (num>0){
        if (num%10==0){
            printf ("\n Eh divisivel por 10 \n");
        }
        else {
            printf ("\n Nao eh divisivel por 10 \n");
        }
        printf ("\nDigite um numero inteiro: ");
        scanf ("%d",&num);
    }
}