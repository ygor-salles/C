#ifndef COM112_SORT_H
#define COM112_SORT_H
#include <time.h>

typedef struct numerosDesordenados {
    int *v, n, mov, comp, time;
    clock_t tinicio, tfim;
}Desordenados;
typedef struct numerosDesordenados Desordenados;


Desordenados *criaNumero(int n);
void bubbleSort2(Desordenados *d);                              //Bubble Sort Melhorado 2
void selectionSort(Desordenados *d);                            //Selection Sort
void insertionSort(Desordenados *d);                            //Insertion Sort
void mergeSort(Desordenados *d, int inicio, int fim);           //Merge Sort - Recursiva
void merge(Desordenados *d, int inicio, int fim, int meio);     //Merge Sort - Intercala
void quickSort(Desordenados *d, int ini, int fim);              //Quick Sort - Recursiva
int particao(Desordenados *d,  int ini, int fim);                //Quick Sort - Inverte
void criaHeap (Desordenados *d, int ini,  int fim);             //HeapSort - Cria Heap
void heapSort (Desordenados *d);                                //Heap Sort

#endif /* COM112_SORT_H */

