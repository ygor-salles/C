#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO SELECTION */

void selectionSort (int *V, int N)
{
    int i, j, menor, troca;
    for (i=0; i<N-1; i++){
        menor = i;
        for (j=i+1; j<N; j++)
            if (V[j] < V[menor])
                menor = j;
        if (i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }

    printf ("\nVETOR ORDENADO SELECTIONSORT: \n");
    for (i=0; i<N; i++)
        printf (" %d",V[i]);

    return ;
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

    selectionSort(V, N);

    printf("\n\n"); system("pause");
    return 0;
}
