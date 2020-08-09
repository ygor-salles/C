#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Escreva um programa que leia 3 nome podendo ter espaço e imprima-os */

void preenche (char m[][101], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",m[i]);
    }
    return ;
}

int main ()
{
    int n;
    char matriz[50][101];
    
    preenche (matriz, 10);
    return 0;
}