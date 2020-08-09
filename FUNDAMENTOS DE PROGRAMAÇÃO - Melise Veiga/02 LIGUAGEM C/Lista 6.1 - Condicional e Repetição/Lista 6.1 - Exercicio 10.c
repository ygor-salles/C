#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore um programa em C que calcule e imprima o somatório expresso pela seguinte série:

     500     480     460            20
S = ----- + ----- + ------ + ... + ----
      2       3       4             26     */

int main ()
{
    float soma=0, den, num=500;

    for (den=2; den<=26; den++){
        soma=soma+(num/den);
        num=num-20;
    }
    printf ("\n\n A soma da serie eh: %.2f\n\n",soma);
    return 0;
}
