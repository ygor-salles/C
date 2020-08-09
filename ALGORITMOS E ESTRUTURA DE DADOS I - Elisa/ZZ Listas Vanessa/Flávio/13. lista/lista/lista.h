#ifndef LISTA_H
#define LISTA_H

typedef struct n no;
typedef lis lista;

//cria lista
lista *crialista();

//InsereOrdenado (inserir elemento ordenadamente na lista)
void InsereOrdenado(lista *l, int valor);

//RemoveElemento (remover um determinado elemento da lista)
void RemoveElemento(lista *l, int valor);

//ConsultaElemento (verifica se um determinado elemento se encontra na lista)
int ConsultaElemento(lista *l, int valor);

//Esvazia (remove todos os elementos da lista)
void Esvazia(lista *l);

//listaVazia (verifica se a lista está vazia)
int listavazia(lista *l);

//imprimeLista (imprime todos os elementos da lista)
void imprimelista(lista *l);

//TamanhoLista (retorna a quantidade de elementos na lista)
int TamanhoLista(lista *l);
#endif /* LISTA_H */

