#include<stdio.h>
#include<stdlib.h>

/*1. Usando a estratégia acima, escrever uma função que retorne o valor mínimo e máximo
de uma sequência de n valores fornecidos pelo usuário. A leitura dos valores digitados
no teclado deve ser feita dentro da função. Contudo, a quantidade de valores a ser lido
(n) deve ser um parâmetro de entrada da função. */

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
