#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO QUICKSORT */
//Nesse Algoritmo só usaremos o tipo Chave, não usará o tipo name.

typedef struct TipoItem
{
    int Chave;
    char name[100];
} TipoItem;

void particao(int esq, int dir, int *i, int *j, TipoItem *A)
{
    TipoItem x, w;
    *i = esq;
    *j = dir;
    x = A[(*i + *j)/2]; //obtem o pivô
    do{
        while(x.Chave > A[*i].Chave) (*i)++;
        while(x.Chave < A[*j].Chave) (*j)--;
        if(*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++; (*j)--;
        }
    } while(*i < *j);
}

void ordena (int esq, int dir, TipoItem *A)
{
    int i, j;
    particao(esq, dir, &i, &j, A);
    if(esq < j) ordena(esq, j, A);
    if(i < dir) ordena(i, dir, A);
}

void quickSort(TipoItem *A, int n)
{
    ordena(1, n, A);
}

int main (int argc, char *argv[])
{
    TipoItem *A;
    int n=10, i;

    A = calloc(sizeof(TipoItem), n+1);
    printf("\nVetor Criado: \n");
    for (i=1; i<=n; i++){
        A[i].Chave = rand() % 100;
        printf (" %d",A[i].Chave);
    }

    printf("\n\n"); system("pause");

    quickSort(A, n);

    printf ("\n\nVETOR ORDENADO NO QUICKSORT: \n");
    for (i=1; i<=n; i++)
        printf (" %d",A[i].Chave);

    printf("\n\n"); system("pause");
    return 0;
}
