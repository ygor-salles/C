#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoIndice;
typedef long TipoChave;
typedef struct Pessoas
{
  int Chave;
  char name[100];
} Pessoas;

/*SUAS FUNCOES AQUI*/
void Particao (int Esq , int Dir , int *i, int *j, Pessoas *A)
{
  Pessoas x,w;
  *i = Esq;
  *j = Dir;
  x = A[(*i + *j) / 2];
  do{
    while(x.Chave>A[*i].Chave)(*i)++;
    while(x.Chave<A[*j].Chave) (*j)--;

    if(*i<=*j){
        w = A[*i];
        A[*i]=A[*j];
        A[*j]=w;
        (*i)++;(*j)--;
    }
  }while(*i<=*j);
}

void Ordena(int Esq,int Dir, Pessoas *A)
{
    int i,j;
    Particao(Esq,Dir,&i,&j,A);
    //imprime
    if(Esq<j)
        Ordena(Esq,j,A);
    if(i<Dir)
        Ordena(i,Dir,A);
}

void QuickSort(Pessoas *A,int n)
{
  Ordena(1,n,A);
}

float mediana_final(int dir, int esq, int meio)
{
  int v[3] = {dir, esq, meio};
  int i, maior, menor, mediana;

  maior = v[0];
  for(i=1; i<3; i++)
    if (v[i]>maior) maior = v[i];

  menor = v[0];
  for(i=1; i<3; i++)
    if (v[i]<menor) menor = v[i];

  for(i=0; i<3; i++)
    if (v[i]!=maior || v[i]!=menor) mediana = v[i];

  return mediana;
}

int main(int argc, char * argv[])
{
  int n, i;
  Pessoas *P;

  printf("Digite a quantidade: "); scanf("%d",&n);

  P = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  printf("\n\nPreencha o vetor com numero e nome respectivamente: \n");
  for(i=1; i<=n; i++){
    scanf("%ld ", &(P[i].Chave));
    fgets(P[i].name, 100, stdin);
    P[i].name[strlen(P[i].name) - 1] = '\0';
  }

  QuickSort(P, n);

  printf("\n");
  for(i=1; i<= n; i++){
    printf("%ld %s\n", P[i].Chave, P[i].name);
  }

  int dir, esq, meio, mediana;
  dir = P[1].Chave;
  esq = P[n].Chave;
  meio = P[(1+n)/2].Chave;
  printf("\n\n %d %d %d\n", dir, esq, meio);

  mediana = mediana_final (dir, esq, meio);
  printf ("\n\nA mediana entre os termos encontrados eh: %d\n\n",mediana);

  return 0;
}