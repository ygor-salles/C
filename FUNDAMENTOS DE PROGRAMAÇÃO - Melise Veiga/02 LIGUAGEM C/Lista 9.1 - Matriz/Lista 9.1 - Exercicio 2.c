#include <stdio.h>

/*Escreva um programa que preencha uma matriz de dimens�o N (N <=10 e deve ser digitado
pelo usu�rio) e retorne a soma dos elementos positivos da matriz.*/

int main ()
{
    int mat[10][10], i, j, soma=0, n;

    printf ("Digite o tamanho da matriz: ");
    scanf ("%d",&n);

    for (i=0; i<n; i++)
        for (j=0; j<n; j++){
            printf ("\nDigite num linha[%d] coluna[%d]: ",i, j);
            scanf (" %d", &mat[i][j]);
        }

    for (i=0; i<n; i++)
        for (j=0; j<n; j++){
            if (mat[i][j]>0){
                soma = soma+mat[i][j];
            }
        }

    printf ("\nA soma dos elementos positivos da matriz eh: %d",soma);
    printf ("\n");

    return 0;
}
