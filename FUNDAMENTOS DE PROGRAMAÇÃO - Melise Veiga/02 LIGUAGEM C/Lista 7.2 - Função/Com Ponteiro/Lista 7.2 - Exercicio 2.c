#include<stdio.h>
#include<stdlib.h>

/* Elabore uma função que receba dois números inteiros e positivos e
calcule a soma dos números no intervalo fechado definido entre o primeiro e o
segundo número. Use a função no programa principal para calcular a soma entre dois
números fornecidos pelo usuário. A função só deverá ser executada caso o primeiro
valor seja maior ou igual ao segundo.
Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que
deverá guardar o valor da soma. */


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
