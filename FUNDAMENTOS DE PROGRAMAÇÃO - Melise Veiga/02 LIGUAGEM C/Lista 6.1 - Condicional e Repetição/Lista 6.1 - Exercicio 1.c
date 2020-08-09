#include<stdio.h>

/* Ler um número e verificar se o número é par ou impar. Em C, o operador % retorna o resto
da divisão.*/

int main ()
{
    int num;
    printf ("Digite um numero inteiro: ");
    scanf ("%d",&num);

    if (num%2==0){
        printf ("\n PAR \n\n");
    }
    else{
        printf ("\n IMPAR \n\n");
    }
    return 0;
}
