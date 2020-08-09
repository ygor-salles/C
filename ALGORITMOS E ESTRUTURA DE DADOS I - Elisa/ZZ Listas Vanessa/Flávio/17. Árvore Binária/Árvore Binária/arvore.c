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

void removeelementoit(arvore *a, int elemento) {
    noarvore *aux, *pai, *predecessor;
    if(!a->raiz) {
        printf("\nÁrvore vazia\n");
        return ;
    }
    //encontrar o nó a ser removido
    aux = a->raiz;
    pai = NULL;
    while (aux && aux->chave != elemento) {
        pai = aux;
        if (elemento < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    if (!aux) {
        printf("\nElemento não encontrado na árvorez\n");
        return;
    }    
    //verificar se o nó tem grau 2
    if (aux->esq && aux->dir) {
       predecessor = aux->esq;
       pai = aux;
       while (predecessor->dir) {
           pai = predecessor;
           predecessor = predecessor->dir;
       }
       aux->chave = predecessor->chave;
       aux = predecessor;
    }
    //chama a função remove it
    removeit(a,aux,pai);
    return ;
}

void removeit(arvore *a, noarvore *no, noarvore *pai) {
    if (!pai) {
        if (no->esq)
            a->raiz = no->esq;
        else {
            if(no->dir)
                a->raiz = no->dir;
            else 
                a->raiz = NULL;
        }
        free(no);
        return ;
    }
    //testar a relação do nó com o pai
    if(no->chave < pai->chave) {
        if (no->esq) 
            pai->esq = no->esq;
        else
            pai->esq = no->dir;
    }
    else {
        if (no->esq) 
            pai->dir = no->esq;
        else
            pai->dir = no->dir;
    }
    free(no);
    return;
}

void predecessor(noarvore *R, int elemento){
    
    if(R == NULL){
        printf("A árvore está vazia\n");
        return ; //árvore vazia
    }
    if(R->dir->chave == elemento || R->esq->chave == elemento){
        printf("O no predecessor do no %d eh: %d \n",elemento,R->chave); 
        return ;
    }
    if(R->chave < elemento){
        predecessor(R->dir,elemento);
        return ;
    }else{
        predecessor(R->esq,elemento);
        return ;
    }
    
}