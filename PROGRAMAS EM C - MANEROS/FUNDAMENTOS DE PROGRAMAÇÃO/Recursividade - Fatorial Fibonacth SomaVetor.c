#include<stdio.h>

/* Realizar as funções de fibonachi, fatorial e preenchimento de vetor. Com recursividade*/

int fib(int n);
int fatorial(int n);
int soma(int n, int vetor[]);

int main ()
{
    int n, resultado, i;
    printf ("Digite o valor de N: ");
    scanf ("%d",&n);
    int vetor[n];

    resultado = fib(n);
    printf ("%d",resultado);

    resultado = fatorial(n);
    printf ("\n%d\n",resultado);

    printf ("\nPreenche vetor: \n");
    for (i=0; i<n; i++)
        scanf ("%d",&vetor[i]);

    resultado = soma(n, vetor);
    printf ("\n%d\n",resultado);


    return 0;
}

int fib(int n)
{
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int fatorial(int n)
{
    if (n==0 || n==1)
        return 1;
    return n*fatorial(n-1);
}

int soma(int n, int vetor[])
{
    if (n==1)
        return vetor[n-1];
    return n + soma(n-1, vetor);
}
