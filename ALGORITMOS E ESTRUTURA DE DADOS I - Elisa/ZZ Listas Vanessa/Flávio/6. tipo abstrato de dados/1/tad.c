#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <string.h>

struct cpf {
    char nome[50], cpf[11];
    int dia, mes, ano;
};

Cpf *cria (int alunos) {
    Cpf *dados;
    dados = (Cpf *) malloc (alunos*sizeof(Cpf));
    
    if(!dados) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    
    char n[50], c[12];
    int d, m, a;
    
    /*dados->ano = a;
    strcpy (dados->cpf, c);
    dados->dia = d;
    dados->mes = m;
    strcpy(dados->nome, n);*/
    
    return (dados);
}

void preenche (Cpf *dados, int alunos) {
    int i;
    
    for(i=0; i<alunos; i++) {
        
        printf("Digite seu nome: ");
        scanf(" %[^\n]", dados[i].nome);
        printf("Digite seu CPF: ");
        scanf(" %[^\n]",dados[i].cpf);
        printf("Digite o dia que nasceu: ");
        scanf("%d", &dados[i].dia);
        printf("Digite o mês que nasceu: ");
        scanf("%d",&dados[i].mes);
        printf("Digite o ano que nasceu: ");
        scanf("%d", &dados[i].ano);
        printf("\n");
    }
    return ;
}

void imprime (Cpf *dados, int alunos) {
    int i;
    for(i=0; i<alunos; i++) {
        
        printf("\n");
        printf("Nome: %s\n",dados[i].nome);
        printf("Cpf: %s\n",dados[i].cpf);
        printf("%d/%d/%d\n",dados[i].dia, dados[i].mes, dados[i].ano);
    }
    return ;
}