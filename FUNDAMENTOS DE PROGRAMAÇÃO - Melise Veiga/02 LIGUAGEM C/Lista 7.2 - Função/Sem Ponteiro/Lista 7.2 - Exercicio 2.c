#include<stdio.h>

/* Elabore uma fun��o que receba dois n�meros inteiros e positivos e
calcule a soma dos n�meros no intervalo fechado definido entre o primeiro e o
segundo n�mero. Use a fun��o no programa principal para calcular a soma entre dois
n�meros fornecidos pelo usu�rio. A fun��o s� dever� ser executada caso o primeiro
valor seja maior ou igual ao segundo.
Dica: um dos par�metros recebidos pela fun��o deve ser o endere�o da vari�vel que
dever� guardar o valor da soma. */

int retorna (int x, int y)
{
    int i, soma=0;
    for (i=y; i<=x; i++){
        soma = soma+i;
    }
    return (soma);
}

int main ()
{
    int x, y, funcao;
    printf ("Digite o valor de x: ");
    scanf ("%d",&x);
    printf ("Digite o valor de y: ");
    scanf ("%d",&y);

    if (x<y){
        (" ");
    }
    else {
        funcao = retorna (x, y);
        printf ("\nA soma no intervalo dosnumeros digitados eh: %d\n",funcao);
    }
    return 0;
}