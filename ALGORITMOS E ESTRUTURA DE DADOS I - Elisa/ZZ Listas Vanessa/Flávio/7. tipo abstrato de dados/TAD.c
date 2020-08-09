/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"


struct matriz
{
    int linhas;
    int colunas;
    float **v;
};

mat *cria(int m, int n)
{
    mat *estrutura;
    float **mt;
    int i;
    
    //alocar a estrutura
    estrutura = (mat*)malloc(sizeof(mat));
    if (!estrutura)
    {
        printf("Erro ao alocar a estrutura\n");
        exit(1);
    }
    
    //alocar a matriz de float    
    //Sim, poderia alocar direto na variável v!
    mt = (float**)malloc(m*sizeof(float*));
    if (!mt)
    {
        printf("Erro ao alocar as linhas da matriz\n");
        exit(1);
    }
    for (i=0; i<m; i++)
    {
        mt[i] = (float*)malloc(m*sizeof(float));
        if (!mt[i])
        {
            printf("Erro ao alocar as colunas da matriz\n");
            exit(1);
        }
    }
    
    //atribuir os elementos à estrutura m
    estrutura->linhas = m;
    estrutura->colunas = n;
    estrutura->v = mt;
    
    return estrutura;    
}

void libera(mat *m)
{
    if(m)
    {
        free(m->v);
        free(m);
    }
    return;
}

float acessa(mat *m, int i, int j)
{
    if ((i<m->linhas) && (j<m->colunas))
    {
        return (m->v[i][j]);
    }
    printf("\nIndices fora da dimensao da matriz\n");
    return -1;
}

void atribui(mat *m, int i, int j, float elemento)
{
    if ((i<m->linhas) && (j<m->colunas))
    {
        m->v[i][j] = elemento;
    }
    else
        printf("\nIndices fora da dimensao da matriz\n");
    return;
}

int linhas(mat *m)
{
    return (m->linhas);
}

int colunas(mat *m)
{
    return (m->colunas);
}

void preencheAleatoriamente(mat *m)
{
    int i, j;
    
    for (i=0; i<m->linhas; i++)
    {
        for (j=0; j<m->colunas; j++)
        {
            m->v[i][j] = rand()%200;
        }
    }
    return;
}

void imprimeMatriz(mat *m)
{
    int i, j;
    
    for (i=0; i<m->linhas; i++)
    {
        for (j=0; j<m->colunas; j++)
        {
            printf("%0.2f  ", m->v[i][j]);
        }
        printf("\n");
    }
    return;
}
