#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "com112_sort.h"
#include "com112_file.h"
#include <time.h>

FILE *arquivo, *arquivo2;

void gerarNumeros(int n) {
    int i;
    arquivo = fopen("com112_entrada.txt", "w");
    fprintf(arquivo, "%d\n", n);
    fclose(arquivo);
    arquivo = fopen("com112_entrada.txt", "a");
    srand(time(NULL));
    for (i = 0; i < n; i++)
        fprintf(arquivo, "%d ", rand() % 100);
    fclose(arquivo);
}

void lerNumeros(Desordenados *d) {
    int i = 0;
    arquivo = fopen("com112_entrada.txt", "r");
    arquivo2 = fopen("com112_saida.txt", "w");
    fscanf(arquivo, "%d\n", &d->n);
    fprintf(arquivo2, "\tNúmeros desordenados:\n");
    while (i < d->n) {
        fscanf(arquivo, "%d ", &d->v[i]);
        fprintf(arquivo2, "%d ", d->v[i]);
        i++;
    }
    fclose(arquivo);
    fclose(arquivo2);
}

void desordenar(Desordenados *d) {
    int i = 0;
    arquivo = fopen("com112_entrada.txt", "r");
    fscanf(arquivo, "%d\n", &d->n);
    while (i < d->n) {
        fscanf(arquivo, "%d ", &d->v[i]);
        i++;
    }
    d->comp = 0 ;
    d->mov = 0;
    d->tinicio = 0;
    d->tfim = 0;
    fclose(arquivo);
}

void ordenados(Desordenados *d) {
    int i = 0;
    arquivo2 = fopen("com112_saida.txt", "a");
    fprintf(arquivo2, "\n\tNúmeros ordenados:\n");
    while (i < d->n) {
        fprintf(arquivo2, "%d ", d->v[i]);
        i++;
    }
    fclose(arquivo2);
}

void relatorioCompleto(Desordenados *d, FILE *arquivo3){
    fprintf(arquivo3, "\r\nNumero de elementos ordenados: %d", d->n);
    //fprintf(arquivo, "\nTempo de Execução: %d", d->temp);
    fprintf(arquivo3, "\r\nNumero de Comparações: %d", d->comp);
    fprintf(arquivo3, "\r\nNumero de Movimentação: %d\r", d->mov);
    fprintf(arquivo3, "\nTempo de execução: %d ms\n", d->time);
}
