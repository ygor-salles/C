#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Criar um algoritmo que leia os limites inferior e superior de um intervalo e imprima
//todos os números inteiros pares no intervalo aberto e o somatório desses números.

int main ()
{
    int inf, sup, soma=0, i;
    printf ("\n Digite o valor inferior: ");
    scanf ("%d",&inf);
    printf ("\n Digite o valor superior: ");
    scanf ("%d",&sup);

    for (i=inf; i<=sup; i++) {
        if (i % 2==0) {
            printf ("\n %d \n",i);
            soma = soma+i;
        }
    }
    printf ("\n A soma dos valores pares eh %d\n\n",soma);
    system ("pause");
    return 0;
}