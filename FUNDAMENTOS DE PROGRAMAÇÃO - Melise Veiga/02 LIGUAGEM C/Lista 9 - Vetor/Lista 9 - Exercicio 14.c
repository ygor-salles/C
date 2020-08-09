#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que receba o nome e duas notas de seis alunos e mostre o relat�rio a seguir. 
Relat�rio de notas:
ALUNO   1�Prova   2�Prova    M�DIA     SITUA��O
Carlos    8,0       9,0      8,5        Aprovado
Pedro     4,0       5,0      4,5        Reprovado
� m�dia da classe = ?
� percentual de alunos aprovados = ?%
� percentual de alunos de exame = ?%
� percentual de alunos reprovados = ?% */

int main ()
{
  
  char nome[6];
  float notaP1[6], notaP2[6], media[6];
  int i;

  for (i=0; i<6; i++){
    printf ("Digite o nome: ");
    scanf (" %c",&nome[i]);
    printf ("Digite a nota da P1: ");
    scanf ("%f",&notaP1[i]);
    printf ("Digite a nota da P2: ");
    scanf ("%f",&notaP2[i]);
    media[i] = (notaP1[i] + notaP2[i])/2;
    printf ("\n");
  }

  printf ("\n                 Relatorio de Notas                  \n");
  printf (" ALUNO  |  1�PROVA  |  2�PROVA  |  MEDIA  |  SITUACAO  ");
  for (i=0; i<6; i++){
    if (media[i] >= 6){
  printf ("\n   %c    |   %.1f      |   %.1f       |  %.1f       |  APROVADO  ",nome[i], notaP1[i], notaP2[i], media[i]); 
    }
    else{
      printf ("\n   %c    |   %.1f      |   %.1f       |  %.1f       |  REPROVADO  ",nome[i], notaP1[i], notaP2[i], media[i]);
    }
  }
  printf ("\n");
  
  return 0;
}