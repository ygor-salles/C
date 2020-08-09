#include<stdio.h>
#include<stdlib.h>

int funcao (int *p, int *q)
{
    return (/*Colocar a equação aqui para teste */);
}

int main ()
{
    int i=6, j=3, resultado;
    resultado = funcao (&i, &j);
    printf ("\n%8d\n",resultado);
    return 0;
}
