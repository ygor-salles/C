#include<stdio.h>

/* 3) Faça uma função recursiva buscaLinear para realizar a pesquisa linear em um vetor. Se
a chave de pesquisa for encontrada, retorne o índice do vetor; caso contrário, retorne
–1. */

int busca (int vetor[], int valor, int i)
{
    if (valor>0 && valor<=5){
        if (vetor[i]==valor)
            return i;
        return busca(vetor, valor, i+1);
    }
    else{
        return -1;
    }
}

int main ()
{
    int vetor[5] = {1, 2, 3, 4, 5};
    int valor, i=0, resultado;

    printf ("Digite o valor de pesquisa: "); scanf ("%d",&valor);

    resultado = busca (vetor, valor, i);
    printf ("\n %d\n",resultado);

    return 0;
}
