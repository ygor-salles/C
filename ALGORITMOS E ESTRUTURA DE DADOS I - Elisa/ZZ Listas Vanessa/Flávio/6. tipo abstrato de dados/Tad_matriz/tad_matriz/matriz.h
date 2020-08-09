/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matriz.h
 * Author: fla_e
 *
 * Created on 14 de Agosto de 2017, 22:23
 */

#ifndef MATRIZ_H
    typedef struct matriz;
    matriz mat;
    mat cria_mat (int lin, int col); //Aloca e retorna matriz m por n
    void libera_mat (float **v); //Libera a memória de uma matriz
    float acessa (int lin, int col, float **v);  //Retorna o valor do elemento [i][j]
    void atribui (int lin, int col, float **v); //Atribui valor ao elemento [i][j]
    int linhas (float **v); //Retorna o no. de linhas da matriz
    int colunas (float **v) //Retorna o no. de colunas da matriz
    
#endif /* MATRIZ_H */

