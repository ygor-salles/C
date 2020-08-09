#ifndef TAD_H
#define TAD_H
#define tammax 3

typedef struct pil pilha;

//criapilha
pilha *criapilha();

//empilha: inclui um elemento no topo da pilha
void push(pilha *p, int elemento);

//desempilha: retira o elemento que está no topo da pilha e retorna seu valor
int pop(pilha *p);

//pilhaVazia: retorna verdadeiro se a pilha está vazia
int pilhavazia(pilha *p);

//pilhaCheia: retorna verdadeiro se a pilha está cheia
int pilhacheia(pilha *p);

//top: retorna o valor do elemento que está no topo sem retirá-lo da pilha
int top(pilha *p);

//listaDados: imprime os dados da pilha começando do topo
void listadados(pilha *p);


#endif /* TAD_H */

