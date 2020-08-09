#include<stdio.h>
#include<math.h>

/* O cosseno de um ângulo X (em radianos) pode ser calculado utilizando-se a série
COS(X) = 1 – X
2
/2! + X4
/4!- X
6
/6! +, ...

Escrever um algoritmo que leia um valor para X, calcule e escreva o valor da soma dos 10
primeiros termos da série. Voce deve usar uma estrutura de repetição. */

int main ()
{
    int fat, i, x, expo=2, fatorial;
    float soma=1;

    printf ("Digite o valor inteiro de X: ");
    scanf ("%d",&x);

    for (i=2; i<=10; i++){
        fat=1;
        for(fatorial=expo; fatorial>=1; fatorial--){
            fat=fatorial*fat;
        }
        if (i%2==0){
            soma=soma-((pow(x,expo))/(float)fat);
        }
        else{
            soma=soma+((pow(x,expo))/(float)fat);
        }
        expo=expo+2;
    }
    printf ("\n\n A soma eh de: %f\n\n",soma);
    return 0;
}
