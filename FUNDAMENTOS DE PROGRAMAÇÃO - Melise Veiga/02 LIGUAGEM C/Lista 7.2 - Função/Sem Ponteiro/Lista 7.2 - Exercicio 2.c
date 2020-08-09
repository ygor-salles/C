#include<stdio.h>

/* Elabore uma função que receba dois números inteiros e positivos e
calcule a soma dos números no intervalo fechado definido entre o primeiro e o
segundo número. Use a função no programa principal para calcular a soma entre dois
números fornecidos pelo usuário. A função só deverá ser executada caso o primeiro
valor seja maior ou igual ao segundo.
Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que
deverá guardar o valor da soma. */

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