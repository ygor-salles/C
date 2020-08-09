#include <stdio.h>
#include<stdlib.h>

/* Escreva um programa que leia uma matriz 5 x 5 e imprima sua diagonal secund�ria.
Na �lgebra linear, os �ndices (i,j) dos elementos da diagonal secund�ria de uma matriz NxN
apresentam o seguinte comportamento: i+j=N+1. Voce pode usar esta regra para resolver o
problema. Contudo, em C, os �ndices iniciam em 0 e, na �lgebra linear, os �ndices come�am
com1. Logo, voc� dever� fazer as adapta��es necess�rias para adequar os valores dos �ndices
em uma matriz em C.*/

int main ()
{
	int matriz [5][5], n, i, j;

	printf ("Digite o valor de N <= 5: ");
	scanf ("%d",&n);

    if (n<=0 || n>5){
        printf ("\nDados incorretos!\n");
    }
    else{
        printf ("\nDigite os numeros da matriz: \n");
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                scanf ("%d", &matriz[i][j]);
            }
        }

        printf ("\nMatriz dos numeros digitados: \n");
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                printf ("_%d_|", matriz[i][j]);
            }
            printf ("\n");
        }

        printf ("\nDiagonal Primaria: \n");
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                if (j == i){
                    printf ("%d ", matriz[i][j]);
                }
            }
        }

        printf ("\n\nDiagonal Secundaria: \n");
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                if (j == (n-1-i)){
                    printf ("%d ", matriz[i][j]);
                }
            }
        }
        printf ("\n");
    }
    return 0;
}