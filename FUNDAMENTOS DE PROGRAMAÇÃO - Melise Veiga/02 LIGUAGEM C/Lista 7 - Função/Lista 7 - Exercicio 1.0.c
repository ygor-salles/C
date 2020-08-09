#include <stdio.h>
/* Elabore uma função que receba um número inteiro e retorne 1 se o
número recebido for positivo ou retorne 0, se o número for negativo ou 0. */

int retorna (int a)
{
    if (a>0)
        return (1);
        else
        return (0);
}


int main ()
{
    int x, funcao;
    printf ("Digite o valor de x: ");
    scanf ("%d",&x);
    funcao = retorna (x);
    printf ("%d\n", funcao);
}
