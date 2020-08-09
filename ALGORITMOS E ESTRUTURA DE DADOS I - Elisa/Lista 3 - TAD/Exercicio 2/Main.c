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

    //Quest�o B1
    dados = aloca_atribui(n);

    //Quest�o B2
    maior_venda = maior_preco(n, dados);
    printf ("O maior pre�o de vendas �: R$%.2f\n",maior_venda);

    //Quest�o B3
    aumenta_preco(n, dados);

    //Quest�o B4
    maior_qtd = maior_quantidade(n, dados);
    printf ("\n\nO c�digo do produto com maior quantidade em estoque �: %d \n",maior_qtd);

    //Quest�o B5
    imprimir_produto(n, dados);

    //Quest�o B6
    imprimir_vetor (n, dados);

    return 0;
}
