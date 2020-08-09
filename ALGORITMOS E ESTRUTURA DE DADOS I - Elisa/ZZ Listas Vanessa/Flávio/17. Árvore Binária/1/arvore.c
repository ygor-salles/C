#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvore.h"

struct noArvore {
    int chave;
    struct noArvore *esq;
    struct noArvore *dir;
};

struct arvoreb {
    struct noArvore *raiz;
};

arvore* criaarvore() {
    arvore *a;
    a = (arvore*)malloc(sizeof(arvore));
    if(!a){
        printf("Erro ao alocar\n");
        exit(1);
    }
    a->raiz = NULL;
    return a;
}

int arvorevazia(arvore *a) {
    return (a->raiz == NULL);
}

int buscaelementoit(arvore *a, int elemento) {
    noarvore *aux = a->raiz;
    int achou = 0;
    while (!achou  && aux) {//while((achou==0) && (aux!=NULL))
        if( aux->chave == elemento) 
            achou = 1;
        else {
            if (elemento < aux->chave)
                aux = aux->esq;
            else 
                aux = aux->dir;      
            }
        }
    return achou;
}

void insereelementoit(arvore *a, int elemento) {
    noarvore *novono;
    noarvore *aux, *pai;
    
    //alocar o novono
    novono = (noarvore*)malloc(sizeof(noarvore));
    if (!novono) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    novono->chave = elemento;
    novono->dir = NULL;
    novono->esq = NULL;
    
    //verificar se a árvore é vazia
    if (a->raiz == NULL) {
        a->raiz = novono;
        return ;
    }
    
    //buscar a posição do novono
    aux = a->raiz;
    while(aux!=NULL) {
        pai = aux;
        if (elemento < aux->chave)
            aux = aux->esq;
        else 
            aux = aux->dir;
    }
    if (elemento < pai->chave) 
        pai->esq = novono;
    else 
        pai->dir = novono;
    return ;
}

void percorreemordem(noarvore *no) {
    if (no == NULL)
        return;
    percorreemordem(no->esq);
    printf("%d ", no->chave);
    percorreemordem(no->dir);
    return ;
}

int buscaelementorec(noarvore *no, int elemento) {
    if (no == NULL) 
        return 0;
    if (no->chave == elemento)
        return 1;
    if (elemento < no->chave)
        buscaelementorec(no->esq,elemento);
    else if (elemento > no->chave) 
        buscaelementorec(no->dir,elemento);
}

noarvore *insereelementorec(arvore *a, noarvore *aux, noarvore *novono) {
    if (a->raiz == NULL) {
        a->raiz = novono;
        exit(0);
    }
    if (aux == NULL) 
        return novono;
    if (novono->chave < aux->chave)
        aux->esq = insereelementorec(a, aux->esq, novono);
    else 
        aux->dir = insereelementorec(a, aux->dir, novono);
}

noarvore *retornaraiz(arvore *a) {
    return a->raiz;
}

int altura(noarvore *no) {
    int e,d;
    if (!no)
        return -1;
    else {
        e = altura(no->esq);
        d = altura(no->dir);
        if(e < d)
            return d+1;
        else
            return e+1;
    }
}

int maiorvalor(noarvore *no) {
    noarvore *aux = no;
    noarvore *pai;
    while (aux != NULL) {
        pai = aux;
        aux = aux->dir;
    }
    return pai->chave;
}

int menorvalor(noarvore *no) {
    noarvore *aux = no;
    noarvore *pai;
    while (aux != NULL) {
        pai = aux;
        aux = aux->esq;
    }
    return pai->chave;
    
}