#include<stdio.h>
#include<stdlib.h>

/*1. Usando a estrat�gia acima, escrever uma fun��o que retorne o valor m�nimo e m�ximo
de uma sequ�ncia de n valores fornecidos pelo usu�rio. A leitura dos valores digitados
no teclado deve ser feita dentro da fun��o. Contudo, a quantidade de valores a ser lido
(n) deve ser um par�metro de entrada da fun��o. */

void funcao (int n, int *max, int *min)
{
    int i, valor;
    for (i=1; i<=n; i++){
        printf ("\nEntre com um valor: ");
        scanf ("%d",&valor);
        if (valor>*max){
            *max = valor;
        }
        if (valor<*min){
            *min = valor;
        }
    }
    return ;
}

int main ()
{
    int n, max, min;
    printf ("Digite o valor de N: ");
    scanf ("%d",&n);

    funcao (n, &max, &min);
    printf ("\nO maior valor da sequencia eh: %d\n",max);
    printf ("\nO menor valor da sequencia eh: %d\n",min);
    return 0;
}
