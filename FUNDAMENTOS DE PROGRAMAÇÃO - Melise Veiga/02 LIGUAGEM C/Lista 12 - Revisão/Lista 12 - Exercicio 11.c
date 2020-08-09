#include<stdio.h>
#include<stdlib.h>

/* 11. Fazer uma função que recebe um vetor de elementos inteiros de dimensão N (N = 50),
um elemento inteiro X e retorne um valor que corresponde ao número de vezes que o
elemento X aparece no vetor. Escrever um algoritmo que leia uma matriz A de
elementos inteiros de dimensão M x N, (M,N = 50) e, utilizando a subrotina acima, gere
um vetor V cujos elementos representam quantas vezes o valor zero (0) aparece em
cada linha da matriz A. Escreva a matriz A e o vetor V. */

int funcao_vetor(int n, int vetor[], int x);
void funcao_matriz(int a[][10], int n, int m);

int main ()
{
    int vetor[50], a[5][10], n=50, m, x, i, j, resultado;

    //PRIMEIRA FUNÇÃO
    printf ("\nVETOR: \n");
    for (i=0; i<n; i++){
        vetor[i] = rand() % 10;
        printf ("%d ",vetor[i]);
    }

    printf ("\n\nDigite o valor de X: "); scanf("%d",&x);
    resultado = funcao_vetor(n, vetor, x);
    printf ("\n\nA quantidade de vezes que X aparece no vetor eh: %d vezes\n\n",resultado);

    system("pause");
    system("CLS");

    //SEGUNDA FUNÇÃO
    m=5; n=10;
    printf ("\nMATRIZ: \n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            a[i][j] = rand() % 10;
            printf (" %d",a[i][j]);
        }
        printf ("\n");
    }

    funcao_matriz(a, n, m);

    return 0;
}

int funcao_vetor(int n, int vetor[], int x)
{
    int i, cont=0;

    for (i=0; i<n; i++)
        if (x == vetor[i])
            cont++;

    return cont;
}

void funcao_matriz(int a[][10], int n, int m)
{
    int i, j, v[50], cont, k;

    for(i=0; i<m; i++){
        cont=0;
        for(j=0; j<n; j++)
            if(a[i][j] == 0)
                cont++;
        v[i]=cont;
    }

    printf("\nVETOR DE ZEROS, SEGUIDO POR LINHAS DA MATRIZ: \n");
    for(i=0; i<m; i++)
        printf ("%d ",v[i]);

    printf ("\n\n");
    return ;
}
