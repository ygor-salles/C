#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*2. Elabore uma função que receba uma matriz de nome (tamanho máximo de cada nome = 50)
e um nome (tamanho máximo = 50) e retorne 1 se o nome estiver na matriz e 0, caso contrário. */

void funcao (char mat[][51], char nome[], int n, int *semafaro);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, n, semafaro;
    printf ("Digite a quantidade de nomes: ");
    scanf ("%d",&n);

    char mat[n][51], nome[51];
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",mat[i]);
    }

    printf ("\nDigite um nome para comparação: ");
    scanf (" %[^\n]",nome);

    funcao(mat, nome, n, &semafaro);
    printf ("\n%d\n",semafaro);
    return 0;
}

void funcao (char mat[][51], char nome[], int n, int *semafaro)
{
    int i;
    *semafaro=0;
    for (i=0; i<n; i++){
       if (strcmp(mat[i],nome)==0){
        *semafaro = 1;
       }
    }
    return ;
}
