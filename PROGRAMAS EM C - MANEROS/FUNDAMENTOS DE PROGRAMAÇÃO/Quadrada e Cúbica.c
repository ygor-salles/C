#include<stdio.h>

/* URI 1143 - Quadrada e Cúbica */ 

int main ()
{
    int n, i, j, k=1;
    printf ("Digite o valor de N: ");
    scanf ("%d",&n);

    int mat[n][n];
    for (i=0; i<n; i++){
        for (j=0; j<3; j++){
            if (j==0){
                mat[i][j] = k;
                printf (" %d",mat[i][j]);
            }
            else{
                mat[i][j] = mat[i][j-1] * k;
                printf (" %d",mat[i][j]);
            }
        }
        printf ("\n");
        k++;
    }

    return 0;
}
