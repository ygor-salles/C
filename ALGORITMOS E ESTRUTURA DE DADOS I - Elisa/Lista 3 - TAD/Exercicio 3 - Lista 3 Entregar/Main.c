#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

int main ()
{
    float x, y, a, b, c, d;
    Complexo *dados;

    printf ("Digite valores de A e B respectivamente: \n");
    scanf (" %f %f",&a, &b);
    printf ("Digite valores de C e D respectivamente: \n");
    scanf (" %f %f",&c, &d);

    dados = criar (a, b, c, d);

    somar (&x, &y, dados);
    printf ("\nA soma eh: (%.2f)+(%.2f)i\n",x, y);

    subtrair (&x, &y, dados);
    printf ("\nA subtracao eh: (%.2f)+(%.2f)i\n",x, y);

    multiplicar (&x, &y, dados);
    printf ("\nA multiplicacao eh: (%.2f)+(%.2f)i\n",x, y);

    dividir (&x, &y, dados);
    printf ("\nA divisao eh: (%.2f)+(%.2f)i\n",x, y);

    liberar(dados);

    return 0;
}
