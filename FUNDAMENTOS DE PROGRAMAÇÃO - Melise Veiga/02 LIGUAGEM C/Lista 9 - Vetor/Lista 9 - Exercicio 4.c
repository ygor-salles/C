#include<stdio.h>
#include<stdlib.h>

/*Fa�a um programa que preencha um vetor com quinze elementos inteiros e verifique a exist�ncia de elementos
iguais a 30, mostrando as posi��es em que apareceram. */ 

int main ()
{
    int vet[15], i;

    for (i=0; i<15; i++){
        printf ("Digite numero: ");
        scanf ("%d",&vet[i]);
    }

    printf ("\n POSICAO : VETOR=30 \n");
    for (i=0; i<15; i++){
        if (vet[i] == 30){
            printf ("\n    %d   :    %d   \n",i, vet[i]);
        }
    }
    return 0;
}
