#include<stdio.h>
#include<stdlib.h>

/* Ler uma matriz quadrada A de dimensão M (M <= 10) de elementos inteiros. Em seguida, obter seu elemento minimax.
O minimax é o menor elemento da linha que contém o maior elemento da matriz. */

int main ()
{
    int matriz[10][10], i, j, m, linha, maior, minmax;

    printf ("Digite o valor de M: ");
    scanf ("%d",&m);
    printf ("\n");

    for (i=0; i<m; i++){
        for (j=0; j<m; j++){
            printf ("Digite num linha[%d]coluna[%d]: ",i, j);
            scanf ("%d",&matriz[i][j]);
        }
        printf ("\n");
    }

    maior = matriz[0][0];
    for (i=0; i<m; i++){
        for (j=0; j<m; j++){
            if (matriz[i][j] > maior){
                maior = matriz[i][j];
                linha = i;
            }
        }
    }

    minmax = matriz[linha][0];
    for (j=0; j<m; j++){
        if (matriz[linha][j] < minmax){
            minmax = matriz[linha][j];
        }
    }

    printf ("\n O valor do minmax eh: %d, linha %d\n",minmax, linha);

    return 0;
}
