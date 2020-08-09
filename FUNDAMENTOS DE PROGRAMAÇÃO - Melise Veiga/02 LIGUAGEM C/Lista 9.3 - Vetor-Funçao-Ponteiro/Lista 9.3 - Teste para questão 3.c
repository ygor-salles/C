#include<stdio.h>
#include<stdlib.h>

/* 3. Assumindo que pulo[10] é um vetor do tipo int, quais das seguintes expressões referenciam o valor do terceiro elemento?
a) *(pulo + 2) b) *(pulo + 4) c) pulo + 4 d) pulo + 2 */

int main ()
{
    int i, pulo[10];

    for (i=0; i<10; i++){
        pulo[i] = rand() % 100;
        printf ("_%d_|",pulo[i]);
    }

    printf ("\n\nPulo 2, vetor posicao 3 eh: %d\n",*(pulo+2));

    return 0;

}
