#include<stdio.h>
#include<stdlib.h>

/* Elabore uma fun��o que receba dois n�meros inteiros e positivos e
calcule a soma dos n�meros no intervalo fechado definido entre o primeiro e o
segundo n�mero. Use a fun��o no programa principal para calcular a soma entre dois
n�meros fornecidos pelo usu�rio. A fun��o s� dever� ser executada caso o primeiro
valor seja maior ou igual ao segundo.
Dica: um dos par�metros recebidos pela fun��o deve ser o endere�o da vari�vel que
dever� guardar o valor da soma. */


void fsoma (int x, int y, int *pResultado)
{
    int i;
    for (i=y; i<=x; i++){
    *pResultado = *pResultado+i;
    }
}

int main ()
{
    int x, y, resultado=0;
    printf ("Digite o valor de X e Y respectivamente: \n");
    scanf ("%d %d",&x, &y);

    if (x>=y){
        fsoma (x, y, &resultado);
        printf ("\nA soma no intervalo fechado dos numeros digitados eh: %d\n", resultado);
    }
    return 0;
}
