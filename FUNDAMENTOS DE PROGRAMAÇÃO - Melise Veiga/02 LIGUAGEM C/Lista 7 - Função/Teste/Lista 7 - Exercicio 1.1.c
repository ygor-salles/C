#include<stdio.h>

/* Elabore um programa que receba um numero inteiro e utilize a funcao criada para
informar ao usuario se o numero eh positivo ou negativo. */

void imprima (int a)
{
    if (a>=0){
        printf ("\n Positivo \n");
    }
    else{
        printf ("\n Negativo \n");
    }
    return ;
}


int main ()
{
    int a;
    printf ("Digite o valor de A: ");
    scanf ("%d",&a);
    imprima (a);
}
