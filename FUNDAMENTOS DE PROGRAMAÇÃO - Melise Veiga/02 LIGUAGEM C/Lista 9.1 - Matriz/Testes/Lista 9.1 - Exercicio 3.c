#include <stdio.h>
#include <stdlib.h>

/*2. Elabore um programa que leia o código e a quantidade em estoque de 10 produtos e armazene
esses dados em uma matriz. Depois de preenchida a matriz, imprima a quantidade total de
produtos e o código de todos os produtos com quantidade maior que 10.*/

int main ()
{
    int mat[2][10], i, j, semafaro=0, k=0, soma=0, res[10];

    for (i=0; i<2; i++){
        if (semafaro == 1){
            printf ("\nDigite qtd: \n");
        }else{
        printf ("Digite cod: \n");
        }
        for (j=0; j<10; j++){
            scanf ("%d",&mat[i][j]);
        }
        semafaro=1;
    }

        for (j=0; j<10; j++){
            soma = soma + mat[1][j];
            if (mat[1][j]>10){
                res[k] = mat[0][j];
                k++;
            }
        }

    printf ("\nA quantidade total de produtos eh: %d\n",soma);

    printf ("\nCodigo de todos produtos com a quantidade maior que 10: \n");
    for (i=0; i<k; i++){
        printf (" %d",res[i]);
    }
    return 0;
}
