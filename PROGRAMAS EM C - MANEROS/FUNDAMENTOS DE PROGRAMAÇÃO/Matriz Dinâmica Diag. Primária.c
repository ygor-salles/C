#include <stdio.h>
#include <stdlib.h>

/* 2. Escreva funções para lidar com matrizes triangulares inferiores de dimensão n X n, onde todos
os elementos abaixo da diagonal são iguais a zero e não devem ser alocados. No entanto, um
acesso a um elemento abaixo da diagonal deve retornar o valor zero. Escreva as seguintes
funções, usando a estratégia de vetor de ponteiros para armazenar a matriz.
(a) Função para criar uma matriz, onde n representa a dimensão da matriz, inicialmente com
os valores todos iguais a zero:
float **cria(int n);
(b) Função para atribuir o valor de um elemento da matriz, assumindo que i >= j:
void atribui(int i, int j, float x);
(c) Função para acessar o valor de um elemento da matriz, inclusive elementos acima da
diagonal:
float acessa(int i, int j);
(d) Função para liberar a memória da matriz alocada:
void libera(int n, float **mat);
Escreva uma função main para testar as funções implementadas. */

float **cria(int n);
void atribui(int i, int j, float x, float **mat);
float acessa(int i, int j, float **mat);
void libera(int n, float **m5at);

int main()
{
  int n, i, j;
  float **mat, x;

  printf("\nDigite a dimensao da matriz quadrada triangular inferior: ");
  scanf("%d", &n);

  mat = cria(n);
  printf("\n");

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(i<=j){
        printf("Digite o valor do elemento %d, %d da matriz: ", i, j);
        scanf("%f", &x);
        atribui(i, j, x, mat);
      }
    }
    printf("\n");
  }

  for(i=0; i<n; i++){
    printf("\n");
    for(j=0; j<n; j++){
      printf("%.0f ", acessa(i, j, mat));
    }
  }
  printf ("\n");

  libera(n, mat);

  return 0;
}

float** cria(int n)
{
  int i;
  float **mat = (float**) malloc(n * sizeof(float*));
  if(mat == NULL){
    printf("Memória insuficiente!");
    return NULL;
  }

  for(i=0; i<n; i++){
    mat[i] = (float*) malloc((n-i) * sizeof(float));
    if(mat[i] == NULL){
      printf("Memória insuficiente!");
      return NULL;
    }
  }

  return mat;
}

void atribui(int i, int j, float x, float **mat)
{
  if(i <= j){
    mat[i][j-i] = x;
  }
}

float acessa(int i, int j, float **mat)
{
  if(i <= j)
    return mat[i][j-i];
  else
    return 0;
}

void libera(int n, float **mat)
{
  int i;
  for(i=0; i<n; i++)
    free(mat[i]);
  free(mat);
}
