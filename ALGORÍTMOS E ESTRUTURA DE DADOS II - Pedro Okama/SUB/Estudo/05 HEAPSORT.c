HEAPSORT

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


COMPLEXIDADE: Em todos casos O(n logn)


Arvore n termos -> altura = log n

Condição de HEAP:

HEAP > encontrar os filhos:
direita = 2*i (2i)
esquerda = 2*i + 1 (2i+1)

HEAP > encontrar pai
i/2 -> se for ímpar desconsidera a casa decimal
Ex: 5/2 => Pai é 2

Os que não possui filhos respeitam a condição de HEAP

HEAP
Constroi O(n)
Insere/retira O(log n)
Array que respeita a condição de Heap