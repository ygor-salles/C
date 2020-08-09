/**
Nessa atividade voce devera' implementar 3 algoritmos de ordenacao
o bubble sort, o selection sort e o insertion sort
voce pode e deve usar os codigos das atividades passadas.

- A ordenacao e' so' por chave. Alguns algoritmos podem ser estaveis, outros nao.
- suas funcoes devem receber dois apontadores para o tipo 'contador' que deve ser
atualizado com o numero de comparacoes e com o numero de movimentos de registros de
cada algoritmo
- voce deve submeter sua solucao no run.codes conforme explicado em sala
**/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long contador;

typedef struct Pessoas
{
  int Chave;
  char name[100];
} Pessoas;

#include <string.h>

/** EDITAR APENAS AS 3 FUNCOES ABAIXO */

void insertionSort (Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos);
void selectionSort (Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos);
void bubbleSort(Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos);
void copia_pessoas(Pessoas *destino, Pessoas *origem, int n);
void verifica_ordenacao(Pessoas *P, int n);

int main ()
{
    Pessoas *P, *Q;
    int n, i;

    contador num_comparacoes, num_movimentos;

    printf ("Digite valor de N: "); scanf("%d",&n);

    P = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
    Q = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
    if(P==NULL){
        perror("Error while allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nPreencha o Vetor: \n");
    for (i=0; i<n; i++){
        scanf("%d",&P[i].Chave);
        /* fgets(P[i].name, 100, stdin);
        P[i].name[strlen(P[i].name) - 1] = '\0'; */
    }

    printf("\n"); system("pause");
    system("CLS");

    printf("VETOR PREENCHIDO: \n");
    for (i=0; i<n; i++)
        printf(" %d",P[i].Chave);

    copia_pessoas(Q, P, n);

    num_comparacoes = 0; num_movimentos = 0;
    selectionSort(P, n, &num_comparacoes, &num_movimentos);
    printf("\nComparacoes: %lu  Movimentos: %lu\n", num_comparacoes, num_movimentos);

    verifica_ordenacao(P, n);
    copia_pessoas(P, Q, n);

    num_comparacoes = 0; num_movimentos = 0;
    insertionSort(P, n, &num_comparacoes, &num_movimentos);
    printf("\nComparacoes: %lu  Movimentos: %lu\n", num_comparacoes, num_movimentos);

    verifica_ordenacao(P, n);
    copia_pessoas(P, Q, n);

    num_comparacoes = 0; num_movimentos = 0;
    bubbleSort(P, n, &num_comparacoes, &num_movimentos);
    printf("\nComparacoes: %lu  Movimentos: %lu\n", num_comparacoes, num_movimentos);

    printf("\n\n\n"); system("pause");
    return 0;
}

void selectionSort (Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos)
{
    int i, j, menor;
    Pessoas troca;
    for (i=0; i<n-1; i++){
        menor = i;
        for (j=i+1; j<n; j++){
            if (P[j].Chave < P[menor].Chave){
                menor = j;
            }
            ++(*num_comparacoes);
        }
        if (i != menor){
            troca = P[i];
            P[i] = P[menor];
            P[menor] = troca;
            ++(*num_movimentos);
        }

    }

    printf ("\n\n\nVETOR ORDENADO SELECTIONSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",P[i].Chave);

    return ;
}

void insertionSort (Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos)
{
    int i, j, semafaro;
    Pessoas aux;
    for (i=1; i<n; i++){
        aux = P[i];
        semafaro = 0;
        for (j=i; (j>0)&&(aux.Chave < P[j-1].Chave); j--){
            P[j] = P[j-1];
            semafaro = 1;
        }
        P[j] = aux;
        ++(*num_comparacoes);
        if (semafaro == 1)
            ++(*num_movimentos);
    }

    printf ("\n\nVETOR ORDENADO INSERTIONSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",P[i].Chave);
}

void bubbleSort(Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos)
{
    int i, continua, fim = n;
    Pessoas aux;
    do{
        continua = 0;
        for (i=0; i<fim-1; i++){
            if (P[i].Chave > P[i+1].Chave){
                aux = P[i];
                P[i] = P[i+1];
                P[i+1] = aux;
                continua = i;
                ++(*num_movimentos);
            }
            ++(*num_comparacoes);
        }
        fim--;
    } while (continua != 0);

    printf ("\n\nVETOR ORDENADO NO BUBBLESORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",P[i].Chave);
}

void copia_pessoas(Pessoas *destino, Pessoas *origem, int n)
{
    int i;
    for(i=0; i<n; i++)
        destino[i] = origem[i];
}

void verifica_ordenacao(Pessoas *P, int n)
{
    int i;
    for(i=1; i<n; i++)
        if(P[i].Chave < P[i-1].Chave){
            printf("Ordenacao invalida.\n");
            exit(EXIT_FAILURE);
        }
}
