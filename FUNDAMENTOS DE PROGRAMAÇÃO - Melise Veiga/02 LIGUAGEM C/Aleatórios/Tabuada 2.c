#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* Fa�a um programa que receb um n�mero e que calcule a tabuada desse numero */

int main ()
{
    int tabuada, i, num;

    printf ("Digite um numero para o calculo da tabuada: ");
    scanf ("%d",&num);

    for (i=1; i<=10; i++){
        tabuada=num*i;
        printf ("\n %d x %d = %d\n", num, i, tabuada);
    }
    return 0;
}
