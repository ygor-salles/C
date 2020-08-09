#ifndef TAD_H
#define TAD_H
#define tammax 6

typedef struct pil pilha;

//criapilha
pilha *criapilha();

//empilha: inclui um elemento no topo da pilha
void push(pilha *p, int elemento);

//desempilha: retira o elemento que está no topo da pilha e retorna seu valor
void pop(pilha *p);

//preenche pilha
void preenche(pilha *p, pilha *n);

//imprimindo as pilhas
void imprime(pilha *p, pilha *n);


#endif /* TAD_H */

