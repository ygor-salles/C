#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que receba o nome de oito clientes e armazene-os em um vetor. Em um segundo vetor,
armazene a quantidade de DVDs locados em 2011 por cada um dos oito clientes. Sabe-se que, para cada
dez locações, o cliente tem direito a uma locação grátis. Faça um programa que mostre o nome de todos
os clientes, com a quantidade de locações grátis a que ele tem direito. */

int main ()
{
  char cliente[8], aux[8];
  int qtd[8], i, locacao[8], j=0;

  for (i=0; i<8; i++){
    printf ("Digite o nome do cliente: ");
    scanf (" %c",&cliente[i]);
    printf ("Quantidade de DVD's locados em 2011: ");
    scanf ("%d",&qtd[i]);
    printf ("\n");
  }

  for (i=0; i<8; i++){
    if (qtd[i]>=10){
      locacao[j] = qtd[i]/10;
      aux[j] = cliente[i];
      j++;
    }
  }

  printf ("  Pessoas com direito a locacoes gratis");
  printf ("\n   Nome  |  Quantidade de locacoes gratis");
  for (i=0; i<j; i++){
  printf ("\n    %c    |       %d",aux[i], locacao[i]);
  }

  return 0;
}