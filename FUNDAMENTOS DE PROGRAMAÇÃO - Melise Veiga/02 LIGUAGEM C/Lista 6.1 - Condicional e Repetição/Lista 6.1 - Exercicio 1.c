#include<stdio.h>

/* Ler um n�mero e verificar se o n�mero � par ou impar. Em C, o operador % retorna o resto
da divis�o.*/

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
