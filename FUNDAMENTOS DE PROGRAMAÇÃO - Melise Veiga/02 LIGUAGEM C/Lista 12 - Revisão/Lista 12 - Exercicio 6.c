#include<stdio.h>
#include<stdlib.h>

/* 6. Escreva um programa que leia uma matriz quadrada A de números inteiros (ordem n <
10, n deve ser fornecido pelo usuário) e imprima a matriz Media utilizando as funções
das questões 3 e 4. */

void retorna_matriz_media(int n, int a[][n], float media[][n])
{
    int i, j;
    float med;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            if (j==0 && i==0)
                med = (float)(a[i][j+1] + a[i+1][j]) / 2;
            else if (j==0 && i==n-1)
                med = (float)(a[i][j+1] + a[i-1][j]) / 2;
            else if (j==0)
                med = (float)(a[i-1][j] + a[i][j+1] + a[i+1][j]) / 3;

            else if (j==n-1 && i==0)
                med = (float)(a[i][j-1] + a[i+1][j]) / 2;
            else if (j==n-1 && i==n-1)
                med = (float)(a[i-1][j] + a[i][j-1]) / 2;
            else if (j==n-1)
                med = (float)(a[i-1][j] + a[j-1][i] + a[i+1][j]) / 3;

            else if (i==0)
                med = (float)(a[i][j-1] + a[i+1][j] + a[i][j+1]) / 3;
            else if (i==n-1)
                med = (float)(a[i][j-1] + a[i-1][j] + a[i][j+1]) / 3;

            else
                med = (float)(a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1]) / 4;

            media[i][j] = med;
        }

    return ;
}

int main ()
{
    int n, i, j;

    printf ("\nDigite o tamanho da matriz: "); scanf("%d",&n);
    if (n>=10) return 0;
    int a[n][n];
    float media[n][n];

    printf ("\nPreencha a matriz %dx%d: \n",n, n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            printf ("[%d][%d]: ",i,j); scanf("%d",&a[i][j]);
        }

    printf("\nConfira os dados digitados\n");
    system("pause");
    system("CLS");

    printf ("\nMATRIZ: \n\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf ("_%d_|",a[i][j]);
        printf ("\n");
    }

    retorna_matriz_media(n, a, media);

    printf ("\nA matriz media eh: \n\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf ("_%.2f_|",media[i][j]);
        printf ("\n");
    }

    return 0;
}
