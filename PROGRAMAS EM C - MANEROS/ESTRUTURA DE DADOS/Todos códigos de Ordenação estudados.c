#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* EXERCICIO - Fazer um menu de escolha de todos os algoritmos de ordenação estudados */

void bubbleSort0(int v[], int n);
void bubbleSort1(int v[], int n);
void bubbleSort2(int v[], int n);
void selectionSort(int v[], int n);
void insertionSort(int v[], int n);
void mergeSort(int v[], int inicio, int fim);
void merge(int v[], int inicio, int fim, int meio);
int particiona (int *V, int inicio, int fim);
void quickSort(int *V, int inicio, int fim);
void criaHeap (int *V, int i,  int f);
void heapSort (int *V, int n);
int menu(int v[], int n);
void mostraValores(int v[], int n);
void limpa_tela();

//Main

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int v[5], n = 5, x;
    x = menu(v, n);
    limpa_tela();
    while (x != 0) {
        x = menu(v, n);
        limpa_tela();
    }
    return 0;
}

//Mostra valores

void mostraValores(int v[], int n) {
    int i;
    //MOSTRANDO OS NÚMEROS ORDENADOS
    printf("\nNúmeros ordenados:    ");
    for (i = 0; i < n; i++) 
        printf("%d ", v[i]);

    printf("\n\n");
}

//Menu

int menu(int v[], int n) {
    int x, i, j;
    printf("--------------MÉTODOS DE ORDENAÇÃO--------------\n\n");
    printf("1 - Bubble Sort - Versão Simples\n");
    printf("2 - Bubble Sort - Versão Melhorada 1\n");
    printf("3 - Bubble Sort - Versão Melhorada 2\n");
    printf("4 - Selection Sort\n");
    printf("5 - Insertion Sort\n");
    printf("6 - Merge Sort\n");
    printf("7 - Quick Sort\n");
    printf("8 - Heap Sort\n");
    printf("0 - Sair\n");
    printf("\nDigite um número: ");
    scanf("%d", &x);
    //Sair do menu
    if (x == 0)
        return 0;
    //Número inválido
    if (x < 0 || x > 8) {
        printf("\nNúmero Inválido!\n\n");
        return x;
    }
    //Números para ordenar
    printf("\nDigite 5 números para ordenar: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    //Mostrando números desordenados
    printf("\nNúmeros desordenados: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    if (x == 1)
        bubbleSort0(v, n);
    if (x == 2)
        bubbleSort1(v, n);
    if (x == 3)
        bubbleSort2(v, n);
    if (x == 4)
        selectionSort(v, n);
    if (x == 5)
        insertionSort(v, n);
    if (x == 6)
        mergeSort(v, 0, n-1);
    if (x == 7)
        quickSort(v, 0, n-1);
    if (x == 8)
        heapSort(v, n);

    mostraValores(v, n);
    return x;
}

//Versão Simples do Bubble Sort

void bubbleSort0(int v[], int n) {
    int i, j, aux;
    //BUBBLE SORT - ORDENANDO
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

//Versão Melhorada 1 do Bubble Sort

void bubbleSort1(int v[], int n) {
    int i, j, aux;
    for (i = 1; i < n - 1; i++) {
        for (j = n - 1; j >= i; j--) {
            if (v[j] < v[j - 1]) {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
            }
        }
    }
}
//Versão Melhorada 2 do Bubble Sort

void bubbleSort2(int v[], int n) {
    int i, j, houve_troca = 1, aux;
    //MOSTRANDO OS NÚMEROS DESORDENADOS
    i = 1;
    while (i <= n && houve_troca == 1) {
        houve_troca = 0;
        for (j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                houve_troca = 1;
            }
        }
        i++;
    }
}

//Selection Sort

void selectionSort(int v[], int n) {
    int i, j, eleito, menor, pos;

    for (i = 0; i < n - 1; i++) {
        eleito = v[i];
        menor = v[i + 1];
        pos = i + 1;
        for (j = i + 1; j < n; j++) {
            if (v[j] < menor) {
                menor = v[j];
                pos = j;
            }
        }
        if (menor < eleito) {
            v[i] = v[pos];
            v[pos] = eleito;
        }
    }
}


//Inserction Sort

void insertionSort(int v[], int n) {
    int i, j, eleito;
    for (i = 1; i <= n - 1; i++) {
        eleito = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > eleito) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = eleito;
    }
}

//Merge Sort - Recursiva

void mergeSort(int v[], int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, fim, meio);
    }
}

//Merge Sort - Ordenação

void merge(int v[], int inicio, int fim, int meio) {
    int posLivre, inicio_v1, inicio_v2, i;
    int aux[5];
    inicio_v1 = inicio;
    inicio_v2 = meio + 1;
    posLivre = inicio;

    while (inicio_v1 <= meio && inicio_v2 <= fim) {
        if (v[inicio_v1] <= v[inicio_v2]) {
            aux[posLivre] = v[inicio_v1];
            inicio_v1++;
        } else {
            aux[posLivre] = v[inicio_v2];
            inicio_v2++;
        }
        posLivre++;
    }
    //Caso haja números no primeiro vetor que não foram intercalados
    for (i = inicio_v1; i <= meio; i++) {
        aux[posLivre] = v[i];
        posLivre++;
    }
    //Caso haja número no segundo vetor que não foram intercalados
    for (i = inicio_v2; i <= fim; i++) {
        aux[posLivre] = v[i];
        posLivre++;
    }
    //Retorna os valores de aux para o vetor
    for (i = inicio; i <= fim; i++) {
        v[i] = aux[i];
    }
}

//Função Particiona Quick Sort

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

//Fução Adm Quick Sort

void quickSort(int *V, int inicio, int fim)
{
    int pivo, i;
    if (fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

//Função CriaHeap

void criaHeap (int *V, int i,  int f)
{
    int aux = V[i];
    int j = i*2+1;
    while (j <= f){
        if (j<f)
            if (V[j] < V[j+1])
                j = j+1;

        if (aux < V[j]){
            V[i] = V[j];
            i = j;
            j = 2*i+1;
        }
        else
            j = f+1;
    }
    V[i] = aux;
}

//Função Heap Sort

void heapSort (int *V, int n)
{
    int i, aux;
    for (i=(n-1)/2; i>=0; i--){
        criaHeap (V, i, n-1);
    }
    for (i=n-1; i>=1; i--){
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        criaHeap (V, 0, i-1);
    }
}

//Limpa a Tela
void limpa_tela()
{
    printf("\n"); system("pause"); system("cls");
}
