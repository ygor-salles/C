#include <stdio.h>

// Considere um número de 3 dígitos, usando os operadores \ (divisão inteira) e %
// (resto da divisão), imprima o algarismo correspondente à centena e o algarismo
// correspondente à dezena.

int main ()
{
    int num, centena, dezena, aux;
    printf ("Digite um número de 3 digitos: ");
    scanf (" %d",&num);

    centena = num/100;
    aux = num % 100;
    dezena = aux/10;

    printf ("\n A centena eh: %d\n\n",centena);
    printf (" A dezena eh: %d\n",dezena);
}
