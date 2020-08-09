#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "com112_sort.h"
#include "com112_file.h"

double tExecBS = 0, tExecSS = 0, tExecIS = 0, tExecMS = 0, tExecQS = 0, tExecHS = 0; //Variáveis de tempo
clock_t tempo; //Variável de controle de tempo

int menu(Desordenados *d, FILE *arquivo3);
void relatorio(Desordenados *d);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n, escolha;
    FILE *arquivo3 = fopen("com112_relatorio.txt", "w");
    //Gerando números
    printf("Digite a quantidade de números para serem ordenados: ");
    scanf("%d", &n);
    Desordenados *d = criaNumero(n);
    gerarNumeros(n);
    lerNumeros(d);
    do {
        escolha = menu(d, arquivo3);
    } while ((escolha != 0) && (escolha < 8));
    fclose(arquivo3);
    return 0;
}

//Menu de opções

int menu(Desordenados *d, FILE *arquivo3)
{
    int x;
    printf("\n\n--------------MÉTODOS DE ORDENAÇÃO--------------\n\n");
    printf("1 - Bubble Sort - Versão Melhorada 2\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Quick Sort\n");
    printf("6 - Heap Sort\n");
    printf("7 - Relatório Geral\n");
    printf("0 - Sair\n");
    printf("Digite um número: ");
    scanf("%d", &x);
    //Sair do menu
    if (x == 0)
        return 0;
    //Número inválido
    if (x < 0 || x > 7) {
        printf("\nNúmero Inválido!\n\n");
        return x;
    }
    if (x == 1) {
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Bubble Sort.");
        bubbleSort2(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
    }
    if (x == 2) {
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Selection Sort.");
        selectionSort(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
    }
    if (x == 3) {
        fprintf(arquivo3, "\r\nMétodo Insertion Sort.");
        insertionSort(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
    }
    if (x == 4) {
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Merge Sort.");
        mergeSort(d, 0, d->n - 1);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
    }
    if (x == 5) {
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Quick Sort.");
        quickSort(d, 0, d->n - 1);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
    }
    if (x == 6) {
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Heap Sort.");
        heapSort(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
    }
    if (x == 7) {
        //Bubble Sort
        fprintf(arquivo3, "\r\nMétodo Bubble Sort.");
        d->tinicio = clock();
        bubbleSort2(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
        ordenados(d);
        relatorio(d);
        relatorioCompleto(d, arquivo3);
        desordenar(d);
        //Selection Sort
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Selection Sort.");
        selectionSort(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
        ordenados(d);
        relatorio(d);
        relatorioCompleto(d, arquivo3);
        desordenar(d);
        //Insertion Sort
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Insertion Sort.");
        insertionSort(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
        ordenados(d);
        relatorio(d);
        relatorioCompleto(d, arquivo3);
        desordenar(d);
        //Merge Sort
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Merge Sort.");
        mergeSort(d, 0, d->n - 1);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
        ordenados(d);
        relatorio(d);
        relatorioCompleto(d, arquivo3);
        desordenar(d);
        //Quick Sort
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Quick Sort.");
        quickSort(d, 0, d->n - 1);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
        ordenados(d);
        relatorio(d);
        relatorioCompleto(d, arquivo3);
        desordenar(d);
        //Heap Sort
        d->tinicio = clock();
        fprintf(arquivo3, "\r\nMétodo Heap Sort.");
        heapSort(d);
        d->tfim = clock();
        d->time = (double) (d->tfim - d->tinicio) / (CLOCKS_PER_SEC/1000);
        ordenados(d);
        relatorio(d);
        relatorioCompleto(d, arquivo3);
        desordenar(d);
        return 7;
    }
    ordenados(d);
    relatorio(d);
    relatorioCompleto(d, arquivo3);
    desordenar(d);
    return x;
}

//Imprime na tela o tempo de execução, número de movimentos e comparações

void relatorio(Desordenados *d) {
    printf("\n\nNumero de Comparações: %d", d->comp);
    printf("\nNumero de Movimentação: %d", d->mov);
    printf("\nTempo de Execução: %d ms", d->time);
}
