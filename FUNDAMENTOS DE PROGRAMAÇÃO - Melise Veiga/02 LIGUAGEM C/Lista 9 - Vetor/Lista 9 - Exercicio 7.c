#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que preencha um vetor com dez n�meros reais, calcule e mostre a quantidade de n�meros
negativos e a soma dos n�meros positivos desse vetor. */

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
