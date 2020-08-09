#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO BUBBLESORT */

void bubbleSort(int *V, int n)
{
    int i, semafaro, aux, fim = n;
    do{
        semafaro = 0;
        for (i=0; i<fim-1; i++){
            if (V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                semafaro = i;
            }
        }
        fim--;
    } while (semafaro != 0);

    printf ("\n\nVETOR ORDENADO NO BUBBLESORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",V[i]);
}

//n deve receber uma nova variável(fim) pois na ultima interação ele terá um novo valor diferente do tamanho do vetor e imprimirá um vetor do tamnho do ultimo valor de n.

int main ()
{
    int *V, n=10, i;

    V = (int*) malloc(n*sizeof(int));
    printf("\nVetor Criado: \n");
    for (i=0; i<n; i++){
        V[i] = rand() % 100;
        printf (" %d",V[i]);
    }

    bubbleSort(V, n);

    printf("\n\n"); system("pause");
    return 0;
}
