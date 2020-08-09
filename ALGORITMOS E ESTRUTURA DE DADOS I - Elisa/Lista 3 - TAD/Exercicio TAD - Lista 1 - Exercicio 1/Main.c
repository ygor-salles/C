#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "tad.h"

/* Lista 1 - Exercicio 1 com TAD, Aloca��o Dinamica, Struct, Ponteiro e Fun��o Retorna Valor */

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    Habitantes *h;

    printf ("Digite a quantidade de habitantes: ");
    scanf ("%d",&n);

    //Aloca Dinamicamente
    h = aloca(n);

    //Fun��o A
    funcaoA (n, h);

    //Fun��o B - Ponteiro
    float media=0;
    funcaoB (n, h, &media);
    printf ("\nA media de idade das pessoas com olhos castanhos e cabelos pretos �: %.2f\n",media);

    //Fun��o C - Retorna Valor
    int maior_idade;
    maior_idade = funcaoC (n, h);
    printf ("\nA maior idade entre os habitantes �: %d\n",maior_idade);

    //Fun��o D
    int individuo=0;
    funcaoD (n, h, &individuo);
    printf ("\n%d Indiv�duo(s) do sexo feminino com idade entre 18 e 35 anos (inclusive) e que possuem olhos azuis e cabelos louros\n",individuo);

    //Fun��o E
    int i, j, **mat;
    mat = (int**) malloc(n*sizeof(int*));
    if (!mat){
        printf ("MEMORIA INSUFICIENTE");
        exit(1);
    }
    for (i=0; i<n; i++){
        mat[i] = (int*) malloc(n*sizeof(int));
        if (!mat[i]){
            printf ("MEMORIA INSUFICIENTE");
            exit(1);
        }
    }
    funcaoE (n, h, mat);
    printf ("\nMATRIZ: \n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf ("_%d_|",mat[i][j]);
        }
        printf ("\n");
    }

    free(h);
    for (i=0; i<n; i++)
        free(mat[i]);
    free(mat);
    return 0;
}
