#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que imprima invertidos os nomes dos algarismos de um n�mero
inteiro de tr�s d�gitos. Use a sua fun��o no programa principal. N�o � necess�rio validar
a entrada do n�mero. Ex: 234 sa�da: quatro tr�s dois. */

void algarismo (int x, int *c, int *d, int *u)
{
    *c = x/100;
    *d = (x%100)/10;
    *u = (x%100)%10;

    printf ("\n%d %d %d\n", *u, *d, *c);
    return ;
}

int main ()
{
    int num, c, d, u;
    printf ("Digite um valor inteiro: ");
    scanf ("%d",&num);

    algarismo (num, &c, &d, &u);
    return 0;
}
