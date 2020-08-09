#include<stdlib.h>
#include<stdio.h>
#include "tad.h"
#include<string.h>

/* struct e processamento de dados */

struct pessoa
{
    char nome[50];
    int nascimento, cpf;
};

Pessoa *aloca()
{
    Pessoa *dados;
    dados = (Pessoa*) malloc(sizeof(Pessoa));
    if (!dados){
        printf ("\nERRO AO ALOCAR!");
        exit(1);
    }

    return dados;
}

void preenche(Pessoa *dados)
{
    printf ("Digite o nome: "); scanf (" %[^\n]",dados->nome);
    printf ("Digite nascimento, somente numeros: "); scanf ("%d",&dados->nascimento);
    printf ("Digite CPF: "); scanf ("%d",&dados->cpf);

    return ;
}

void imprime(Pessoa *dados)
{
    printf ("\nNome: %s",dados->nome);
    printf ("\nNascimento: %d",dados->nascimento);
    printf ("\nCPF: %d\n",dados->cpf);

    return ;
}
