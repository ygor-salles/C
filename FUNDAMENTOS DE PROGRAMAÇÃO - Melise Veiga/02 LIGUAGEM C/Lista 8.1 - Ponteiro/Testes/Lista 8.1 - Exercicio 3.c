#include<stdio.h>
#include<stdlib.h>

/* Fa�a uma fun��o que receba um valor inteiro como refer�ncia e retorne o resto da
divis�o deste n�mero por 10. Altere tamb�m o valor da vari�vel passada por refer�ncia,
dividindo-a por 10. */


int resto (int *x)
{
    *x = *x%10;
    return *x;
}

int dividir (int *x)
{
    *x = *x/10;
    return *x;
}

int main ()
{
    int a;
    printf ("Digite um valor: ");
    scanf ("%d",&a);

    resto (&a);
    printf ("\nO resto da divis�o por 10 eh: %d\n",a);
    dividir (&a);
    printf ("\nO valor dividido por 10 eh: %d\n",a);
    return 0;
}
