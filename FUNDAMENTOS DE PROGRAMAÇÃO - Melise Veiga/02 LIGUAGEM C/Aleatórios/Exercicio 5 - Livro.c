#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/* Elabore um programa que preencha uma matriz? 1 24 com os valores das vendas de uma loja, em que cada
linha representa um m�s do ano e cada coluna representa uma semana do m�s. O programa dever� calcular
e mostrar:
� o total vendido em cada m�s do ano, mostrando o nome do m�s por extenso;
� o total vendido em cada semana durante todo o ano;
� o total vendido pela loja no ano. */

int main ()
{
    setlocale(LC_ALL, "Portuguese");

    int i, j, k;
    char mes[3][15];
    float venda[3][4], tmes, ano, sem;

    for (i=0; i<3; i++){
        printf ("Digite o m�s: ");
        scanf (" %[^\n]",&mes[i]);
        printf ("Digite os valores de venda do m�s %s:\n",mes[i]);
        for (j=0; j<4; j++){
            scanf ("%f",&venda[i][j]);
        }
        printf ("\n");
    }

    printf ("O total de vendas dos m�ses");
    printf ("\n     M�s     |       Valor       ");
    ano = 0;
    for (i=0; i<3; i++){
        tmes = 0;
        sem = 0;
        for (j=0; j<4; j++){
            tmes = tmes + venda[i][j];
            ano = ano + venda[i][j];
        }
    printf ("\n %s              R$%.2f",mes[i], tmes);
    }

    printf ("\n\nComapra��o de vendas entre as semanas no ano");
    printf ("\n  Semana   |    Valor     ");
    for (i=0; i<4; i++){
        sem = 0;
        for (j=0; j<3; j++){
            sem = sem + venda[j][i];
        }
        printf ("\n    %d           %.2f",i+1, sem);
    }

    printf ("\n\nO total vendido durante o ano �: R$%.2f\n",ano);

    return 0;

}
