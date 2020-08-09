#include <stdio.h>

/*Desenvolver um algoritmo que leia um número inteiro e verifique se é divisível por 5 e
divisível por 3 exiba uma mensagem com esta informação. Caso não seja, é necessário
exibir uma mensagem.*/

int main ()
{
    int num;
    printf ("Digite um número: ");
    scanf ("%d",&num);

    if (num%5 == 0) {
        printf ("\n e divisivel por 5 \n\n");
    }
    if (num%3 == 0){
        printf ("\n e divisivel por 3 \n\n");
    }
    if ((num%3 == 0) && (num%5 == 0)){
        printf ("\n e divisivel por 5 e por 3 \n\n");
    }
    return 0;
}
