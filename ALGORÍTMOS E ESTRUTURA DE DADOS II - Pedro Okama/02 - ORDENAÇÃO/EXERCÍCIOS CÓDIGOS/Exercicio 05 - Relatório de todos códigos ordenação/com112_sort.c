#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

Desordenados *criaNumero(int n) {
    Desordenados *d;
    d = (Desordenados*) malloc(sizeof (Desordenados));
    if (!d) {
        printf("Erro ao alocar os números\n");
        exit(1);
    }
    d->v = (int*) malloc(n * sizeof (int));
    if (!d->v) {
        printf("Erro ao alocar a memória!");
        exit(1);
    }
    d->n = 0;
    d->comp = 0;
    d->mov = 0;
    return d;
    //Código melhorado
}

//Versão Melhorada 2 do Bubble Sort

void bubbleSort2(Desordenados *d) {
    int i, j, houve_troca = 1, aux;
    d->comp = 0, d->mov = 0;
    //MOSTRANDO OS NÚMEROS DESORDENADOS
    i = 1;
    while (i <= d->n && houve_troca == 1) {
        houve_troca = 0;
        for (j = 0; j < d->n - 1; j++) {
            (d->comp)++;
            if (d->v[j] > d->v[j + 1]) {
                (d->mov)++;                aux = d->v[j];
                d->v[j] = d->v[j + 1];
                d->v[j + 1] = aux;
                houve_troca = 1;
            }
        }
        i++;
    }
}

//Selection Sort

void selectionSort(Desordenados *d) {
    int i, j, eleito, menor, pos;
    d->comp = 0, d->mov = 0;
    for (i = 0; i < d->n - 1; i++) {
        eleito = d->v[i];
        menor = d->v[i + 1];
        pos = i + 1;
        (d->mov)++;
        for (j = i + 1; j < d->n; j++) {
            (d->comp)++;
            if (d->v[j] < menor) {
                menor = d->v[j];
                pos = j;
            }
        }
        if (menor < eleito) {
            (d->mov)++;
            d->v[i] = d->v[pos];
            d->v[pos] = eleito;
        }
    }
}


//Inserction Sort

void insertionSort(Desordenados *d) {
    int i, j, eleito;
    d->comp = 0, d->mov = 0;
    for (i = 1; i <= d->n - 1; i++) {
        (d->comp)++;
        eleito = d->v[i];
        j = i - 1;
        while (j >= 0 && d->v[j] > eleito) {
            (d->comp)++;
            (d->mov)++;
            d->v[j + 1] = d->v[j];
            j--;
        }
        d->v[j + 1] = eleito;
    }
}

//Merge Sort - Recursiva

void mergeSort(Desordenados *d, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(d, inicio, meio);
        mergeSort(d, meio + 1, fim);
        merge(d, inicio, fim, meio);
    }
}

//Merge Sort - Ordenação

void merge(Desordenados *d, int inicio, int fim, int meio) {
    int posLivre, inicio_v1, inicio_v2, i;
    int *aux = (int*) malloc(d->n * (sizeof (int)));
    //d->comp = 0, d->mov = 0;
    if (!aux) {
        printf("Erro ao alocar a memória!");
        exit(1);
    }

    inicio_v1 = inicio;
    inicio_v2 = meio + 1;
    posLivre = inicio;

    while (inicio_v1 <= meio && inicio_v2 <= fim) {
        (d->comp)++;
        if (d->v[inicio_v1] <= d->v[inicio_v2]) {
            aux[posLivre] = d->v[inicio_v1];
            inicio_v1++;
        } else {
            aux[posLivre] = d->v[inicio_v2];
            inicio_v2++;
        }
        posLivre++;
    }
    //Caso haja números no primeiro vetor que não foram intercalados
    for (i = inicio_v1; i <= meio; i++) {
        aux[posLivre] = d->v[i];
        posLivre++;
    }
    //Caso haja número no segundo vetor que não foram intercalados
    for (i = inicio_v2; i <= fim; i++) {
        aux[posLivre] = d->v[i];
        posLivre++;
    }
    //Retorna os valores de aux para o vetor
    for (i = inicio; i <= fim; i++) {
        (d->mov)++;
        d->v[i] = aux[i];
    }
    free(aux);
}

//Quick Sort - Recursiva

void quickSort(Desordenados *d, int ini, int fim) {
    int pivo;
    if (ini < fim) {
        pivo = particao(d, ini, fim);
        quickSort(d, ini, pivo);
        quickSort(d, pivo + 1, fim);
    }
}

//Quick Sort - Troca

int particao(Desordenados *d, int ini, int fim) {
    int pivo, i, j;
    pivo = d->v[(ini + fim) / 2];
    i = ini - 1;
    j = fim + 1;

    while (i < j) {

        do {
            j--;
            (d->comp)++;
        } while (d->v[j] > pivo);

        do {
            i++;
            (d->comp)++;
        } while (d->v[i] < pivo);

        if (i < j) {
            (d->mov)++;
            int aux;
            aux = d->v[i];
            d->v[i] = d->v[j];
            d->v[j] = aux;
        }
    }
    return j;
}

//HeapSort - Cria Heap

void criaHeap (Desordenados *d, int ini,  int fim)
{
    int aux = d->v[ini];
    int j = ini*2+1;
    while (j <= fim){
        (d->comp)++;
        if (j<fim)
            if (d->v[j] < d->v[j+1])
                j = j+1;

        if (aux < d->v[j]){
            d->v[ini] = d->v[j];
            ini = j;
            j = 2*ini+1;
        }
        else
            j = fim+1;
    }
    d->v[ini] = aux;
    (d->mov)++;
}

//Heap Sort

void heapSort (Desordenados *d)
{
    int i, aux;
    for (i=(d->n-1)/2; i>=0; i--){
        criaHeap (d, i, d->n-1);
    }
    for (i=d->n-1; i>=1; i--){
        aux = d->v[0];
        d->v[0] = d->v[i];
        d->v[i] = aux;
        criaHeap (d, 0, i-1);
    }
}

