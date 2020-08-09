#include<stdio.h>
#include<stdlib.h>

/* 2. Escreva uma função que receba dois vetores A e B de números inteiros de tamanho = 30 e altere os elementos do segundo vetor somando os elementos correspondentes de A e B.
Como exemplo:
A = {10,20,30,40}
B = {1,2,3,4}, depois da chamada função B = {11,22,33,44} */

void funcaoB (int va[], int vb[], int i)
{
    for (i=0; i<5; i++){
        vb[i] = va[i] + vb[i];
    }
    return ;
}

int main ()
{
    int va[5], vb[5], i;

    printf ("Vetor de A:\n");
    for (i=0; i<5; i++){
        printf ("Digite num: ");
        scanf (" %d",&va[i]);
    }

    printf ("\nVetor de B:\n");
    for (i=0; i<5; i++){
        printf ("Digite num: ");
        scanf (" %d",&vb[i]);
    }

    funcaoB(va, vb, i);
    printf ("\n\nDepois da chamada da funcao B: \n");
    for (i=0; i<5; i++){
        printf (" %d",vb[i]);
    }
    printf ("\n");

    return 0;
}

