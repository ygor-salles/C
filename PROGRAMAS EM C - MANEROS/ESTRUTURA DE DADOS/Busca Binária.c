#include<stdio.h>
#include<stdlib.h>

/* BUSCA ORDENADA BINÁRIA: Racho o vetor ao meio,
faço a comparação: se o elemento for menor que o valor do meio só irei proucurar na primeira metade do vetor menos o meio, 
se não, se ele for maior somente na segunda metade do vetor menos o meio, se ele for igual ao meio já retorna o meio */

/* Melhora Nível 2 */

int buscaBinaria (int V[], int N, int elem)
{
    int inicio, meio, fim;
    inicio = 0;
    fim = N-1;
    while (inicio <= fim){
        meio = (inicio + fim)/2;
        if(elem < V[meio])
            fim = meio-1;
        else if (elem > V[meio])
            inicio = meio+1;
        else
            return meio;
    }
    return -1;
}

int main()
{
    int V[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90}, N=10, elem, retorna, i;

    printf("\nVETOR: \n");
    for (i=0; i<N; i++)
        printf(" %d",V[i]);

    printf("\n\nDigite o elemento a ser buscado no vetor: "); scanf("%d",&elem);

    retorna = buscaBinaria(V, N, elem);

    if (retorna == -1)
        printf("\nNao encontrado!\n");
    else
        printf("\nElemento encontrado, indice %d \n",retorna);

    return 0;
}
