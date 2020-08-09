#include<stdio.h>
#include<stdlib.h>

/* Elabore um programa que leia uma lista de N numeros
(n <= 20) preencha um vetor e imprima a quantidade de vezes
que um numero x aparece na lista */

int main ()
{
    int i, n, vet[20], num, c1;
    printf ("Digite uma sequencia de numeros com tamanho menor ou igual a 20!: ");
    scanf ("%d",&n);
    for (i=0; i<n; i++){
        printf ("\nDigite num: ");
        scanf ("%d",&vet[i]);
    }
    printf ("Digite o valor de X que quer que seja impresso: ");
    scanf ("%d",&num);
    for (i=0; i<n; i++){
        if (num == vet[i]){
            c1++;
        }
    }
    printf ("\nA quantidade de vezes: %d\n",c1);
    return 0;
}
