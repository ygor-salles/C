#ifndef PILHAEST_H
#define PILHAEST_H

#define tamMax 3

typedef struct pilhaa pilha;

//criaPilha (cria a estrutura pilha vazia)
pilha *criapilha ();

//Push (inserir elemento na pilha)
void push(pilha *p, int elemento);

//Pop (remover elemento da pilha)
int pop(pilha *p);

//Topo (mostrar quem está no topo da pilha)
int topo(pilha *p);

//Esvazia (remove todos os elementos da pilha)
void esvazia(pilha *p);

//Esvazia (remove todos os elementos da pilha e imprime os valores)
void esvaziaretornando(pilha *p);

//pilhaVazia (verifica se a pilha está vazia)
int pilhavazia(pilha *p);

//pilhaCheia (verifica se a pilha está cheia – estruturas estáticas)
int pilhacheia(pilha *p);


#endif /* PILHAEST_H */

