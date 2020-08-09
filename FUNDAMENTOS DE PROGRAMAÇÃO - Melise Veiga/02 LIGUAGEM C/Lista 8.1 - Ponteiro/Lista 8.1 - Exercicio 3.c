#include<stdio.h>
#include<stdlib.h>

/* 3. Fa�a uma fun��o que receba um valor inteiro como refer�ncia e retorne o resto da
divis�o deste n�mero por 10. Altere tamb�m o valor da vari�vel passada por refer�ncia,
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
