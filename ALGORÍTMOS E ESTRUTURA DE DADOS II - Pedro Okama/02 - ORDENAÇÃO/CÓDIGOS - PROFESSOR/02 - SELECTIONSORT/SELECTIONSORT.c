#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO SELECTIONSORT */
//Nesse Algoritmo só usaremos o tipo Chave, não usará o tipo name.

typedef struct TipoItem
{
    int Chave;
    char name[100];
} TipoItem;

void selectionSort (TipoItem *A, int n)
{
    int i, j, min;
    TipoItem aux;
    for (i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++)
            if (A[j].Chave < A[min].Chave)
                min = j;

        aux = A[min];
        A[min] = A[i];
        A[i] = aux;
    }

    printf ("\nVETOR ORDENADO SELECTION: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i].Chave);
}

int main (int argc, char *argv[])
{
    TipoItem *A;
    int n=10, i;

    A = (TipoItem*) malloc(n*sizeof(TipoItem));
    printf("\nVetor Criado: \n");
    for (i=0; i<n; i++){
        A[i].Chave = rand() % 100;
        printf (" %d",A[i].Chave);
    }

    printf("\n\n"); system("pause");

    selectionSort(A, n);

    printf("\n\n"); system("pause");
    return 0;
}
