#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO BEBBLESORT */
//Nesse Algoritmo só usaremos o tipo Chave, não usará o tipo name.

typedef struct TipoItem
{
    int Chave;
    char name[100];
} TipoItem;

void bubbleSort(TipoItem *V, int n)
{
    int i, j;
    TipoItem aux;

    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1; j++) {
            if (V[j].Chave > V[j+1].Chave) {
                aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;
            }
        }
    }

    printf ("\n\nVETOR ORDENADO NO BUBBLESORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",V[i].Chave);

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

    bubbleSort(A, n);

    printf("\n\n"); system("pause");
    return 0;
}
