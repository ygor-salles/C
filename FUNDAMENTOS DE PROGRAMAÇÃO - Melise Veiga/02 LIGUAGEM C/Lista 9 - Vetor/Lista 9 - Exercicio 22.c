#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que leia um vetor A de dez posições. Em seguida, compacte o vetor, retirando os
valores nulos e negativos. Armazene esse resultado no vetor B. Mostre o vetor B. (Lembre-se: o vetor B
pode não ser completamente preenchido.) */

int main ()
{
    int vet[10], res[10], i, k=0;

    for(i=0; i<10; i++){
        printf ("Digite num: ");
        scanf ("%d",&vet[i]);
        if (vet[i]>0){
            res[k] = vet[i];
            k++;
        }
    }

    printf ("\nVetor de positivos nao nulos\n");
    for (i=0; i<k; i++){
        printf (" %d",res[i]);
    }
    printf ("\n");
    return 0;
}
