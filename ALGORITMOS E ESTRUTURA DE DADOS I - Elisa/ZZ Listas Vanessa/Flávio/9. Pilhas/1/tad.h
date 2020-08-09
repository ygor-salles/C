#ifndef TAD_H
#define TAD_H
#define tammax 10

typedef struct pil pilha;

//criapilha
pilha *criapilha();

//empilha: inclui um elemento no topo da pilha
void push(pilha *p, int elemento);

//desempilha: retira o elemento que está no topo da pilha e retorna seu valor
int pop(pilha *p);

//prenche pilha
void preenchepilha(pilha *p);

//junta pilha
void juntapilha(pilha *p, pilha *n, pilha *q);

//imprime pilha
void imprimepilha(pilha *p);

//Topo (mostrar quem está no topo da pilha)
int topo(pilha *p);


#endif /* TAD_H */

