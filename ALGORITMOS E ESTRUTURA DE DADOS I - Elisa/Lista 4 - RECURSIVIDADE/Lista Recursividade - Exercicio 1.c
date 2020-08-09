#include<stdio.h>

/* 1) Elabore uma função recursiva que calcule o valor da multiplicação entre dois inteiros a
e b positivos. */

int main ()
{
    int a=100, b=5, resultado;

    resultado = recursao(a, b);
    printf ("\n%d\n",resultado);

    return 0;
}

int recursao(int a, int b)
{
    if (b==1)
        return a;
    return a+recursao(a, b-1);
}
