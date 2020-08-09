#include<stdio.h>
#include<stdlib.h>

/*2. Escrever uma fun��o que tem como par�metros tr�s valores inteiros a, b e c e retorna a
posi��o do maior e a posi��o do menor valor. Exemplo: Se a = 7, b = 1 e c = 5, o
procedimento deve retornar 2 como a posi��o do menor e 1 como a posi��o do maior.
Use a fun��o no programa principal considerando tr�s valores digitados pelo usu�rio. */

void posicao (int a, int b, int c, int *maior, int *menor);

int main ()
{
    int a, b, c, maior, menor;
    printf ("Digite o valor de A, B, e C respectivamente: \n");
    scanf ("%d %d %d",&a, &b, &c);

    posicao (a, b, c, &maior, &menor);
    printf ("\nA posicao do maior eh: %d\n",maior);
    printf ("\nA posicao do menor eh %d\n",menor);
    return 0;
}

void posicao (int a, int b, int c, int *maior, int *menor)
{
    if (a>b && a>c){
        *maior = 1;
        if (b>c){
            *menor = 3;
        }
        else{
            *menor = 2;
        }
    }
    else if (b>a && b>c){
        *maior = 2;
        if (a>c){
            *menor = 3;
        }
        else{
            *menor = 1;
        }
    }
    else if (c>a && c>b){
        *maior = 3;
        if (a>b){
            *menor = 2;
        }
        else{
            *menor = 1;
        }
    }
    return ;
}
