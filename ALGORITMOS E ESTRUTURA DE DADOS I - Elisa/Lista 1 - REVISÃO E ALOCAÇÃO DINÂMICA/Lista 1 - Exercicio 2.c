#include<stdio.h>
#include<stdlib.h>

/* 2. Escreva um programa que leia um número l de linhas e um número c de colunas. Em seguida,
um vetor V de tamanho l * c e uma matriz M com l linhas e c colunas devem ser alocados
dinamicamente. Seu programa deve executar as tarefas abaixo sequencialmente, através de
chamadas de funções:
(a) Preencher o vetor V com valores inteiros digitados pelo usuário.
(b) Imprimir o vetor V na tela.
(c) Preencher a matriz M, sequencialmente, com os valores do vetor V .
(d) Imprimir a matriz M na tela. */

int *alocar_vetor(int r);
void preenche_vetor(int r, int *v);
void imprime_vetor (int r, int *v);
int **alocar_matriz (int l, int c);
void preencher_matriz (int l, int c, int **m, int *v);
void imprimir_matriz (int l, int c, int **m);

int main ()
{
  int l, c, r;
  int *v, **m;

  printf ("Digite qtd de lihhas: "); scanf ("%d",&l);
  printf ("Digite qtd de colunas: "); scanf ("%d",&c);
  r = l*c;

  v = alocar_vetor(r);
  preenche_vetor(r, v);
  imprime_vetor (r, v);

  m = alocar_matriz(l, c);
  preencher_matriz(l, c, m, v);
  imprimir_matriz(l, c, m);
  
  free(v);
  free(m);

  return 0;
}

int *alocar_vetor(int r)
{
  int *v;
  v = (int*) malloc(r * sizeof(int));
  if (v==NULL)
    printf ("Memoria insuficente!");

  return v;
}

void preenche_vetor(int r, int *v)
{
  int i;
  printf ("\nDigite os valores: \n");
  for (i=0; i<r; i++)
    scanf ("%d",&v[i]);

  return ;
}

void imprime_vetor (int r, int *v)
{
  int i;
  printf ("\nVetor: \n");
  for (i=0; i<r; i++)
    printf (" %d",v[i]);

  return ;
}

int **alocar_matriz (int l, int c)
{
    int **m, i;
    m = (int**) malloc(l * sizeof(int*));
    if (m==NULL){
        printf ("Memoria insuficinte!");
        return NULL;
    }
    for (i=0; i<l; i++){
        m[i] = (int*) malloc(c * sizeof(int));
        if (m[i]==NULL)
            printf ("Memoria insuficiente!");
    }
    return m;
}

void preencher_matriz (int l, int c, int **m, int *v)
{
    int i, j, k=0;
    for (i=0; i<l; i++)
        for (j=0; j<c; j++){
            m[i][j] = v[k];
            k++;
        }

    return ;
}

void imprimir_matriz (int l, int c, int **m)
{
    int i, j;
    printf ("\n\nMatriz: \n");
    for (i=0; i<l; i++){
        for (j=0; j<c; j++)
            printf (" %d",m[i][j]);
        printf ("\n");
    }
    return ;
}
