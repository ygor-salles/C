#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que preencha um vetor com quinze n�meros, determine e mostre:
� o maior n�mero e a posi��o por ele ocupada no vetor;
� o menor n�mero e a posi��o por ele ocupada no vetor. */

int main ()
{
    int vet[15], i, maior, p_maior, menor, p_menor;

    for (i=0; i<15; i++){
        printf ("Digite num da posicao %d: ",i);
        scanf ("%d",&vet[i]);
    }

    maior = vet[0];
    for (i=1; i<15; i++){
        if (vet[i]>maior){
            maior = vet[i];
            p_maior = i;
        }
    }
    printf ("\n%d eh a posicao do maior que eh: %d\n",p_maior, maior);

    menor = vet[0];
    for (i=1; i<15; i++){
        if (vet[i]<menor){
            menor = vet[i];
            p_menor = i;
        }
    }
    printf ("\n%d eh a posicao do menor que eh: %d\n",p_menor, menor);

    return 0;
}
