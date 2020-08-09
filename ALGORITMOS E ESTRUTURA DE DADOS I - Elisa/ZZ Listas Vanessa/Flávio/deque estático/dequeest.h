#ifndef DEQUEEST_H
#define DEQUEEST_H
#define MAX 5

typedef struct Item item;
typedef struct Deque deque;

//cria deque 
deque* cria_deque ();

//libera deque, para liberar memória ao terminar
void libera_deque(deque *d);

//verificar o tamanho do deque
int tamanho(deque *d);

//verificar se o deque está vazio
int vazio(deque *d);

//verificar se o deque está cheio
int cheio(deque *d);

//consultar o início do deque
int consulta_inicio(deque *d);

//consultar o fim do deque
int consulta_final(deque *d);

//inserção pelo início do deque
void insere_inicio(deque *d, int i);

//inserção pelo final do deque
void insere_final(deque *d, int i);

//remoção pelo início do deque
void remove_inicio(deque *d);

//remoção pelo final do deque
void remove_final(deque *d);

//imprime os elementos do deque
void imprime_deque(deque *d);

//menu de opções
void menu(deque *d);

#endif /* DEQUEEST_H */

