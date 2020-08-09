#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO INSERTIONSORT */

void insertionSort (int *V, int N)
{
    int i, j, aux;
    for (i=1; i<N; i++){
        aux = V[i];
        for (j=i; (j>0)&&(aux < V[j-1]); j--)
            V[j] = V[j-1];
        V[j] = aux;
    }

    printf ("\nVETOR ORDENADO INSERTIONSORT: \n");
    for (i=0; i<N; i++)
        printf (" %d",V[i]);
}

int main ()
{
    int *V, N=10, i;

    V = (int*) malloc(N*sizeof(int));
    printf("\nVetor Criado: \n");
    for (i=0; i<N; i++){
        V[i] = rand() % 100;
        printf (" %d",V[i]);
    }

    printf("\n\n"); system("pause");

    insertionSort(V, N);

    printf("\n\n"); system("pause");
    return 0;
}
