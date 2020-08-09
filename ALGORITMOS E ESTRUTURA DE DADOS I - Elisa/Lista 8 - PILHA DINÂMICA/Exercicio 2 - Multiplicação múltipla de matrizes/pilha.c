// TAD para Pilha sDinâmica Encadeada Simples

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Elemento *aux;

// função para alocar memória do tipo Pilha
Pilha* criar_pilha()
{
  Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL;
        pi->tamanho = 0;
    }
    return pi;
}

// função para liberar memória
int liberar_pilha(Pilha *pi)
{
  if(pi->tamanho == 0 ){
		printf("\n Pilha vazia!!");
		free(pi);
	}else{
		aux = pi->topo;
		do{
			pi->topo = pi->topo->prox;
			free(aux);
			aux = pi->topo;
		}while(aux != NULL);
		printf("\n Pilha vazia!!");
		free(pi);
	}

  return 1;
}

int empilhar(Pilha *pi, int *m)
{
	Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
	novo->m = (int*)malloc(9*sizeof(int));
	for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      novo->m[i*3+j] = m[i*3+j];
    }
  }

	novo->prox = pi->topo;
	pi->topo = novo;
	pi->tamanho++;

  return 1;
}

int* desempilhar(Pilha *pi)
{
  if(pi == NULL || pi->tamanho == 0){
		printf("\n Pilha Vazia!!");
    return 0;
	}else{
		aux = pi->topo;
		int *x = (int*)malloc(9*sizeof(int));
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				x[i*3+j] = aux->m[i*3+j];
			}
		}

		pi->topo = pi->topo->prox;
		free(aux);
    pi->tamanho--;
		return x;
	}
}

int imprimir(Pilha *t1)
{
  if(t1 == NULL || t1->tamanho == 0){
		printf("\nPilha Vazia!!");
	}else{
		aux = t1->topo;
		do{
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				printf(" %d ",aux->m[i*3+j]);
			}
			printf("\n");
  	}
			aux = aux->prox;
			printf("\n");
		} while(aux != NULL);
	}

  return 1;
}