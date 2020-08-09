#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/* Ler duas matrizes A e B de dimensão 5 e elaborar uma matriz C resultante da multiplicação de A por B. */

int main ()
{
    int mA[5][5], mB[5][5], mC[5][5], i, j, k, soma=0;

    printf ("Matriz A\n");
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            mA[i][j] = rand() % 100;
            printf ("%d ",mA[i][j]);
          /*printf ("Digite num [%d][%d]: ",i, j);
            scanf ("%d",&mA[i][j]); */
        }
        printf ("\n");
    }

    printf ("\nMatriz B\n");
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            mB[i][j] = rand() % 100;
            printf ("%d ",mB[i][j]);
          /*printf ("Digite num [%d][%d]: ",i, j);
            scanf ("%d",&mB[i][j]); */
        }
        printf ("\n");
    }

/* Processamento de dados da mC */
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            mC[i][j] = 0;
            for (k=0; k<5; k++){
                soma += mA[i][k] * mB[k][j];
            }
        mC[i][j] = soma;
        soma = 0;
        }
    }

    printf ("\n Matriz C Resultante: \n");
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf ("_%d_|",mC[i][j]);
        }
        printf ("\n");
    }

    return 0;
}

