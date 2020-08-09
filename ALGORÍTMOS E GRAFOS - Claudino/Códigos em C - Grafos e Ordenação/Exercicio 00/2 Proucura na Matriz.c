#include<stdio.h>
#include<stdlib.h>

int proucura(int m, int n, int M[][m], int x)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(M[i][j] == x)
                return 1;

    return -1;
}

int main ()
{
    int m, n, i, j, x, retorna;
    printf("Digite valor de linha e coluna respctivamente: \n");
    scanf("%d",&m); scanf("%d",&n);

    int M[n][m];

    //PROCESSAMENTO
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(i==0 & j==0)
                M[i][j] = 1;
            else
                M[i][j] = M[i][j-1] + 1;

    //IMPRESSÃO
    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<m; j++)
            printf(" %d",M[i][j]);
    }

    printf("\n\nDigite valor de X: "); scanf("%d",&x);
    retorna = proucura(n, m, M, x);
    if(retorna == 1)
        printf("\n\nEncontrado\n\n");
    else
        printf("\n\nNao Encontrado\n\n");

    return 0;
}
