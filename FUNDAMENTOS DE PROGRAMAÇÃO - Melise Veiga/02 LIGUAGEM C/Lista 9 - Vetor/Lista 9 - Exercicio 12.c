#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que receba cinco n�meros e mostre a sa�da a seguir:
Digite o 1� n�mero 5
Digite o 2� n�mero 3
Digite o 3� n�mero 2
Digite o 4� n�mero 0
Digite o 5� n�mero 2
Os n�meros digitados foram: 5 + 3 + 2 + 0 + 2 = 12 */

int main ()
{
  int vet[5], i, soma=0;

  for (i=1; i<=5; i++){
    printf ("Digite o %d� numero: ",i);
    scanf ("%d",&vet[i]);
    soma = soma+vet[i];
  }

  printf ("\nOs n�meros digitados foram: %d + %d + %d + %d + %d = %d\n",vet[1], vet[2], vet[3], vet[4], vet[5], soma);

  return 0;
}