#include<stdio.h>
#include<stdlib.h>

/*Faça um programa que preencha três vetores com dez posições cada um: o primeiro vetor, com os nomes de
dez produtos; o segundo vetor, com os códigos dos dez produtos; e o terceiro vetor, com os preços dos produtos.
Mostre um relatório apenas com o nome, o código, o preço e o novo preço dos produtos que sofrerão
aumento.
Sabe-se que os produtos que sofrerão aumento são aqueles que possuem código par ou preço superior a
R$ 1.000,00. Sabe-se ainda que, para os produtos que satisfazem as duas condições anteriores, código e
preço, o aumento será de 20%; para aqueles que satisfazem apenas a condição de código, o aumento será
de 15%; e para aqueles que satisfazem apenas a condição de preço, o aumento será de 10%. */

int main ()
{
  char nome[10];
  int cod[10], i;
  float preco[10], novo_preco[10];

  for (i=0; i<10; i++){
    printf ("Digite a inicial do nome: ");
    scanf (" %c",&nome[i]);
    printf ("Digite o codigo do produto: ");
    scanf ("%d",&cod[i]);
    printf ("Digite preco do produto: ");
    scanf ("%f",&preco[i]);
    printf ("\n");
  }

  printf ("\n             Relatorio            \n");
  printf ("\nNome | Codigo | Preco | Novo Preco\n");
  for (i=0; i<10; i++){
    if (cod[i] % 2 == 0 && preco[i]>1000){
        novo_preco[i] = preco[i]+(preco[i]*0.2);
        printf ("\n %c  %6d     %.2f    %.2f\n",nome[i], cod[i], preco[i], novo_preco[i]);
    }
    else if (cod[i] % 2 == 0){
        novo_preco[i] = preco[i]+(preco[i]*0.15);
        printf ("\n %c  %6d     %.2f    %.2f\n",nome[i], cod[i], preco[i], novo_preco[i]);
    }
    else if (preco[i]>1000){
        novo_preco[i] = preco[i]+(preco[i]*0.1);
        printf ("\n %c  %6d     %.2f    %.2f\n",nome[i], cod[i], preco[i], novo_preco[i]);
    }
  }
  return 0;
}
