#include<stdio.h>
#include<stdlib.h>

/* Faça uma função que receba um valor inteiro como referência e retorne o resto da
divisão deste número por 10. Altere também o valor da variável passada por referência,
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
    printf ("\nO resto da divisão por 10 eh: %d\n",a);
    dividir (&a);
    printf ("\nO valor dividido por 10 eh: %d\n",a);
    return 0;
}
