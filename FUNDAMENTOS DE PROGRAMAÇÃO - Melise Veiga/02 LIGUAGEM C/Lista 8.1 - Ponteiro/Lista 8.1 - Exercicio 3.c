#include<stdio.h>
#include<stdlib.h>

/* 3. Faça uma função que receba um valor inteiro como referência e retorne o resto da
divisão deste número por 10. Altere também o valor da variável passada por referência,
dividindo-a por 10. */

void converte (int *n, float *divisao)
{
    *divisao = (float)*n/10;
    *n = *n%10;
    return ;
}

int main ()
{
    int n;
    float divisao;
    printf ("Digite o valor de N: ");
    scanf ("%d",&n);

    converte (&n, &divisao);
    printf ("\nA divisao do numero por 10 eh: %.1f\n",divisao);
    printf ("\nO resto da divisao do numero por 10 eh: %d\n",n);
    return 0;
}
