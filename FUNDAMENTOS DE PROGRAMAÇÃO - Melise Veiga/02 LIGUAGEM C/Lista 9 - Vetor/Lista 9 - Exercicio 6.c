#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que receba o total das vendas de cada vendedor de uma loja e armazene-as em um vetor.
Receba também o percentual de comissão a que cada vendedor tem direito e armazene-os em outro vetor.
Receba os nomes desses vendedores e armazene-os em um terceiro vetor. Existem apenas dez vendedores na
loja. Calcule e mostre:
º um relatório com os nomes dos vendedores e os valores a receber referentes à comissão;
º o total das vendas de todos os vendedores;
º o maior valor a receber e o nome de quem o receberá;
º o menor valor a receber e o nome de quem o receberá. */

int main ()
{
    float venda[10], receber[10], maior, menor, c1;
    int comissao[10], i;
    char nome[10], nome_menor, nome_maior;

    for (i=0; i<10; i++){
        printf ("Digite a inicial do seu nome: ");
        scanf (" %c",&nome[i]);
        printf ("Digite o total de venda: R$");
        scanf ("%f",&venda[i]);
        printf ("Digite o percentual de comissao: ");
        scanf ("%d",&comissao[i]);
        printf ("\n");
    }

    printf ("\nNome vendedor | Valor a Receber");
    c1 = 0;
    for (i=0; i<10; i++){
        c1 = c1+venda[i];
        receber[i] = venda[i]*((float)comissao[i]/100);
        printf ("\n   %c          |     R$%.2f        ",nome[i], receber[i]);
    }

    printf ("\n\nTotal de vendas de todos os vendedores: R$%.2f\n",c1);

    maior = receber[0];
    nome_maior = nome[0];
    for (i=1; i<10; i++){
        if (receber[i] > maior){
            maior = receber[i];
            nome_maior = nome[i];
        }
    }
    printf ("\nO maior valor eh %.2f de %c\n",maior, nome_maior);

    menor = receber[0];
    nome_menor = nome[0];
    for (i=1; i<10; i++){
        if (receber[i] < menor){
            menor = receber[i];
            nome_menor = nome[i];
        }
    }
    printf ("\nO menor valor eh %.2f de %c\n\n",menor, nome_menor);

    system ("pause");
    return 0;
}
