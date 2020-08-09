#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que leia um vetor com quinze posições para números inteiros. Crie, a seguir, um vetor
resultante que contenha todos os números primos do vetor digitado. Escreva o vetor resultante. */

int main ()
{
    int vet[15], primo[15], i, j, c, k=0;

    for (i=0; i<15; i++){
        printf ("Digite num: ");
        scanf ("%d",&vet[i]);
    }

    for (i=0; i<15; i++){
        c=0;
        for (j=1; j<=vet[i]; j++){
            if (vet[i]%j==0){
                c++;
            }
        }
        if (c==2){
            primo[k] = vet[i];
            k++;
        }
    }

    printf ("\nVetor de Primos: \n");
    for (i=0; i<k; i++){
        printf (" %d",primo[i]);
    }
    printf ("\n");

    return 0;
}
