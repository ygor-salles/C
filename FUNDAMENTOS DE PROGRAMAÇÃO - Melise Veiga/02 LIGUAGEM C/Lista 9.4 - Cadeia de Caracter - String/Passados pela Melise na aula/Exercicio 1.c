#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Escreva um programa que leia 3 nome podendo ter espaço e imprima-os */

int main ()
{
    char nomes[3][11];
    int i;

    for (i=0; i<3; i++){
        printf ("Digite o nome: ");
        scanf (" %[^\n]",nomes[i]);
    }

    for (i=0; i<3; i++){
        printf (" %s",nomes[i]);
    }

    return 0;
}
