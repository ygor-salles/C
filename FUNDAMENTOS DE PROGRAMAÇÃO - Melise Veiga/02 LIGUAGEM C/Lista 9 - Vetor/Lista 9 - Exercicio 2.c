#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que preencha um vetor com sete n�meros inteiros, calcule e mostre:
� os n�meros m�ltiplos de 2;
� os n�meros m�ltiplos de 3;
� os n�meros m�ltiplos de 2 e de 3. */

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
