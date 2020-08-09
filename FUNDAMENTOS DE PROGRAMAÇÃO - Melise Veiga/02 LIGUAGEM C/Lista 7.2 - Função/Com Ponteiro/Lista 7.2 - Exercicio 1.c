#include<stdio.h>
#include<stdlib.h>

/* Elabore uma fun��o que receba uma hora completa
(hora/minuto/segundo) e converta para segundo. Use a fun��o no programa principal
para converter um valor hora completo fornecido pelo usu�rio.
Dica: um dos par�metros recebidos pela fun��o deve ser o endere�o da vari�vel que
dever� guardar o resultado da convers�o. */

void hrSegundo (int hora, int min, int seg, float *segundo)
{
    float minuto;
    minuto = (hora*60)+min;
    *segundo = (minuto*60)+seg;
}

int main ()
{
    float segundo;
    int hora, min, seg;
    printf ("Digite a hora, minuto e segundo respectivamente: \n");
    scanf ("%d %d %d",&hora, &min, &seg);

    hrSegundo (hora, min, seg, &segundo);
    printf ("\nA hora convertida para segundo eh: %.0f segundos\n", segundo);
    return 0;
}
