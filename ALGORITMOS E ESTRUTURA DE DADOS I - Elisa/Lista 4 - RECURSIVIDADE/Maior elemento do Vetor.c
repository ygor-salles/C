#include<stdio.h>

/* Dado um vetor de números inteiros, implemente:
b) Função recursiva que encontre o maior elemento do vetor */

int recursivo (int valor[], int maior, int i);

int main ()
{
    int valor[5], funcao, maior, i;

    printf ("Preencha o vetor de 5 elementos: \n");
    for (i=0; i<5; i++)
        scanf ("%d",&valor[i]);

    maior = valor[0]; i=1;
    funcao = recursivo(valor, maior, i);

    printf ("\n%d\n",funcao);
    return 0;
}

int recursivo (int valor[], int maior, int i)
{
    if (i<5){
        if (valor[i] > maior){
            maior = valor[i];
        }
        maior = recursivo(valor, maior, i+1);
    }
    else
        return maior;
}
