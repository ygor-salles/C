#include<stdio.h>
#include<stdlib.h>

int particiona (int *V, int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = V[inicio];

    while (esq < dir){
        while (V[esq] <= pivo)
            esq ++;
        while (V[dir] > pivo)
            dir--;
        if (esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;

    return dir;
}

void quickSort(int *V, int inicio, int fim)
{
    int pivo, i;
    if (fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

int main ()
{
    int *V, n=10, i, inicio, fim;

    V = (int*) malloc(n*sizeof(int));
    printf("\nVetor Criado: \n");
    for (i=0; i<n; i++){
        V[i] = rand() % 100;
        printf (" %d",V[i]);
    }

    quickSort(V, 0, 9);

    printf ("\n\nVETOR ORDENADO NO QUICKSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",V[i]);

    printf("\n\n"); system("pause");
    return 0;
}
