#ifndef LISTA_H
#define LISTA_H

typedef struct lista lista;
typedef struct no no;

//CriaLista (cria a estrutura lista vazia)
lista * crialista();

// InsereOrdenado (inserir elemento ordenadamente na lista) 
void insereordenado(lista *l, int valor);

//RemoveElemento (remover um determinado elemento da lista)
void removeelemento(lista *l,int valor);

//ConsultaElemento (verifica se um determinado elemento se encontra na lista) 
no* consultaelemento(lista *l,int valor);

//Esvazia (remove todos os elementos da lista
void esvazia(lista *l);

//istaVazia (verifica se a lista está vazia)
int listavazia(lista *l);

//imprimeLista (imprime todos os elementos da lista) 
void imprimelista(lista *l);

//TamanhoLista (retorna a quantidade de elementos na lista)
int tamanholista(lista *l);

int tamanhocalc(lista *l, no *pos);




#endif /* LISTA_H */