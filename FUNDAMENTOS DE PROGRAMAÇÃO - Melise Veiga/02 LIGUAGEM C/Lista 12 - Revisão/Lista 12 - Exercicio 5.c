#include<stdio.h>
#include<stdlib.h>

/* 5. Escreva uma função que receba como parâmetro uma matriz quadrada A de números
inteiros (ordem n < 10) e retorne uma matriz Media, onde media[i][j] é a média
aritmética dos vizinhos de A[i][j]. Para isto, utilize a função da questão anterior. */

void retorna_matriz_media(int n, int a[][n], int linha, int coluna, float media[][n], int semafaro[][n])
{
    int i, j;
    float med;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if (i==linha && j==coluna){
                printf ("\n valor: %d\n",a[i][j]);

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

                printf ("\nA media dos vizinhos da matriz eh: %.2f\n",med);
                media[i][j] = med;
                semafaro[i][j] = 1;
            }

    return ;
}

int main ()
{
    int n, i, j, linha, coluna, laco=0;
    char opcao;

    printf ("\nDigite o tamanho da matriz: "); scanf("%d",&n);
    if (n>=10) return 0;
    int a[n][n];
    float media[n][n];
    int semafaro[n][n];

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            semafaro[i][j] = 0;

    printf ("\nPreencha a matriz %dx%d: \n",n, n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            printf ("[%d][%d]: ",i,j); scanf("%d",&a[i][j]);
        }

    printf("\nConfira os dados digitados\n");
    system("pause");
    system("CLS");

    do{
        laco++;
        printf ("\nMATRIZ: \n\n");
        for(i=0; i<n; i++){
            for(j=0; j<n; j++)
                printf ("_%d_|",a[i][j]);
            printf ("\n");
        }

        printf ("\nDigite a posicao para calcular a media: \n");
        printf ("Linha: "); scanf("%d",&linha);
        printf ("Coluna: "); scanf("%d",&coluna);

        retorna_matriz_media(n, a, linha, coluna, media, semafaro);
        printf ("\nDeseja continuar(S/N)?: "); scanf(" %c",&opcao);
        system("CLS");

    } while((opcao == 's' || opcao == 'S') && laco<(n*n));

    printf ("\nA matriz media dos pontos escolhidos eh: \n\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if (semafaro[i][j] == 0)
                media[i][j] = 0;
            printf ("_%.2f_|",media[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
