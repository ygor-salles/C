#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct matriz {
    int linhas;
    int colunas;
    float **v;
};

mat *cria (int m, int n) {
    mat *estrutura;
    float **mt;
    int i;
    
    //alocar a estrutura
    estrutura = (mat*) malloc(sizeof(mat));
    if(!estrutura) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    
    //alocar a matriz
    mt = (float **) malloc (m*sizeof(float*));
       if(!mt) {
            printf("Erro ao alocar as linhas da matriz\n");
            exit(1);
    }
    for (i=0; i<m; i++) {
        mt[i] = (float*) malloc(n*sizeof(float));
    }
        if(!mt) {
            printf("Erro ao alocar as colunas da matriz\n");
            exit(1);
    }
    //atribuir valores aos atributos da estrutura
    estrutura ->linhas = m;
    estrutura ->colunas = n;
    estrutura ->v = mt;
    
    return (estrutura);  
}

void libera (mat *m) {
    if(m) {
        free(m->v);
        free(m);
    }
    return;
}

float acessa (mat *m, int i, int j) {
    if (i<m->linhas && j<m->colunas) {
        return (m->v[i][j]);
    }
    return -1;
}

void atribui (mat *m, int i, int j, float valor) {
    if (i<m->linhas && j<m->colunas) {
        m->v[i][j] = valor;
    }
    return;
}

int linhas (mat *m) {
    return (m->linhas);
}

int colunas (mat *m) {
    return (m->colunas);
}

void preenchealeatoriamente (mat *m) {
    int i, j;
    for (i=0; i<m->linhas; i++) {
        for (j=0; j<m->colunas; j++) {
            m->v[i][j] = rand()%100;
        }
    }
    return ;
}

void imprime (mat *m) {
    int i, j;
    printf("\n");
    for (i=0; i<m->linhas; i++) {
        for (j=0; j<m->colunas; j++) {
            printf("%.2f ", m->v[i][j]);
        }
        printf("\n");
    }
}



