#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO HEAPSORT */
//Nesse Algoritmo só usaremos o tipo Chave, não usará o tipo name.

typedef struct TipoItem
{
    int Chave;
    char name[100];
} TipoItem;

void Refaz(int Esq, int Dir, TipoItem *A)
{
  int i = Esq;
  int j; TipoItem x;
  j = i * 2;
  x = A[i];
  while (j <= Dir){
    if (j < Dir)
      if (A[j].Chave < A[j+1].Chave) j++;
    if (x.Chave >= A[j].Chave) break;
    A[i] = A[j];
    i = j;
    j = i*2;
  }
  A[i] = x;
}

void Constroi(TipoItem *A, int n)
{
  int Esq;
  Esq = n / 2 + 1;
  while (Esq > 1){
    Esq--;
    Refaz(Esq, n, A);
  }
}

void HeapSort(TipoItem *A, int n)
{
    int esq, dir;
    TipoItem x;

    Constroi(A, n);
    esq = 1;
    dir = n;
    while(dir > 1){
        x = A[1];
        A[1] = A[dir];
        A[dir] = x;
        dir--;
        Refaz(esq, dir, A);
    }
}

int main (int argc, char *argv[])
{
    TipoItem *A;
    int n=10, i;

    A = calloc(sizeof(TipoItem), 2*n); //+1 para a sentinela em P[0]
    printf("\nVetor Criado: \n");
    for (i=1; i<=n; i++){
        A[i].Chave = rand() % 100;
        printf (" %d",A[i].Chave);
    }

    printf("\n\n"); system("pause");

    HeapSort(A, n);

    printf ("\n\nVETOR ORDENADO NO HEAPSORT: \n");
    for (i=1; i<=n; i++)
        printf (" %d",A[i].Chave);

    printf("\n\n"); system("pause");
    return 0;
}
