#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*1. Elabore programa que preencha uma matriz de nomes contendo dois nomes com no máximo 50 caracteres.
Imprima os nomes digitados a partir da leitura da matriz. */

int main ()
{
    char nome[2][51];
    int i;

    for (i=0; i<2; i++){
        printf ("Digite nome: ");
        gets(nome[i]);
    }

    for (i=0; i<2; i++)
        printf (" %s",nome[i]);

    return 0;
}
