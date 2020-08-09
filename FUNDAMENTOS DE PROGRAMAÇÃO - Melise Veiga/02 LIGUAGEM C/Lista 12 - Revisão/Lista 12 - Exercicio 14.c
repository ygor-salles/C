#include<stdio.h>
#include<stdlib.h>

/* 14. Dizemos que uma matriz inteira Anxn é uma matriz de permutação se em cada linha e
em cada coluna houver n-1 elementos nulos e um único elemento igual a 1. Crie uma
função que receba como parâmetro uma matriz quadrada de ordem 5 e retorne 1, se a
matriz for de permutação ou 0, caso contrário. Utilize a função no programa principal. */

int permutacao(int mat[][5]);

int main ()
{
    int mat[5][5], i, j;

    printf ("PREENCHA A MATRIZ COM ZEROS E UM'S: \n");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            do{
            scanf("%d",&mat[i][j]);
            if (mat[i][j]<0 || mat[i][j]>1)
                printf ("Digite somente UM ou ZERO!\n");

            } while(mat[i][j]<0 || mat[i][j]>1);
        }
        printf("\n");
    }

    system("pause");
    system("CLS");

    printf(" MATRIZ: \n\n");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
            printf ("_%d_|",mat[i][j]);
        printf("\n");
    }

    permutacao(mat);

    if (permutacao(mat) == 1)
        printf("\n\n EH UMA MATRIZ DE PERMUTACAO!\n\n");
    else
        printf("\n\n Nao eh uma Matriz de permutacao!\n\n");

    return 0;
}

int permutacao(int mat[][5])
{
    int i, j, soma, cont=0;

    //Verificando as linhas
    for(i=0; i<5; i++){
        soma=0;
        for(j=0; j<5; j++)
            soma = soma + mat[i][j];

        if (soma == 1)
            cont++;
    }

    if (cont != 5)
        return 0;

    //Se as linhas baterem, verificar as colunas
    cont=0;
    for(i=0; i<5; i++){
        soma=0;
        for(j=0; j<5; j++)
            soma = soma + mat[j][i];

        if (soma == 1)
            cont++;
    }

    if (cont == 5)
        return 1;
    else
        return 0;
}
