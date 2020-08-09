/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ABP.h
 * Author: vanessa
 *
 * Created on 31 de Outubro de 2017, 11:10
 */

#ifndef ABP_H
#define ABP_H

typedef struct noArvore noArvore;
typedef struct arvore abp;

//cria a estrutura árvore vazia
abp* criaArvore();

//verifica se a árvore está vazia. Retorna 1 se vazia e 0 se não vazia
int arvoreVazia(abp *A);

//busca um elemento na árvore - Implementação Iterativa. Retorna 1 se encontrou e 0 se não encontrou
int buscaElementoIt(abp *A, int elemento);

//insere um novo elemento na árvore - Implementação Iterativa
void insereElementoIt(abp *A, int elemento);

//percorrimento em ordem - Implementação Recursiva
void percorreEmOrdem(noArvore *no);

//busca um elemento na árvore - Implementação Recursiva. Retorna 1 se encontrou e 0 se não encontrou
int buscaElementoRec(noArvore *no, int elemento);

//insere um novo elemento na árvore - Implementação Recursiva
noArvore *insereElementoRec(abp *A, noArvore *aux, noArvore *novoNo);

//funcao que aloca o novo nó
noArvore *alocaNo(int elemento);

//retorna o nó raiz
noArvore *retornaRaiz(abp *A);



#endif /* ABP_H */

