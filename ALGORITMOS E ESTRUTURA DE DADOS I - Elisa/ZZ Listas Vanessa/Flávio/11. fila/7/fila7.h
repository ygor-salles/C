#ifndef FILA7_H
#define FILA7_H

typedef struct n no;
typedef struct fil fila;
typedef struct proc processo;

//CriaFila (cria a estrutura fila vazia)
fila *criafila();

//Enfileirar - (enqueue) (inserir elemento na fila)
void enfileirar(fila *f, int elemento);

//Desenfileirar – (dequeue) (remover elemento da fila)
void desinfileirar(fila *f, no *res);

//ComecoFila (mostrar quem está no início da fila)
int comecofila(fila *f);

//Esvazia (remove todos os elementos da fila)
void esvazia(fila*f);

//filaVazia (verifica se a fila está vazia)
int filavazia(fila *f);

//TamanhoFila (retorna a quantidade de elementos na fila)
int tamanhofila(fila *f);



#endif /* FILA7_H */

