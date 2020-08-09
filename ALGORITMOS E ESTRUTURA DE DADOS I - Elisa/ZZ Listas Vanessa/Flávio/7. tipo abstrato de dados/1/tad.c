#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

struct alunos {
    int cod;
    char nome[100];
    float notas[5];
};

al *cria ( int n) {
    int i,j;
    al *dados;
    dados = (al*) malloc (n*sizeof(al));
    if (!dados) {
        printf("Erro ao alocar\n");
        exit (1);
    }
    printf("\n");
    for (i=0; i<n; i++) {
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", dados[i].nome);
        printf("Digite o código do aluno: ");
        scanf("%d", &dados[i].cod);
        for(j=0; j<5; j++) {
            printf("Digite a nota %d: ",j+1);
            scanf("%f",&dados[i].notas[j]);
        }
        printf("\n");
    }
    return dados;
}

float media (int cod, int n, al *dados) {
    int i, j, aux;
    float med;
    for(i=0; i<n; i++) {
        if (dados[i].cod == cod) {
            aux = i;
        }
    }
    for (j=0; j<5; j++) {
        med += dados[aux].notas[j];
    }
    med = med/5;
    return med;
}

float mediamedia (int cod, int n, al *dados) {
    int i, j, aux;
    float medmed;
    for(i=0; i<n; i++) {
        for (j=0; j<5; j++) {
            medmed += dados[i].notas[j];
        }
    }    
    aux = n*5;
    medmed = medmed/aux;
    
    return medmed;
}

void libera (al *dados) {
    free(dados);
    return ;
}