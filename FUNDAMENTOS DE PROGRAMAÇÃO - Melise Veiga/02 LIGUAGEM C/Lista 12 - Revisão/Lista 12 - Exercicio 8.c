#include<stdio.h>
#include<stdlib.h>

/* 8. Os elementos aij de uma matriz inteira A de dimens�o N representam os custos de
transporte da cidade i para a cidade j. Exemplo: considere a matriz A abaixo:
( 4    1    2    3 )
| 5    2    1  400 |
| 2    1    3    8 |
( 7    1    2    5 )
O custo do itiner�rio (caminho) 0 3 1 3 3 2 1 0 �
a03 + a31 + a13 + a33 + a32 + a21 + a10 = 3 + 1 + 400 + 5 + 2 + 1 + 5 = 417
O n�mero m�ximo de cidades � 10. O tamanho m�ximo de um itiner�rio � 15. Elaborar
uma fun��o que receba a matriz A, um vetor contendo o itiner�rio, o tamanho do itiner�rio
e retorne o custo do itiner�rio.
No programa principal, leia a matriz de custo e solicite o usu�rio que digite o tamanho do
itiner�rio e as cidades do caminho. Utilize a fun��o elaborada para retornar o custo total da
viagem. */

float retorna_custo_itinerario(int a[][4], int n, int itinerario[]);

int main ()
{
    int a[4][4], n, i, j, soma;

    printf ("\nPreencha MATRIZ: \n");
    for (i=0; i<4; i++)
        for (j=0;j<4; j++)
            scanf("%d",&a[i][j]);

    printf ("\n\n");
    system("pause");
    system("CLS");

    printf ("\nMATRIZ: \n");
    for (i=0; i<4; i++){
        for (j=0;j<4; j++)
            printf(" %d",a[i][j]);
        printf ("\n");
    }

    printf ("\nDigite o tamanho do itinerario: "); scanf ("%d",&n);
    if (n>15) return 0;
    int itinerario[n];

    printf ("\nDigite as cidades do caminho: \n");
    for (i=0; i<n; i++)
        scanf("%d",&itinerario[i]);

    soma = retorna_custo_itinerario(a, n, itinerario);

    printf ("\nO custo total da viajem eh: %d\n",soma);

    return 0;
}

float retorna_custo_itinerario(int a[][4], int n, int itinerario[])
{
    int i, j, k, soma=0;

    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            for (k=0; k<n; k++)
                if (i==itinerario[k] && j==itinerario[k+1])
                    soma = soma + a[i][j];

    return soma;
}
