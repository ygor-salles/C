#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Calcular o valor da sequ�ncia abaixo definida por recorr�ncia:
S(i) = i2
*S(i-1), para i=1, S=1, n deve ser fornecido pelo usu�rio.

A fun��o pow(x,y) da biblioteca math.h devolve x elevado a y (o resultado da fun��o �
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
