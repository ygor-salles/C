#ifndef ARVORE_H
#define ARVORE_H

typedef struct noArvore noarvore;
typedef struct arvoreb arvore;

//cria a estrutura árvore vazia
arvore* criaarvore();

//verifica se a árvore está vazia. Retorna 1 se vazia e 0 se não vazia
int arvorevazia(arvore *a);

//busca um elemento na árvore - Implementação Iterativa. Retorna 1 se encontrou e 0 se não encontrou
int buscaelementoit(arvore *a, int elemento);

//insere um novo elemento na árvore - Implementação Iterativa
void insereelementoit(arvore *a, int elemento);

//percorrimento em ordem - Implementação Recursiva
void percorreemordem(noarvore *no);

//busca um elemento na árvore - Implementação Recursiva. Retorna 1 se encontrou e 0 se não encontrou
int buscaelementorec(noarvore *no, int elemento);

//insere um novo elemento na árvore - Implementação Recursiva
noarvore *insereelementorec(arvore *a, noarvore *aux, noarvore *novono);

//funcao que aloca o novo nó
noarvore *alocano(int elemento);

//retorna o nó raiz
noarvore *retornaraiz(arvore *a);

//altura da arvore
int altura(noarvore *no);

//maior valor da árvore
int maiorvalor(noarvore *no);

//menor valor da árvore
int menorvalor(noarvore *no);



#endif /* ARVORE_H */

