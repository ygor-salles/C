#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que receba o nome e a nota de oito alunos e mostre o relat�rio a seguir:
Digite o nome do 1� aluno: Carlos
Digite a nota do Carlos: 8
Digite o nome do 1� aluno: Pedro
Digite a nota do Pedro: 5
Relat�rios de notas
Carlos 8.0
Pedro 5.0
..
..
..
M�dia da classe = ?? */

int main ()
{
  int i, c=0;
  float nota[8], soma=0;
  char nome[8];

  for (i=1; i<=8; i++){
    printf ("Digite o nome do %d� aluno: ",i);
    scanf (" %c",&nome[i]);
    printf ("Digite a nota do %c: ",nome[i]);
    scanf ("%f",&nota[i]);
    soma = soma + nota[i];
    c++; 
  }

  printf ("\n    Relatorio de Notas     ");
  for (i=1; i<=8; i++){
    printf ("\n %c  %.1f",nome[i], nota[i]);
  }
  printf ("\n\n A media da classe foi de: %.1f\n",soma/(float)c);

  return 0;
}