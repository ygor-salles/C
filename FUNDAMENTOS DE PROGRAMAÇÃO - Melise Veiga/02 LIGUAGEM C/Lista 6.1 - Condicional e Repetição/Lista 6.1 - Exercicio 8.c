#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Considere um caixa automático com apenas um repositório com capacidade para armazenar
1000 notas de 10 reais. Elabore um algoritmo para ler um valor e fornecer a quantidade de
notas correspondente a esse valor. O repositório começa sempre com 1000 notas. A cada
valor digitado, o seu algoritmo deve manter a quantidade de notas no repositório atualizada.
Caso o valor lido não possa ser fornecido por falta de notas, o algoritmo deve imprimir uma
mensagem indicando o fato. O algoritmo também deve imprimir uma mensagem se o valor
não for múltiplo de 10. Após o tratamento do valor lido, com a impressão da mensagem ou
o fornecimento da quantidade de notas, o procedimento deve ser repetido solicitando ao
usuário que digite um novo valor. O algoritmo deve parar quando um valor lido for
negativo ou quando não houver mais notas para o saque.*/

int main ()
{
    int caixa=1000, qtd, valor;
    printf ("\n\n O valor maximo disponivel eh de R$ 1.000,00");
    printf ("\n\n Digite um valor para saque: R$");
    scanf (" %d",&valor);

    if ((valor<0) || (valor>1000)){
        printf ("\n Nao ha notas suficiente no caixa, ou valor negativo digitado \n\n");
    }
    else{
    while ((valor<=caixa) && (valor>0)){
        if (valor%10 == 0){
            caixa = caixa-valor;
        }else{
            printf ("\n O valor digitado nao eh multiplo de 10!");
            printf ("\n Saque sera efetuado caso vlr > 10. E sera o vlr da div inteira por 10 \n\n");
            caixa = caixa-valor+(valor%10);
        }
        qtd = valor/10;
        printf ("\n A quantidade de notas de R$ 10,00 eh: %d\n\n",qtd);
        printf ("\n O valor atual do caixa eh de: R$%d\n\n",caixa);
        printf ("\n Digite um valor para saque: R$");
        scanf ("%d",&valor);
        }
    }
    printf ("\n Nao ha notas suficiente no caixa, ou valor negativo digitado \n\n");
    return 0;
}