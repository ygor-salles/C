#include<stdio.h>
#include<stdlib.h>

/* 4. Escreva uma função que recebe como parâmetros uma matriz quadrada A de números inteiros (ordem n < 10),
uma posição [i][j] da matriz, e calcule a média aritmética dos vizinhos de A[i][j], ou seja,
a média entre A[i-1][j], A[i+1][j],A[i][j+1], A[i][j+1]
Desconsidere os vizinhos que não pertencem a matriz (por exemplo, os vizinhos de (0, 0) são somente (0,1) e (1,0) ). */

void calcula_media_matriz(int n, int a[][n], int linha, int coluna)
{
    int i, j, semafaro=0;
    float media;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if (i==linha && j==coluna){
                printf ("\n valor: %d\n",a[i][j]);

                    if (j==0 && i==0)
                        media = (float)(a[i][j+1] + a[i+1][j]) / 2;
                    else if (j==0 && i==n-1)
                        media = (float)(a[i][j+1] + a[i-1][j]) / 2;
                    else if (j==0)
                        media = (float)(a[i-1][j] + a[i][j+1] + a[i+1][j]) / 3;

                    else if (j==n-1 && i==0)
                        media = (float)(a[i][j-1] + a[i+1][j]) / 2;
                    else if (j==n-1 && i==n-1)
                        media = (float)(a[i-1][j] + a[i][j-1]) / 2;
                    else if (j==n-1)
                        media = (float)(a[i-1][j] + a[j-1][i] + a[i+1][j]) / 3;

                    else if (i==0)
                        media = (float)(a[i][j-1] + a[i+1][j] + a[i][j+1]) / 3; //
                    else if (i==n-1)
                        media = (float)(a[i][j-1] + a[i-1][j] + a[i][j+1]) / 3;

                    else
                        media = (float)(a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1]) / 4;

                printf ("\nA media dos vizinhos da matriz eh: %.2f\n",media);
                semafaro = 1;
            }

    if (semafaro == 0)
        printf ("\nDigite pontos que se encontram na matriz!\n");

    return ;
}


int main ()
{
    int n, i, j, linha, coluna;
    char opcao;

    printf ("\nDigite o tamanho da matriz: "); scanf("%d",&n);
    int a[n][n];
    if(n>=10) return 0;

    printf ("\nPreencha a matriz %dx%d: \n",n, n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            printf ("[%d][%d]: ",i,j); scanf("%d",&a[i][j]);
        }

    printf("\nConfira os dados digitados\n");
    system("pause");
    system("CLS");

    do{
        printf ("\nMATRIZ: \n");
        for(i=0; i<n; i++){
            for(j=0; j<n; j++)
                printf (" %d",a[i][j]);
            printf ("\n");
        }

        printf ("\nDigite a posicao para calcular a media: \n");
        printf ("Linha: "); scanf("%d",&linha);
        printf ("Coluna: "); scanf("%d",&coluna);

        calcula_media_matriz(n, a, linha, coluna);
        printf ("\nDeseja continuar(S/N)?: "); scanf(" %c",&opcao);
        system("CLS");
    } while(opcao == 's' || opcao == 'S');

    return 0;
}
