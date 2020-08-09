#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

struct produto
{
    int cod, qtd;
    float preco;
};

Produto *aloca_atribui(int n)
{
    int i;
    Produto *dados;
    dados = (Produto*) malloc(n*sizeof(Produto));
    if (!dados){
        printf ("\nMEM�RIA INSUFICIENTE!");
        exit(1);
    }

    for (i=0; i<n; i++){
        printf ("Digite c�digo: "); scanf ("%d",&dados[i].cod);
        printf ("Digite quantidade: "); scanf ("%d",&dados[i].qtd);
        printf ("Digite pre�o: "); scanf ("%f",&dados[i].preco);
        printf ("\n");
    }
    return dados;
}

float maior_preco(int n, Produto *dados)
{
    int i;
    float maior;
    maior = dados[0].preco;
    for (i=0; i<n; i++)
        if (i>0)
            if (dados[i].preco > maior)
                maior = dados[i].preco;

    printf ("#################################################################\n");
    return maior;
}

void aumenta_preco(int n, Produto *dados)
{
    int i; float x;
    printf ("\nDigite a porcentagem de aumento: "); scanf ("%f",&x);
    printf ("Pre�os ap�s aumento:");
    for (i=0; i<n; i++){
        dados[i].preco = dados[i].preco + (dados[i].preco*(x/100));
        printf ("\nProduto [%d]: R$%.2f",dados[i].cod, dados[i].preco);
    }

    return ;
}

int maior_quantidade(int n, Produto *dados)
{
    int i, maior, aux;
    aux = dados[0].qtd;
    for (i=0; i<n; i++)
        if (i>0)
            if (dados[i].qtd > aux){
                aux = dados[i].qtd;
                maior = dados[i].cod;
            }

    return maior;
}

void imprimir_produto(int n, Produto *dados)
{
    int i, codigo;
    printf ("\nDigite c�digo do produto que deseja imprimir: ");
    scanf ("%d",&codigo);

    for (i=0; i<n; i++)
        if (codigo == dados[i].cod)
            printf ("C�digo: %d       Quantidade: %d      Pre�o: R$%.2f\n",dados[i].cod, dados[i].qtd, dados[i].preco);

    return ;
}

void imprimir_vetor (int n, Produto *dados)
{
    int i;
    printf ("\nVETOR: \n");
    for (i=0; i<n; i++)
        printf ("C�digo: %d       Quantidade: %d      Pre�o: R$%.2f\n",dados[i].cod, dados[i].qtd, dados[i].preco);

    return ;
}
