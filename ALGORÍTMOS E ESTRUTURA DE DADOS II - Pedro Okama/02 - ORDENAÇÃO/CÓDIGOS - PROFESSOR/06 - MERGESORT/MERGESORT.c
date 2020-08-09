#include<stdio.h>
#include<stdlib.h>
#define MAX 100

/* ALGORITMO DE ORDENAÇÃO MERGESORT */
//Nesse Algoritmo só usaremos o tipo Chave, não usará o tipo name.

void merge(int *A, int esq, int mid, int dir)
{
    int aux[MAX];
    int i=esq, j=mid+1, k=0;

    while(i<=mid && j<=dir)
        if(A[i] <= A[j])
            aux[k++] = A[i++];
        else
            aux[k++] = A[j++];

    while(i <= mid)
        aux[k++] = A[i++];
    while(j <= dir)
        aux[k++] = A[j++];

    for(i=esq, k=0; i<=dir; i++, k++)
        A[i] = aux[k];
}

void mergeSort(int *A, int esq, int dir)
{
    int mid = (esq + dir)/2;
    if(esq < dir){
        mergeSort(A, esq, mid);
        mergeSort(A, mid+1, dir);
        merge(A, esq, mid, dir);
    }
}

int main (int argc, char *argv[])
{
    int *A;
    int n=10, i;

    A = (int*) malloc(n*sizeof(int));
    printf("\nVetor Criado: \n");
    for (i=0; i<n; i++){
        A[i] = rand() % 100;
        printf (" %d",A[i]);
    }

    printf("\n\n"); system("pause");

    mergeSort(A, 0, n-1);

    printf ("\n\nVETOR ORDENADO NO MERGESORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i]);

    printf("\n\n"); system("pause");
    return 0;
}
