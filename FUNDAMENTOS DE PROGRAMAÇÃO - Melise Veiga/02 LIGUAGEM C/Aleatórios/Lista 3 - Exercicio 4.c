#include <stdio.h>

// Considere um n�mero de 3 d�gitos, usando os operadores \ (divis�o inteira) e %
// (resto da divis�o), imprima o algarismo correspondente � centena e o algarismo
// correspondente � dezena.

int main ()
{
    int num, centena, dezena, aux;
    printf ("Digite um n�mero de 3 digitos: ");
    scanf (" %d",&num);

    centena = num/100;
    aux = num % 100;
    dezena = aux/10;

    printf ("\n A centena eh: %d\n\n",centena);
    printf (" A dezena eh: %d\n",dezena);
}
