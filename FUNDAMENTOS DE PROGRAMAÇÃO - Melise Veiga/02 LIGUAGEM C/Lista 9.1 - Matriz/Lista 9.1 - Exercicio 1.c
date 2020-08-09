#include<stdio.h>
#include<stdlib.h>

/* Escrever um programa que leia os dados e preencha uma matriz de dimensão 5 x 8 e imprima
os dados digitados. O preenchimento e a impressão dos dados devem ser feitos separados. */

int main ()
{
    int matriz[5][8], i, j;

    for (i=0; i<5; i++){
        for (j=0; j<8; j++){
            printf ("Digite num[%d][%d]: ",i, j);
            scanf ("%d",&matriz[i][j]);
        }
        printf ("\n");
    }

    printf ("Matriz resultante\n\n");
    for (i=0; i<5; i++){
        for (j=0; j<8; j++){
            printf ("_%d_|",matriz[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
