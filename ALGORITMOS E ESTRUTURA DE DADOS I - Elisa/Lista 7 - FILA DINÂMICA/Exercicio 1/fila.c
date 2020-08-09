// TAD para Fila Dinâmica Encadeada Simples

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Elemento *aux;
Senha *auxiliar;

// função para alocar memória do tipo Fila
Fila* criar_fila()
{
  Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
	/*a fila inicia-se vazia, portanto inicio e fim são iguais a NULL*/
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->tamanho = 0;
    }
    return fi;
}

Atendimento* criar_atendimento()
{
  Atendimento *fi = (Atendimento*) malloc(sizeof(Atendimento));
    if(fi != NULL){
	/*a fila inicia-se vazia, portanto inicio e fim são iguais a NULL*/
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->tamanho = 0;
    }
    return fi;
}


// função para liberar memória
int liberar_fila(Fila *fi)
{
  if(fi->inicio == NULL ){
		printf("\n Fila vazia!!");
	}else{
		aux = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(aux);
			aux = fi->inicio;
		}while(aux != NULL);
    fi->tamanho = 0;
	}

  return 1;
}

int liberar_atendimento(Atendimento *fi)
{
  if(fi->inicio == NULL ){
		printf("\n Sem atendimentos!!");
	}else{
		auxiliar = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(auxiliar);
			auxiliar = fi->inicio;
		}while(auxiliar != NULL);
    fi->tamanho = 0;
	}

  return 1;
}

void imprimir_senha_por_mesa(Atendimento *fi, int mesa)
{
  if(fi->inicio == NULL ){
		printf("\n Sem atendimentos!!");
	}else{
		auxiliar = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			if(mesa == 1) printf("Mesa Negocial: %c%c%d\n", auxiliar->tipo, auxiliar->perfil, auxiliar->senha);
			else printf("Mesa Caixa: %c%c%d\n", auxiliar->tipo, auxiliar->perfil, auxiliar->senha);
			free(auxiliar);
			auxiliar = fi->inicio;
		}while(auxiliar != NULL);
    fi->tamanho = 0;
	}

}

//****************************************************************************************************************
// função para obter o tamanho da fila
int tamanho_fila(Fila *fi)
{
  if(fi == NULL) return 0;
  else return fi->tamanho;
}

int enfileirar(Fila *fi, int n)
{
  /*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
	Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
	novo->num = n;
	novo->prox = NULL;
	/*caso a fila esteja vazia, o elemento inserido será o primeiro e o último */
	if(fi->inicio == NULL){
		fi->inicio = novo;
		fi->fim = novo;
    fi->tamanho++;
	/*caso a fila ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila*/
	}else{
		fi->fim->prox = novo;
		fi->fim = novo;
    fi->tamanho++;
	}

  return 1;
}

int enfileirarAtendimento(Atendimento *fi, int n, char type, char profile)
{
  /*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
	Senha *novo =(Senha*) malloc(sizeof(Senha));
	novo->senha = n;
	novo->tipo = type;
	novo->perfil = profile;
	novo->prox = NULL;
	/*caso a fila esteja vazia, o elemento inserido será o primeiro e o último */
	if(fi->inicio == NULL){
		fi->inicio = novo;
		fi->fim = novo;
    fi->tamanho++;
	/*caso a fila ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila*/
	}else{
		fi->fim->prox = novo;
		fi->fim = novo;
    fi->tamanho++;
	}

  return 1;
}

int desenfileirar(Fila *fi)
{
  if(fi == NULL || fi->tamanho == 0){
		printf("\n Fila Vazia!!");
    return 0;
	}else{
		aux = fi->inicio;
		int x = aux->num;
		//printf(" %d removido!", fi->inicio->num);
		fi->inicio = fi->inicio->prox;
		free(aux);
    fi->tamanho--;
		return x;
	}
}
// função para buscar o elemento que está na posição 'pos'
int buscar_posicao(Fila *fi, int pos)
{
  if(fi == NULL || fi->tamanho == 0 || pos > fi->tamanho){
    return 0;
	}else{
    int i = 0;
    pos--;
		aux = fi->inicio;
		while(aux != NULL && i < pos){
			aux = aux->prox;
      i++;
		}
    return aux->num;
	}
}


// função para buscar o elemento código na lista
int buscar_dado(Fila *fi, int codigo)
{
  if(fi == NULL || fi->tamanho == 0){
		printf("\nFila Vazia!!");
    return 0;
	}else{
		aux = fi->inicio;
		do{
			if(aux->num == codigo)
        return codigo;
			aux = aux->prox;
		} while(aux != NULL);
	}

  return 0;
}
// função para imprimir a fila
int imprimir(Fila *fi)
{
  if(fi == NULL || fi->tamanho == 0){
		printf("\nFila Vazia!!");
    return 0;
	}else{
		aux = fi->inicio;
		do{
			printf(" %d ", aux->num);
			aux = aux->prox;
		} while(aux != NULL);
	}

  return 1;
}

int imprimirAtendimento(Atendimento *xp)
{
		auxiliar = xp->inicio;
		do{
			printf(" %c%c%d ", auxiliar->tipo, auxiliar->perfil, auxiliar->senha);
			auxiliar = auxiliar->prox;
		} while(auxiliar != NULL);

  return 1;
}

int buscarAtendimento(Atendimento *xp, Atendimento *mesa)
{
	Senha s;
  if(xp->tamanho == 0){
		//printf("\nFila vazia!!");
    return 0;
	}else{
		if(xp->inicio == xp->fim) xp->fim = NULL;

		auxiliar = xp->inicio;
		xp->inicio = xp->inicio->prox;

		enfileirarAtendimento(mesa, auxiliar->senha, auxiliar->tipo, auxiliar->perfil);

		free(auxiliar);
		xp->tamanho--;
		return 1; 
	}
}

