#include <stdio.h>

/*Desenvolver um algoritmo que leia um n�mero inteiro e verifique se � divis�vel por 5 e
divis�vel por 3 exiba uma mensagem com esta informa��o. Caso n�o seja, � necess�rio
exibir uma mensagem.*/

int main ()
{
    int num;
    printf ("Digite um n�mero: ");
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
