#include<stdio.h>
#include<stdlib.h>

/* 1. Escreva uma fun��o que receba um vetor V de n n�meros inteiros e tenha como valor de retorno
um novo vetor, alocado dinamicamente, com os elementos do vetor original em ordem reversa.
A fun��o deve ter como valor de retorno o ponteiro do vetor alocado, seguindo o prot�tipo:
float *reverso (int n, float *v)
Fa�a uma fun��o main para testar sua fun��o. Na fun��o main, n�o esque�a de liberar a
mem�ria alocada pela fun��o auxiliar. */

float *reverso (int n, float *v);

int main ()
{
    int n, i;
    float *v, *v2;

    printf ("Digite o valor de N: ");
    scanf ("%d",&n);

    v = (float*) malloc(n*sizeof(float));
    if (v == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        exit(1);
    }

    printf ("\nPreencha o vetor Dinamico: \n");
    for (i=0; i<n; i++)
        scanf ("%f",&v[i]);

    v2 = reverso (n, v);

    printf ("\nNovo Vetor: \n");
    for (i=0; i<n; i++)
        printf (" %.0f",v2[i]);

    printf ("\n");
    free(v);
    free(v2);
}

float *reverso (int n, float *v)
{
    int i, c;
    float *v2;
    c = n-1;

    v2 = (float*) malloc(n*sizeof(float));
    if (v == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        return NULL;
    }

    for (i=0; i<n; i++){
        v2[i] = v[c];
        c--;
    }

    return v2;
}
