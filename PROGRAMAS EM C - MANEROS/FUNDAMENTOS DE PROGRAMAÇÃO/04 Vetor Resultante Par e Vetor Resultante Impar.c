#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que receba dez números inteiros e armazene-os em um vetor. Calcule e mostre dois
vetores resultantes: o primeiro com os números pares e o segundo, com os números ímpares. */

int main ()
{
  int vet[10], par[10], impar[10], i, j=0, k=0;

  for (i=0; i<10; i++){
    printf ("Digite num: ");
    scanf ("%d",&vet[i]);
  }

  for (i=0; i<10; i++){
    if (vet[i] % 2 == 0){
      par[j] = vet[i];
      j++;
    }
    else{
      impar[k] = vet[i];
      k++;
    }
  }

  printf ("\nVetor PAR:");
  for (i=0; i<j; i++){
    printf ("\n%d",par[i]);
  }
  printf ("\n");
  printf ("\nVetor IMPAR:");
  for (i=0; i<k; i++){
    printf ("\n%d",impar[i]);
  }

  return 0;   
  
}