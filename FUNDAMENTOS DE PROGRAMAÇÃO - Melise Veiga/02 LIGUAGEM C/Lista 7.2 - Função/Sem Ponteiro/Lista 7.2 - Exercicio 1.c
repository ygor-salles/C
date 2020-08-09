#include<stdio.h>

/* Elabore uma função que receba uma hora completa
(hora/minuto/segundo) e converta para segundo. Use a função no programa principal
para converter um valor hora completo fornecido pelo usuário.
Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que
deverá guardar o resultado da conversão. */

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
