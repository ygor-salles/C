#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que receba o nome e a nota de oito alunos e mostre o relatório a seguir:
Digite o nome do 1º aluno: Carlos
Digite a nota do Carlos: 8
Digite o nome do 1º aluno: Pedro
Digite a nota do Pedro: 5
Relatórios de notas
Carlos 8.0
Pedro 5.0
..
..
..
Média da classe = ?? */

int main ()
{
  int i, c=0;
  float nota[8], soma=0;
  char nome[8];

  for (i=1; i<=8; i++){
    printf ("Digite o nome do %dº aluno: ",i);
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