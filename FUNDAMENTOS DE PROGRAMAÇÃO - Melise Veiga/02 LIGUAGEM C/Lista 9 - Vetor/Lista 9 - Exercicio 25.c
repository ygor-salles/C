#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que leia um vetor com quinze posi��es para n�meros inteiros. Depois da leitura, divida
todos os seus elementos pelo maior valor do vetor. Mostre o vetor ap�s os c�lculos. */

int main ()
{
    int i;
    float vet[15], maior;

    for (i=0; i<15; i++){
        printf ("Digite num: ");
        scanf ("%f",&vet[i]);
    }

    maior = vet[0];
    for (i=1; i<15; i++){
        if (vet[i]>maior){
            maior = vet[i];
        }
    }

    printf ("\nVetor apos a divisao pelo elemento maior\n");
    for (i=0; i<15; i++){
        vet[i] = vet[i]/maior;
        printf ("\n%.2f",vet[i]);
    }
    printf ("\n");
    
    return 0;
}
