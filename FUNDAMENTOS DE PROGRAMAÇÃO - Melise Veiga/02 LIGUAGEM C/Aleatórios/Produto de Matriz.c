#include<stdio.h>
#include<stdlib.h>

/* 13. Elabore uma função que receba duas matrizes A e B e suas respectivas dimensões e
imprima a matriz resultante da multiplicação de A por B. Caso não seja possível
multiplicar A por B, imprima mensagem de erro. */

void multiplica_matriz(int lA, int cA, int lB, int cB, int a[][cA], int b[][cB]);

int main ()
{
    int i, j, lA, cA, lB, cB;

    printf("\nMATRIZ A: \n");
    printf("Digite a qtd de linhas da matriz A: "); scanf("%d",&lA);
    printf("Digite a qtd de colunas da matriz A: "); scanf("%d",&cA);

    printf("\nMATRIZ B: \n");
    printf("Digite a qtd de linhas da matriz B: "); scanf("%d",&lB);
    printf("Digite a qtd de colunas da matriz B: "); scanf("%d",&cB);

    if (cA != lB){
        printf("\nImpossivel realizar o produto das matrizes! Nro de ColunaA diferente de Nro de LinhasB\n");
        return 0;
    }

    int a[lA][cA];
    int b[lB][cB];

    printf ("\nPreencha a matriz A: \n");
    for(i=0; i<lA; i++)
        for(j=0; j<cA; j++)
            scanf("%d",&a[i][j]);

    printf ("\nPreencha a matriz B: \n");
    for(i=0; i<lB; i++)
        for(j=0; j<cB; j++)
            scanf("%d",&b[i][j]);

    printf("\n\n"); system("pause");
    system("CLS");

    printf ("MATRIZ A: \n");
    for(i=0; i<lA; i++){
        for(j=0; j<cA; j++)
            printf("_%d_|",a[i][j]);
        printf("\n");
    }

    printf ("\nMATRIZ B: \n");
    for(i=0; i<lB; i++){
        for(j=0; j<cB; j++)
            printf("_%d_|",b[i][j]);
        printf("\n");
    }

    multiplica_matriz(lA, cA, lB, cB, a, b);

    return 0;
}

void multiplica_matriz(int lA, int cA, int lB, int cB, int a[][cA], int b[][cB])
{
    int k, aux=0, i, j, c[lB][cA];
    //Processamento e saida em tela
        for(i=0; i<lA; i++)
            for(j=0; j<cB; j++){
                c[i][j]=0;
                for(k=0; k<lB; k++)
                    aux += a[i][k] * b[k][j];

                c[i][j]=aux;
                aux=0;
            }

    printf("\n\n");
    printf("---------------------------- 3 - Matriz Gerada ---------------------------------\n\n");
    for(i=0; i<lA; i++){
         for(j=0; j<cB; j++)
            printf("_%d_|", c[i][j]);
         printf("\n");
    }
    printf("\n\n");

    return ;
}
