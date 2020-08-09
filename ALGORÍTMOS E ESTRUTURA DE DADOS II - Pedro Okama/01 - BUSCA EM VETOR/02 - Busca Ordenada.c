#include<stdio.h>
#include<stdlib.h>

/* BUSCA ORDENADA: Eu posso parar a busca antes,
ou seja até que o elemento do vetor seja maior do que estou proucurando caso não esteja no vetor*/

/* Melhora Nível 1 */

int buscaOrdenada (int *V, int N, int elem)
{
    int i;
    for(i=0; i<N; i++)
        if (elem == V[i])
            return i;
        else
            if (elem < V[i])
                return -1;

    return -1;
}

int main()
{
    int *V, N=10, i, elem, retorna;

    V = (int*) malloc(N*sizeof(int));
    printf ("\nPreencha o vetor com valores ordenados(menor para maior): \n");
    for (i=0; i<N; i++)
        scanf("%d",&V[i]);

    printf("\n"); system("pause");
    system("CLS");

    printf("\nVETOR: \n");
    for (i=0; i<N; i++)
        printf(" %d",V[i]);

    printf("\n\nDigite o elemento a ser buscado no vetor: "); scanf("%d",&elem);

    retorna = buscaOrdenada(V, N, elem);

    if (retorna == -1)
        printf("\nNao encontrado!\n");
    else
        printf("\nElemento encontrado, indice %d \n",retorna);

    return 0;
}
