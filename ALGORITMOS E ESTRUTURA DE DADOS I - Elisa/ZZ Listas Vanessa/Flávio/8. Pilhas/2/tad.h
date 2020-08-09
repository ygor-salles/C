#ifndef TAD_H
#define TAD_H
#define tammax 5

typedef struct pil pilha;
//criar pilha
pilha *criapilha();

//incluindo um elemento na pilha
void push(pilha *p, int elemento);

//retira o elemento do topo da pilha
int pop(pilha *p);

//conversor decimal binario
void divisao(pilha *p, int elemento);

//imprimindo o número binário
void imprime(pilha *p);

#endif /* TAD_H */

