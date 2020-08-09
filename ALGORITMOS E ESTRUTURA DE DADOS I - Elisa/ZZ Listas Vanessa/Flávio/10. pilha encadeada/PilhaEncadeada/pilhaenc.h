#ifndef PILHAENC_H
#define PILHAENC_H

typedef struct pil pilha;
typedef struct n no;

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


#endif /* PILHAENC_H */

