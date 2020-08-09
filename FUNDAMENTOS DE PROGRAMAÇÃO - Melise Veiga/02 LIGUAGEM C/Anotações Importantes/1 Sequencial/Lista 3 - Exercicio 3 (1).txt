#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Elabore um algoritmo para retornar o valor inteiro da divisão de dois números e o
// resto da divisão entre esses dois números.

int main ()
{
    int a, b, resto, divis;

    printf ("Digite o valor de A e B: ");
    scanf ("%d %d", &a, &b);

    divis = (int)a/b;
    resto=a%b;

    printf ("A divisão inteira eh %d e o resto eh %d", divis,resto);
    return 0;
}
