#ifndef ARVORE_H
#define ARVORE_H

typedef struct noArvore noarvore;
typedef struct arvoreb arvore;

//cria a estrutura �rvore vazia
arvore* criaarvore();

//verifica se a �rvore est� vazia. Retorna 1 se vazia e 0 se n�o vazia
int arvorevazia(arvore *a);

//busca um elemento na �rvore - Implementa��o Iterativa. Retorna 1 se encontrou e 0 se n�o encontrou
int buscaelementoit(arvore *a, int elemento);

//insere um novo elemento na �rvore - Implementa��o Iterativa
void insereelementoit(arvore *a, int elemento);

//percorrimento em ordem - Implementa��o Recursiva
void percorreemordem(noarvore *no);

//busca um elemento na �rvore - Implementa��o Recursiva. Retorna 1 se encontrou e 0 se n�o encontrou
int buscaelementorec(noarvore *no, int elemento);

//insere um novo elemento na �rvore - Implementa��o Recursiva
noarvore *insereelementorec(arvore *a, noarvore *aux, noarvore *novono);

//funcao que aloca o novo n�
noarvore *alocano(int elemento);

//retorna o n� raiz
noarvore *retornaraiz(arvore *a);

//altura da arvore
int altura(noarvore *no);

//maior valor da �rvore
int maiorvalor(noarvore *no);

//menor valor da �rvore
int menorvalor(noarvore *no);



#endif /* ARVORE_H */
