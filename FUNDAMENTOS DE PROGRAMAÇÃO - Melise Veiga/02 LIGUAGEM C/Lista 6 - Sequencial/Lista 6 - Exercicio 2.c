#include<stdio.h>

/*2. Escreva um algoritmo para ler dois valores inteiros, efetuar e mostrar o resultado das
operações de adição, subtração e multiplicação do primeiro número pelo segundo.
Considere que o segundo número é sempre diferente de 0.*/

int main ()
{
    int x, y;
    printf ("Digite o valor de X: ");
    scanf ("%d",&x);
    printf ("Digite o valor de X: ");
    scanf ("%d",&y);
    if(y==0){
        printf ("\nO segundo numero deve ser diferente de 0!\n");
        return 0;
    }
    printf ("\nA adicao eh: %d",x+y);
    printf ("\nA subtracao eh: %d",x-y);
    printf ("\nA multiplicacao eh: %d",x*y);
    printf ("\nA divisao eh: %f\n",(float)x/y);
    return 0;
}
