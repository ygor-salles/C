#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que preencha um vetor com seis elementos numéricos inteiros. Calcule e mostre:
º todos os números pares;
ºa quantidade de números pares; 
º todos os números ímpares;
º a quantidade de números ímpares. */

int main ()
{
    int vet[6], i, c1=0, c2=0;

    for (i=0; i<6; i++){
        printf ("Digite num: ");
        scanf ("%d",&vet[i]);
    }

    for (i=0; i<6; i++){
        if (vet[i] % 2 == 0){
            c1++;
            printf ("\nPar: %d",vet[i]);
        }
        else{
            c2++;
            printf ("\nImpar: %d",vet[i]);
        }
    }
    printf ("\n\nA quantidade de numeros pares eh %d e impares eh %d",c1, c2);
    return 0;
}
