#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore um programa que leia uma lista de n�meros inteiros at� que um n�mero negativo
seja digitado. Para cada n�mero lido, verificar se o n�mero � divisor de 10 ou n�o.*/

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