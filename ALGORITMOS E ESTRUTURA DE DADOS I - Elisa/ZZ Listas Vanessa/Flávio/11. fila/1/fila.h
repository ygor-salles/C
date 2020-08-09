#ifndef FILA_H
#define FILA_H

typedef struct n no;
typedef struct fil fila;

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

//imprimefila (imprime a fila)
void imprimefila(fila *f);
#endif /* FILA_H */

