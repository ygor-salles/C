#ifndef 1_12_H
#define 1_12_H
#define tammax 10

typedef struct n no;
typedef struct fil fila;
typedef struct pilhaa pilha;

//CriaFila (cria a estrutura fila vazia)
fila *criafila();

//Enfileirar - (enqueue) (inserir elemento na fila)
void enfileirar(fila *f, int elemento);

//Desenfileirar – (dequeue) (remover elemento da fila)
int desinfileirar(fila *f);

//ComecoFila (mostrar quem está no início da fila)
int comecofila(fila *f);

//Esvazia (remove todos os elementos da fila)
void esvazia(fila*f);

//filaVazia (verifica se a fila está vazia)
int filavazia(fila *f);

//TamanhoFila (retorna a quantidade de elementos na fila)
int tamanhofila(fila *f);

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



#endif /* 1_12_H */

