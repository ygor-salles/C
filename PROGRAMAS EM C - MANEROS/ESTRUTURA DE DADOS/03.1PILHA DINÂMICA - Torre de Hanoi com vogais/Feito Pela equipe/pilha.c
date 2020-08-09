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

int empilhar(Pilha *pi, char l)
{
	Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
	novo->vogal = l;

	novo->prox = pi->topo;
	pi->topo = novo;
	pi->tamanho++;

  return 1;
}

char desempilhar(Pilha *pi)
{
  if(pi == NULL || pi->tamanho == 0){
		printf("\n Pilha Vazia!!");
    return 0;
	}else{
		aux = pi->topo;
		char x = aux->vogal;

		pi->topo = pi->topo->prox;
		free(aux);
    pi->tamanho--;
		return x;
	}
}

int imprimir(Pilha *t1, Pilha *t2, Pilha *t3)
{
  if(t1 == NULL || t1->tamanho == 0){
		printf("\nPilha Vazia!!");
	}else{
		aux = t1->topo;
		do{
			printf(" \n|%c|", aux->vogal);
			aux = aux->prox;
		} while(aux != NULL);
	}

	printf("\n");

	if(t2->tamanho == 0){
		printf("\nPilha Vazia!!");
	}else{
		aux = t2->topo;
		do{
			printf(" \n|%c|", aux->vogal);
			aux = aux->prox;
		} while(aux != NULL);
	}

	printf("\n");

	if(t3->tamanho == 0){
		printf("\nPilha Vazia!!");
	}else{
		aux = t3->topo;
		do{
			printf(" \n|%c|", aux->vogal);
			aux = aux->prox;
		} while(aux != NULL);
	}

  return 1;
}