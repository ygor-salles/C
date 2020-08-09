#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que receba cinco números e mostre a saída a seguir:
Digite o 1º número 5
Digite o 2º número 3
Digite o 3º número 2
Digite o 4º número 0
Digite o 5º número 2
Os números digitados foram: 5 + 3 + 2 + 0 + 2 = 12 */

int main ()
{
  int vet[5], i, soma=0;

  for (i=1; i<=5; i++){
    printf ("Digite o %dº numero: ",i);
    scanf ("%d",&vet[i]);
    soma = soma+vet[i];
  }

  printf ("\nOs números digitados foram: %d + %d + %d + %d + %d = %d\n",vet[1], vet[2], vet[3], vet[4], vet[5], soma);

  return 0;
}