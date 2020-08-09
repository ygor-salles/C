#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Calcular o valor da sequência abaixo definida por recorrência:
S(i) = i2
*S(i-1), para i=1, S=1, n deve ser fornecido pelo usuário.

A função pow(x,y) da biblioteca math.h devolve x elevado a y (o resultado da função é
sempre um valor do tipo double) */

int main ()
{
    double i, s;
    int n;

    printf ("Digite um valor para N: ");
    scanf ("%d",&n);

    for (i=1; i<=n; i++){
        s = pow(i,2) * (i-1);
    }
    printf ("\nA soma eh: %.2f\n",s);
    return 0;
}
