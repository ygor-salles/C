#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que preencha um vetor com sete números inteiros, calcule e mostre:
º os números múltiplos de 2;
º os números múltiplos de 3;
º os números múltiplos de 2 e de 3. */

int main ()
{
    int vet[7], i;

    for (i=0; i<7; i++){
        printf ("Digite numero: ");
        scanf ("%d",&vet[i]);
    }

    printf ("\nMult 2 e 3 | Mult 2| Mult 3\n");
    for (i=0; i<7; i++){
        if (vet[i]%2==0 && vet[i]%3==0){
            printf ("\n%5d ",vet[i]);
        }
        if (vet[i]%2 == 0){
            printf ("\n%16d",vet[i]);
        }
        if (vet[i]%3 == 0){
            printf ("\n%25d",vet[i]);
        }
    }
    printf ("\n");
    return 0;
}
