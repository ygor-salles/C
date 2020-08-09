#include<stdio.h>
#include<stdlib.h>

/*6. Ler um vetor A com 15 elementos. Construir um vetor B do mesmo tipo, sendo que cada elemento de B seja o fatorial
do elemento correspondente do vetor A. O fatorial deve ser elaborada a partir de uma função. */

void fatoracao (int vetorA[], long int vetorB[], int i, int j)
{
    for (j=vetorA[i]; j>=1; j--){
        vetorB[i] = vetorB[i] * j;
    }
    return ;
}

int main ()
{
    int vetA[15], i, j;
    long int vetB[15];

    for (i=0; i<15; i++){
        printf ("Digite num: ");
        scanf ("%d",&vetA[i]);
    }

    printf ("\nTodos o fatoriados: \n");
    for (i=0; i<15; i++){
        vetB[i] = 1;
        fatoracao (vetA, vetB, i, j);
        printf (" %d",vetB[i]);
    }

    printf ("\n");
    return 0;
}
