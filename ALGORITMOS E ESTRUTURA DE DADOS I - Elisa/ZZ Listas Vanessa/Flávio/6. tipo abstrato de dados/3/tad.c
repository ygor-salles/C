#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <string.h>


struct candidato {
    char identidade[9], nome[50], escola[20], profissao[20];
    int d,m,a;
};

cand *cria (char nomearquivo[], int *n) {
    FILE *arq;
    int i;
    cand *dados;
    //abrir o arquivo
    arq = fopen(nomearquivo, "r");
    if(!arq) {
        printf("Erro ao ler o arquivo\n");
        exit (1);
    }
    
    //ler quantidade de candidatos
    fscanf(arq, "%d", n);
    
    //alocar a lista de candidatos
    dados = (cand*) malloc(*n*sizeof(cand));
    
    //preencher a lista de candidatos
    for (i=0; i<*n; i++) {
        fscanf(arq, "%s %s %s %d %d %d %s\n", dados[i].identidade, dados[i].nome, dados[i].escola, &dados[i].d, &dados[i].m, &dados[i].a, dados[i].profissao);
    }
    fclose(arq);
    
    return dados;
}

void imprime (int n, cand *dados) {
    int i;
    printf("\n          DADOS\n\n");
    for (i=0; i<n; i++) {
        printf("Nome: %s\n", dados[i].nome);
        printf("Identidade: %s\n", dados[i].identidade);
        printf("Escolaridade: %s\n", dados[i].escola);
        printf("Profissão: %s\n", dados[i].profissao);
        printf("Data de Nascimento: %d/%d/%d\n\n", dados[i].d, dados[i].m, dados[i].a);
    }
  return ;  
}

void ident(int n, char id[], cand *dados) {
    int i, aux=0,j=-1;
    for (i=0; i<n; i++) {
        if(aux==strcmp(id,dados[i].identidade)) {
            j=i;
        }
    }
    if (j==-1) {
        printf("\nIdentidade não encontrada!\n\n");
        return ;
    }
    else {
          printf("\nNome: %s\n", dados[j].nome);
          printf("Identidade: %s\n", dados[j].identidade);
          printf("Escolaridade: %s\n", dados[j].escola);
          printf("Profissão: %s\n", dados[j].profissao);
          printf("Nascimento: %d/%d/%d\n", dados[j].d, dados[j].m, dados[j].a);
          printf("\n");
    }
    return ;
}

void prof(int n, char p[], cand *dados) {
    int i,aux;
    printf("\n          CANDIDATOS POR PROFISSÃO\n\n");
    for (i=0; i<n; i++) {
        if(aux==strcmp(p,dados[i].profissao)) {
            printf("%s\n",dados[i].nome);
        }
    }
    return ;
}