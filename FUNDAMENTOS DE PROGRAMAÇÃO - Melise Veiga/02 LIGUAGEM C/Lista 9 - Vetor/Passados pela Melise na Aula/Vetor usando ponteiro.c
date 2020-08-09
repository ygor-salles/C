#include<stdio.h>
#include<stdlib.h>

/* Outra forma de denotar vetor, por ponteiro */

int main ()
{
    int v[] = {1, 2}, i, *p;
    p=v;

    for (i=0; i<2; i++){
        printf (" %d",*(v+i));
    }
    
    return 0;
}
