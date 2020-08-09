#include<stdio.h>
#include<stdlib.h>

/* Elabore uma função que receba uma hora completa
(hora/minuto/segundo) e converta para segundo. Use a função no programa principal
para converter um valor hora completo fornecido pelo usuário.
Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que
deverá guardar o resultado da conversão. */

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
