#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/* Elabore um programa que preencha uma matriz? 1 24 com os valores das vendas de uma loja, em que cada
linha representa um mês do ano e cada coluna representa uma semana do mês. O programa deverá calcular
e mostrar:
¦ o total vendido em cada mês do ano, mostrando o nome do mês por extenso;
¦ o total vendido em cada semana durante todo o ano;
¦ o total vendido pela loja no ano. */

int main ()
{
    setlocale(LC_ALL, "Portuguese");

    int i, j, k;
    char mes[3][15];
    float venda[3][4], tmes, ano, sem;

    for (i=0; i<3; i++){
        printf ("Digite o mês: ");
        scanf (" %[^\n]",&mes[i]);
        printf ("Digite os valores de venda do mês %s:\n",mes[i]);
        for (j=0; j<4; j++){
            scanf ("%f",&venda[i][j]);
        }
        printf ("\n");
    }

    printf ("O total de vendas dos mêses");
    printf ("\n     Mês     |       Valor       ");
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

    printf ("\n\nComapração de vendas entre as semanas no ano");
    printf ("\n  Semana   |    Valor     ");
    for (i=0; i<4; i++){
        sem = 0;
        for (j=0; j<3; j++){
            sem = sem + venda[j][i];
        }
        printf ("\n    %d           %.2f",i+1, sem);
    }

    printf ("\n\nO total vendido durante o ano é: R$%.2f\n",ano);

    return 0;

}
