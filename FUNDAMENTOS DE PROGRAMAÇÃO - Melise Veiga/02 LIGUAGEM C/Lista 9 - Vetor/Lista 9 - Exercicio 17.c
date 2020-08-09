#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que preencha dois vetores de dez posições cada, determine e mostre um terceiro contendo
os elementos dos dois vetores anteriores ordenados de maneira decrescente. */

int main ()
{
    int vet1[10], vet2[10], conv[20], i, k=0;

    printf ("Vetor 1\n");
    for (i=0; i<=9; i++){
        printf ("Digite num: ");
        scanf ("%d",&vet1[i]);
    }
    printf ("\nVetor 2\n");
    for (i=0; i<=9; i++){
        printf ("Digite num: ");
        scanf ("%d",&vet2[i]);
    }

    for (i=9; i>=0; i--){
        conv[k] = vet2[i];
        k++;
    }
    for (i=9; i>=0; i--){
        conv[k] = vet1[i];
        k++;
    }

    printf ("\nVetor Resultante\n");
    for (i=0; i<k; i++){
        printf (" %d",conv[i]);
    }
    printf ("\n");

    return 0;
}
