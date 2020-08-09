#include<stdio.h>
#include<stdlib.h>

/* BUSCA LINEAR */

int buscaLinear (int *V, int N, int elem)
{
    int i;
    for(i=0; i<N; i++)
        if (elem == V[i])
            return i;

    return -1;
}

int main()
{
    int *V, N=10, i, elem, retorna;

    V = (int*) malloc(N*sizeof(int));
    for (i=0; i<N; i++){
        V[i] = rand() % 50;
        printf (" %d",V[i]);
    }

    printf("\n\nDigite o elemento a ser buscado no vetor: "); scanf("%d",&elem);

    retorna = buscaLinear(V, N, elem);

    if (retorna == -1)
        printf("\nNao encontrado!\n");
    else
        printf("\nElemento encontrado, indice %d \n",retorna);

    return 0;
}
