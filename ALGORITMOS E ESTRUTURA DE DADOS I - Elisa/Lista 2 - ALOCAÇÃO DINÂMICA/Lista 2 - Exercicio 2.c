#include <stdio.h>
#include <stdlib.h>

/* 2. Escreva fun��es para lidar com matrizes triangulares inferiores de dimens�o n X n, onde todos
os elementos abaixo da diagonal s�o iguais a zero e n�o devem ser alocados. No entanto, um
acesso a um elemento abaixo da diagonal deve retornar o valor zero. Escreva as seguintes
fun��es, usando a estrat�gia de vetor de ponteiros para armazenar a matriz.
(a) Fun��o para criar uma matriz, onde n representa a dimens�o da matriz, inicialmente com
os valores todos iguais a zero:
float **cria(int n);
(b) Fun��o para atribuir o valor de um elemento da matriz, assumindo que i >= j:
void atribui(int i, int j, float x);
(c) Fun��o para acessar o valor de um elemento da matriz, inclusive elementos acima da
diagonal:
float acessa(int i, int j);
(d) Fun��o para liberar a mem�ria da matriz alocada:
void libera(int n, float **mat);
Escreva uma fun��o main para testar as fun��es implementadas. */

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
    printf("Mem�ria insuficiente!");
    return NULL;
  }

  for(i=0; i<n; i++){
    mat[i] = (float*) malloc((n-i) * sizeof(float));
    if(mat[i] == NULL){
      printf("Mem�ria insuficiente!");
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
