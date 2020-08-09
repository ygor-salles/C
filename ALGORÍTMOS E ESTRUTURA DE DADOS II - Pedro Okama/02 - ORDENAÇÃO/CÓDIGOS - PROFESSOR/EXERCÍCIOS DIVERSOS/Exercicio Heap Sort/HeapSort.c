/* Alunos: 2017009453, 2017014382 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int TipoIndice;
typedef int TipoChave;
typedef struct TipoItem{
  TipoChave Chave;
} TipoItem;


void Insere (TipoItem *x , TipoItem *A, TipoIndice *n);
void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A);
TipoItem RetiraMax(TipoItem *A, TipoIndice *n);
void Constroi(TipoItem *A, TipoIndice n);
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A);

void Insere (TipoItem *x , TipoItem *A, TipoIndice *n)
{
  (*n)++;
  A[*n] = *x;
  A[*n].Chave = INT_MIN;
  AumentaChave(*n, x->Chave, A);
}

void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A)
{
  TipoItem x;
  if(ChaveNova < A[i].Chave){
    printf("ChaveNova menor que atual \n");
    return;
  }
  A[i].Chave = ChaveNova;
  while(i > 1 && A[i/2].Chave < A[i].Chave){
    x = A[i/2];
    A[i/2] = A[i];
    A[i] = x;
    i = i/2;
  }
}

TipoItem RetiraMax(TipoItem *A, TipoIndice *n)
{
  TipoItem Maximo;
  if (*n < 1)
    printf("Erro: heap vazio \n" );
  else{
    Maximo = A[1];
    A[1] = A[*n];
    (*n)--;
    Refaz(1, *n, A);
  }
  return Maximo;
}

void Constroi(TipoItem *A, TipoIndice n)
{
  TipoIndice Esq;
  Esq = n / 2 + 1;
  while (Esq > 1){
    Esq--;
    Refaz(Esq, n, A);
  }
}

void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A)
{
  TipoIndice i = Esq;
  int j; TipoItem x;
  j = i * 2;
  x = A[i];
  while (j <= Dir){
    if (j < Dir)
      if (A[j].Chave < A[j+1].Chave) j++;
    if (x.Chave >= A[j].Chave) break;
    A[i] = A[j]; i = j; j = i*2;
  }
  A[i] = x;
}

TipoItem Max(TipoItem *A)
{
  return (A[1]);
}

void imprime(TipoItem *P, int n)
{
  for(int i = 1; i <= n; i++)
    printf("%d ", (P[i].Chave));
  printf("\n");
}

int main(int argc, char * argv[])
{
  int n;
  TipoItem *P, x;
  TipoChave num;
  char op;

  printf ("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  P = calloc(sizeof(TipoItem), 2*n); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  printf ("\nPreencha o vetor: \n");
  for(int i=0; i<n; i++)
    scanf("%d ", &(P[i].Chave));

  Constroi(P, n);

  do
  {
    printf ("\nEscolha uma das opcoes: \n");
    printf ("\n'p': Imprime;");
    printf ("\n'm': Consulta topo mas nao remove e imprime;");
    printf ("\n'r': Retira topo e imprime;");
    printf ("\n'i': Inserir elemento no Heap;");
    printf ("\n'a': Atualiza o registro do topo;");
    printf ("\n'x': Imprime e fecha;");
    printf("\nOpcao: ");
    scanf(" %c",&op);
    system("CLS");

    switch (op)
    {
      case 'a':
        scanf(" %d", &num);
        AumentaChave(1, num, P);
        Refaz(P[0].Chave, P[n-1].Chave, P);
        break;

      case 'p':
        imprime(P, n);
        break;

      case 'i':
        scanf(" %d", &x.Chave);
        Insere (&x , P, &n);
        break;

      case 'r':
        x = RetiraMax(P, &n);
        printf("%d", x.Chave);
        printf("\n");
        break;

      case 'm':
        x = Max(P);
        printf("%d", x.Chave);
        printf("\n");
        break;

      default:
        break;
    }

  } while (op != 'x');
    imprime(P, n);

  return 0;
}
