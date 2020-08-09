#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que imprima invertidos os nomes dos algarismos de um número
inteiro de três dígitos. Use a sua função no programa principal. Não é necessário validar
a entrada do número. Ex: 234 saída: quatro três dois. */

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
