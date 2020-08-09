#include<stdio.h>

/* Dados dois números inteiros positivos determinar quantas vezes o primeiro divide
exatamente o segundo. Se o primeiro não divide o segundo, o número de vezes exibido
deve ser zero. */

int main ()
{
    int num1, num2, total, i=1;

    printf ("Digite o valor de num1: ");
    scanf ("%d",&num1);
    printf ("Digite o valor de num2: ");
    scanf ("%d",&num2);

    if (num1%num2==0){
        total=num1/num2;
    while (total%num2==0){
        total=total/num2;
        i++;
    }
    printf ("\n\n A quantidade de vezes que o primeiro divide o segundo eh de: %d\n\n",i);
    }
    else{
        i=0;
        printf ("\n\n A quantidade de vezes que o primeiro divide o segundo eh de: %d\n\n",i);
    }
    return 0;
}
