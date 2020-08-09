#include<stdio.h>
#include<stdlib.h>

/*Escrever uma função que troca os valores de duas variáveis inteiras. Use a função no
programa principal para trocar dois valores digitados pelo usuário.*/

void troca (int *x, int *y)
{
    int aux;
    aux = *y;
    *y = *x;
    *x = aux;
    return ;
}

int main ()
{
    int a, b;
    printf ("Digite o valor de A: ");
    scanf ("%d",&a);
    printf ("Digite o valor de B: ");
    scanf ("%d",&b);

    troca (&a,&b);
    printf ("\nO Valor de A eh %d e B eh %d\n", a, b);
    return 0;
}

