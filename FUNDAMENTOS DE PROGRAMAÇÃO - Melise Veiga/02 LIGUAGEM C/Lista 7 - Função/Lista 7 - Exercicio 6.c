#include<stdio.h>

/* Faça um programa que contenha uma função que recebe dois números
positivos e retorna a soma dos N números inteiros existentes entre eles (inclusive).
Use a função no programa principal */

int soma (int x, int y)
{
    int soma=0, i;
    if (y>x){
    for (i=x; i<=y; i++){
        soma=soma+i;
    }
    return (soma);
    }
    else {
        for (i=y; i<=x; i++){
        soma=soma+i;
    }
    return (soma);
    }
}

int main ()
{
    int x, y, funcao;
    printf ("Entre com dois numeros: \n");
    scanf ("%d %d", &x, &y);
    funcao = soma (x, y);
    printf ("\n O valor da soma eh: %d\n",funcao);
}
