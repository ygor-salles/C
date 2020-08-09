#include <stdio.h>
#include <stdlib.h>

/*2. Elabore um programa que leia o código e a quantidade em estoque de 10 produtos e armazene
esses dados em uma matriz. Depois de preenchida a matriz, imprima a quantidade total de
produtos e o código de todos os produtos com quantidade maior que 10.*/

int main ()
{
    int mat[10][2], i, k=0, soma=0, res[10];

        for (i=0; i<10; i++){
            printf ("Digite cod: ");
            scanf ("%d",&mat[i][0]);
            printf ("Digite quantidade: ");
            scanf ("%d",&mat[i][1]);
        }

        for (i=0; i<10; i++){
            soma = soma + mat[i][1];
            if (mat[i][1]>10){
                res[k] = mat[i][0];
                k++;
            }
        }

    printf ("\nA quantidade total de produtos eh: %d\n",soma);

    printf ("\nCodigo de todos produtos com a quantidade maior que 10: \n");
    for (i=0; i<k; i++){
        printf (" %d",res[i]);
    }
    printf ("\n");
    return 0;
}
