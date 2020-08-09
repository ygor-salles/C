#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que multiplique os valores de um vetor A pelos valores da mesma
posição do vetor B de no máximo 20 elementos. O tamanho de cada vetor e os valores deverão ser fornecido pelo usuário e caso um vetor seja maior, o restante do vetor
resultante deverá ser preenchido pelo valor do maior */

int main ()
{
  int a[20], b[20], c[20], i, qa, qb, maior, menor;

  printf ("Digite a quantidade de valores de A: ");
  scanf ("%d",&qa);
  printf ("Digite a quantidade de valores de B: ");
  scanf ("%d",&qb);

  if (qa>qb){
    maior = qa;
    menor = qb;
  }else{
    maior = qb;
    menor = qa;
  }

  printf ("\nVetor de A\n");
  for (i=0; i<qa; i++){
    printf ("Digite num: ");
    scanf ("%d",&a[i]);
  }
  printf ("\nVetor de B\n");
  for (i=0; i<qb; i++){
    printf ("Digite num: ");
    scanf ("%d",&b[i]);
  }

  
  for (i=0; i<menor; i++){
    c[i] = a[i]*b[i]; 
  }
  if (qa != qb){
    for (i=menor; i<maior; i++){
        if (maior == qa){
            c[i] = a[i];
        }else{
            c[i] = b[i];
        }
    }
  }

  printf ("\nVetor Resultado\n");
  printf ("\n POSICAO  |  RESULTADO  ");
  for (i=0; i<maior; i++){
    printf ("\n%4d %12d",i, c[i]);
  }
  printf ("\n");

  return 0;
}
