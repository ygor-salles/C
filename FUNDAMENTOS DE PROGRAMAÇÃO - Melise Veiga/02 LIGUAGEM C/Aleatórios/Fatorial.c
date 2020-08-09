#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Escreva um algoritmo que calcule N fatorial. N dado pelo usuário */

int main ()
{
    int fat=1, i, n;

    printf ("Digite um numero inteiro: ");
    scanf ("%d",&n);

    for (i=n; i>=1; i--){
        fat=fat*i;
    }
    printf ("\n A soma de %d fatorial eh: %d\n\n", n, fat);
    return 0;
}
