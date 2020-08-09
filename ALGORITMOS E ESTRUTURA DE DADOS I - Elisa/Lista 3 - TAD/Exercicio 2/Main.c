#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "tad.h"

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int n, maior_qtd;
    Produto *dados;
    float maior_venda;

    printf ("Digite a quantidade de produtos: ");
    scanf ("%d",&n);
    printf ("\n");

    //Questão B1
    dados = aloca_atribui(n);

    //Questão B2
    maior_venda = maior_preco(n, dados);
    printf ("O maior preço de vendas é: R$%.2f\n",maior_venda);

    //Questão B3
    aumenta_preco(n, dados);

    //Questão B4
    maior_qtd = maior_quantidade(n, dados);
    printf ("\n\nO código do produto com maior quantidade em estoque é: %d \n",maior_qtd);

    //Questão B5
    imprimir_produto(n, dados);

    //Questão B6
    imprimir_vetor (n, dados);

    return 0;
}
