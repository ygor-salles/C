#include<stdio.h>

/* Elabore uma fun��o que receba uma hora completa
(hora/minuto/segundo) e converta para segundo. Use a fun��o no programa principal
para converter um valor hora completo fornecido pelo usu�rio.
Dica: um dos par�metros recebidos pela fun��o deve ser o endere�o da vari�vel que
dever� guardar o resultado da convers�o. */

int converte (int h, int m, int s)
{
    float minuto, segundo;
    minuto = (h*60)+m;
    segundo = (minuto*60)+s;
    return (segundo);
}

int main ()
{
    int hora, min, seg, funcao;
    printf ("Digite a hora minuto e segundo respectivamente: \n");
    scanf (" %d %d %d", &hora, &min, &seg);

    funcao = converte (hora, min, seg);
    printf ("\nO valor do horario em segundos eh: %d\n",funcao);
}
