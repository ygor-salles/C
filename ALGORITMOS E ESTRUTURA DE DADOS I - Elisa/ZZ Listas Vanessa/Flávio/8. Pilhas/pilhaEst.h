/* 
 * File:   pilhaEst.h
 * Author: aluno
 *
 * Created on 30 de Agosto de 2017, 21:32
 */

#ifndef PILHAEST_H
#define	PILHAEST_H

#define tamMax 3

typedef struct pilha pilha;
 
//CriaPilha (cria a estrutura pilha vazia)
pilha *criaPilha();

//Push (inserir elemento na pilha)
void push(pilha *p, int elemento);

//Pop (remover elemento da pilha)
int pop(pilha *p);

//Topo (mostrar quem está no topo da pilha)
int topo(pilha *p);

//Esvazia (remove todos os elementos da pilha)
void esvazia(pilha *p);

//Esvazia (remove todos os elementos da pilha, imprimindo seus valores)
void esvaziaRetornando(pilha *p);

//pilhaVazia (verifica se a pilha está vazia)
int pilhaVazia(pilha *p);

//pilhaCheia (verifica se a pilha está cheia – estruturas estáticas)
int pilhaCheia(pilha *p);


#endif	/* PILHAEST_H */

