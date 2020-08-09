#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Faça um programa que mostre as tabuadas completas de 1 à 10 */

int main ()
{
    int i, c, tabuada;
    printf ("O programa exibira a tabuada completa de 1 a 10 \n");

    for (i=1; i<=10; i++){
        tabuada=0;
        for (c=1; c<=10; c++){
            tabuada=i*c;
            printf ("\n %d x %d = %d\n", i, c, tabuada);
        }
    }
    return 0;
}
