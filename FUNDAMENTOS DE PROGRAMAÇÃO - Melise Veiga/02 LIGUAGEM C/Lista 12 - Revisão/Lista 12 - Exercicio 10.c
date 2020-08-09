#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 10. Dizemos que uma matriz quadrada inteira � um quadrado m�gico se a soma dos
elementos de cada linha, a soma dos elementos de cada coluna e a soma dos elementos
das diagonais principal e secund�ria s�o todas iguais. Elabore uma fun��o que receba
uma matriz e retorne 1, se a matriz for um quadrado m�gico e 0, caso contr�rio. Utilize
a fun��o no programa principal.
EX QUADRADO M�GICO:
(8  0  7)
|4  5  6|
(3  10 2) */

float teste_matriz_magica(int matriz[][3]);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int matriz[3][3], i, j;

    printf ("\nPreencha a matriz: \n");
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            scanf("%d",&matriz[i][j]);

    printf ("\nVerificando...\n"); system("pause");
    system("CLS");

    printf ("\nMATRIZ: \n\n");
    for (i=0; i<3; i++){
        for (j=0; j<3; j++)
            printf (" %d",matriz[i][j]);
        printf ("\n");
    }

    teste_matriz_magica(matriz);

    if (teste_matriz_magica(matriz) == 1)
        printf ("\n� UM QUADRADO M�GICO!\n");
    else
        printf ("\nN�o � quadrado m�gico!\n");

    return 0;
}

float teste_matriz_magica(int matriz[][3])
{
    int i, j, linha[3], coluna[3], principal=0, secundaria=0, cont=0;

    for (i=0; i<3; i++){
        linha[i] = 0;
        coluna[i] = 0;
        for (j=0; j<3; j++){
            linha[i] = linha[i] + matriz[i][j];
            coluna[i] = coluna[i] + matriz[j][i];

            if (i == j)
                principal = principal + matriz[i][j];

            if(j == 3-1-i)
                secundaria = secundaria + matriz[i][j];
        }
    }

    for (i=0; i<3-1; i++)
        if (linha[i]==linha[i+1] && coluna[i]==coluna[i+1])
            cont++;

    if (cont==2 && linha[0]==coluna[0] && coluna[0]==principal && principal==secundaria)
        return 1;
    else
        return 0;
}
