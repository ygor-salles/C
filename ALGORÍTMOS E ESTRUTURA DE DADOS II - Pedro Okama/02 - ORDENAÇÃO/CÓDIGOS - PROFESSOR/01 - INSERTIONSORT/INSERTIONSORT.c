#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO INSERTIONSORT */
//Nesse Algoritmo só usaremos o tipo Chave, não usará o tipo name.

typedef struct TipoItem
{
    int Chave;
    char name[100];
} TipoItem;

void insertionSort (TipoItem *A, int n)
{
    int i, j, min;
    TipoItem aux;

    for(i=1; i<n; i++){
        aux = A[i];
        j = i;
        while((aux.Chave < A[j-1].Chave)&&j>0){
            A[j] = A[j-1];
            j--;
        }
        A[j] = aux;
    }

    printf ("\nVETOR ORDENADO INSERTIONSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i].Chave);

}

int main (int argc, char *argv[])
{
    TipoItem *A;
    int n=10, i;

    A = calloc(sizeof(TipoItem), n);
    printf("\nVetor Criado: \n");
    for (i=0; i<n; i++){
        A[i].Chave = rand() % 100;
        printf (" %d",A[i].Chave);
    }

    printf("\n\n"); system("pause");

    insertionSort(A, n);

    printf("\n\n"); system("pause");
    return 0;
}
