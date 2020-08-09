/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vanessa
 *
 * Created on 16 de Agosto de 2017, 20:09
 */

#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

/*
 * 
 */
int main() 
{
    int m, n;
    mat *mt;
    
    printf("Digite a quantidade de linhas da matriz : ");
    scanf("%d", &m);
    printf("Digite a quantidade de colunas da matriz : ");
    scanf("%d", &n);
    mt = cria(m, n);
    printf("\nMatriz alocada com sucesso! A matriz possui %d linhas e %d colunas\n", linhas(mt), colunas(mt));
    preencheAleatoriamente(mt);
    imprimeMatriz(mt);
    printf("A posicao %dx%d da matriz possui o valor : %0.2f\n", 2,0, acessa(mt, 2, 0));
    atribui(mt, 2, 0, 58.67);
    printf("A posicao %dx%d da matriz possui o valor : %0.2f\n", 2,0, acessa(mt, 2, 0));
    libera(mt);

    return (EXIT_SUCCESS);
}

