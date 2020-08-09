#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que preencha um vetor com dez números reais, calcule e mostre a quantidade de números
negativos e a soma dos números positivos desse vetor. */

int main ()
{
    float vet[10], somador;
    int i, cont=0;

    for (i=0; i<10; i++){
        printf ("Digite um numero: ");
        scanf ("%f",&vet[i]);
    }

    for (i=0; i<10; i++){
        if (vet[i]<0){
            cont++;
        }
        else{
            somador = somador+vet[i];
        }
    }
    printf ("\nA quantidade de numeros negativos do vetor eh: %d",cont);
    printf ("\nO somatorio dos numeros positivos do vetor eh: %.2f\n",somador);
    return 0;
}
