#include<stdio.h>
#include<math.h>

/* 8. Faça um algoritmo que receba o peso de uma pessoa, calcule e mostre:
a. O novo peso quando a pessoa engorda 15% do peso digitado
b. O novo peso quando a pessoa engorda 20% do peso digitado */

int main ()
{
    float peso;
    printf ("Digite o seu peso: ");
    scanf ("%f",&peso);

    printf ("\nO novo peso quando engorda 15 porcento eh: %.2f",peso+(peso*0.15));
    printf ("\nO novo peso quando engorda 20 porcento eh: %.2f\n",peso+(peso*0.20));
    return 0;
}
