#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Elabore um programa em C que calcule e imprima a seguinte soma:
     1     3     5     7           99
S = --- + --- + --- + --- + ... + ----
     1     2     3     4           50  */

int main ()
{
    float den, num=1, soma=0;

    for (den=1; den<=50; den++){
        soma=soma+(num/den);
        num=num+2;
    }
    printf ("\n\n A soma eh: %f\n\n",soma);
    return 0;
}
