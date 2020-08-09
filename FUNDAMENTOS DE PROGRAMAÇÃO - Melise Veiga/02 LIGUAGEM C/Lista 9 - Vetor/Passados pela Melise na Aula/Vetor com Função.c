#include<stdio.h>
#include<stdlib.h>

/* Realizar a troca de valor de 2 elementos */

void troca (int x[2])
{
    int aux;
    aux = x[0];
    x[0] = x[1];
    x[1] = aux;
    
    return ;
}

int main ()
{
    int v[] = {1, 2}, i;

    troca(v);
    for (i=0; i<2; i++){
        printf (" %d",v[i]);
    }
}
