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

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long contador;

typedef struct Pessoas
{
  int Chave;
  char name[100];
} Pessoas;

#include <string.h>

/** EDITAR APENAS AS 3 FUNCOES ABAIXO */

void bubble(Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos)
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

void selection(Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos)
{
    int i, j, min;
    Pessoas x;

    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++)
            if (P[j].Chave < P[min].Chave){
                min = j;
                ++(*num_movimentos);
            }

        x = P[min];
        P[min] = P[i];
        P[i] = x;
        ++(*num_comparacoes);
    }

    printf ("\nVETOR ORDENADO SELECTIONSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",P[i].Chave);
}

void insertion(Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos)
{
    int i, j, min;
    Pessoas x;

    for(i=2; i<=n; i++){
        x = P[i];
        j = i-1;
        P[0] = x;
        while(x.Chave < P[j].Chave){
            P[j+1] = P[j];
            j--;
            ++(*num_movimentos);
        }
        P[j+1] = x;
        ++(*num_comparacoes);
    }

    printf ("\nVETOR ORDENADO INSERTIONSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",P[i].Chave);
}


void copia_pessoas(Pessoas * destino, Pessoas * origem, int n)
{
    for(int i = 1; i <= n; i++)
        destino[i] = origem[i];

}


void verifica_ordenacao(Pessoas * P, int n)
{
    for(int i = 2; i <= n; i++)
        if(P[i].Chave < P[i-1].Chave){
            printf("Ordenacao invalida.\n");
            exit(EXIT_FAILURE);
        }
}


int main(int argc, char * argv[])
{
  int n, i;
  Pessoas * P, * Q;
  contador num_comparacoes, num_movimentos;

  printf ("Digite valor de N: "); scanf("%d",&n);

  P = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  Q = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  for(i=1; i<= n; i++){
    scanf("%d ", &(P[i].Chave));
   /* fgets(P[i].name, 100, stdin);
    P[i].name[strlen(P[i].name) - 1] = '\0'; */
  }

  copia_pessoas(Q, P, n);

  num_comparacoes = 0; num_movimentos = 0;
  bubble(P, n, &num_comparacoes, &num_movimentos);
  printf("%lu %lu\n", num_comparacoes, num_movimentos);

  verifica_ordenacao(P, n);
  copia_pessoas(P, Q, n);

  num_comparacoes = 0; num_movimentos = 0;
  selection(P, n, &num_comparacoes, &num_movimentos);
  printf("%lu %lu\n", num_comparacoes, num_movimentos);

  verifica_ordenacao(P, n);
  copia_pessoas(P, Q, n);

  num_comparacoes = 0; num_movimentos = 0;
  insertion(P, n, &num_comparacoes, &num_movimentos);
  printf("%lu %lu\n", num_comparacoes, num_movimentos);

  verifica_ordenacao(P, n);

  for(int i = 1; i <= n; i++)
    printf("%d \n", P[i].Chave);

  return 0;
}
