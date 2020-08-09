// TAD para Lista Din�mica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "listadec.h"

struct produto{
  int codigo;
  char descricao[30];  
  float preco;
  int qtd;
};

struct elemento{
  Produto *produto;
  struct elemento *prox;
};

typedef struct elemento Elemento;
typedef Elemento* Lista;


/****************************************************************************/
int imprimir_produto(Produto *produto)
{
  printf("\n\n   C�digo: %d", produto->codigo);
  printf("\n   Descri��o: %s", produto->descricao);
  printf("\n   Pre�o: %.2f", produto->preco);
  printf("\n   Quantidade: %d", produto->qtd);

  return 1;
}

/****************************************************************************/
int criar_produto(Produto **produto)
{  
  *produto = (Produto*) malloc(sizeof(Produto));  

  printf("\n C�digo: ");
  scanf("%d", &(*produto)->codigo);

  printf(" Descri��o: ");
  scanf(" %[^\n]", &(*produto)->descricao);

  printf(" Pre�o: ");
  scanf("%f", &(*produto)->preco);

  printf(" Quantidade: ");
  scanf("%d", &(*produto)->qtd);

  return 1;
}


/****************************************************************************/
Lista* criar_lista()
{
  // 'li' � um ponteiro para ponteiro do tipo Elemento
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a aloca��o estiver correta 'li' aponta para NULL (lista vazia)
  if(li != NULL){
    *li = NULL;
  }else{
    return NULL;
  }  

  return li;
}


/****************************************************************************/
int liberar_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if(li == NULL){
    return 0;    
  } 

  // verifica se a lista n�o est� vazia
  if((*li) != NULL){
    Elemento *no, *aux;
    no = *li;

    // la�o percorre a lista at� o �ltimo elemento, liberando o anterior
    while( no->prox !=  (*li) ){
      aux = no;
      no = no-> prox;
      free(aux);
    }

    // libera o �ltimo elemento
    free(no);

    // libera o ponteiro de ponteiro (Lista)
    free(li);   
  }

  return 1;
}

/****************************************************************************/
int tamanho_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente ou se a lista est� vazia
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  // inicializa o contador de elementos
  int cont = 0;

  // cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da lista 
  Elemento *no;  
  no = *li;

  // incrementa 'cont' at� acabar o �ltimo elemento da lista
  do{
    cont++;
    no = no->prox;
  }while(no != (*li));

  // retorna a quantidade de elementos da lista
  return cont;
}

/****************************************************************************/
int lista_vazia(Lista *li)
{
  // verifica se houve problema na cria��o da lista
  // ou seja, 'li' n�o � uma lista v�lida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas n�o cont�m nenhum valor (lista vazia)
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


/****************************************************************************/
Elemento* criar_elemento()
{
  // 'no' � um ponteiro do tipo Elemento
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  // verifica se a mem�ria foi alocada corretamente
  if(no == NULL){
    return 0;
  }  

  // retorna ponteiro alocado
  return no;
}


/****************************************************************************/
int inserir_lista_inicio(Lista *li, Produto *produto)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no;
  no = criar_elemento();

  // atribui valores ao elemento novo
  no->produto = produto;

  // verifica se a lista est� vazia
  if((*li) == NULL){ 

    // insere elemento �nico no in�cio da lista    
    no->prox = no;  // pr�ximo elemento na lista circular � ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

    Elemento *aux;
    aux = *li;

    // percorre a lista at� o �ltimo elemento
    while(aux->prox != (*li)){
      aux = aux->prox;
    }

    // insere elemento no in�cio da lista  
    aux->prox = no; // 'no' � o pr�ximo elemento na lista circular ap�s o �ltimo
    no->prox = *li; // primeiro elemento antigo '*li' � o pr�ximo ap�s o 'no'
    *li = no;       // 'no' passa a ser o primeiro elemento
    
  }

  return 1;
}


/****************************************************************************/
int inserir_lista_final(Lista *li, Produto *produto)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no;
  no = criar_elemento();

  // atribui valores ao elemento novo
  no->produto = produto;
  
  // verifica se a lista est� vazia
  if( (*li) == NULL ){

    // insere elemento �nico no in�cio da lista 
    no->prox = no;  // pr�ximo elemento na lista circular � ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

    Elemento *aux;
    aux = *li;

    // percorre a lista at� o �ltimo elemento
    while(aux->prox != (*li)){
      aux = aux->prox;
    }

    // insere elemento no final da lista 
    aux->prox = no;  // 'no' � o pr�ximo elemento na lista circular ap�s o �ltimo
    no->prox = *li;  // primeiro elemento '*li' � o pr�ximo ap�s o 'no'
  }

  return 1;
}


/****************************************************************************/
int inserir_lista_ordenada(Lista *li, Produto *produto)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no;
  no = criar_elemento();

  // atribui valores ao elemento novo
  no->produto = produto;
  
  // verifica se a lista est� vazia
  if( (*li) == NULL ){

    // insere elemento �nico no in�cio da lista 
    no->prox = no;  // pr�ximo elemento na lista circular � ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

    // primeira posi��o � a correta para inser��o do elemento novo
    if((*li)->produto->codigo > produto->codigo){

      Elemento *aux;
      aux = *li;
      
      // percorre a lista at� o �ltimo elemento
      while(aux->prox != (*li)){
        aux = aux->prox;
      }

      // insere elemento no in�cio da lista  
      aux->prox = no; // 'no' � o pr�ximo elemento na lista circular ap�s o �ltimo
      no->prox = *li; // primeiro elemento antigo '*li' � o pr�ximo ap�s o 'no'
      *li = no;       // 'no' passa a ser o primeiro elemento
    }

    // sen�o, percorre a lista, a partir do segundo elemento, at� achar o local correto e insere
    Elemento *anterior, *atual;

    anterior = *li;
    atual = anterior->prox;

    // percorre a lista at� o �ltimo elemento ou at� encontrar um elemento maior que o novo
    while(atual != (*li) && atual->produto->codigo < produto->codigo){
      anterior = atual;
      atual = atual->prox;
    }

    // insere elemento na posi��o correta da lista (meio)
    anterior->prox = no; // 'no' � o pr�ximo elemento na lista circular ap�s o anterior
    no->prox = atual;    // 'atual' � o pr�ximo elemento ap�s o 'no'
  }

  return 1;
}


/****************************************************************************/
int remover_lista_inicio(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista est� vazia (n�o existem elementos a serem removidos)
  if((*li) == NULL){
    return 0;
  }

  // verifica se existe apenas um elemento na lista (ap�s remo��o a lista fica vazia)
  if ((*li)->prox == (*li)){

    // libera elemento �nico
    free(*li);
    // indica que a lista ficou vazia
    *li = NULL;

    return 1;
  }

  Elemento *no, *aux;
  no = *li; // 'no' � o elemento a ser removido
  aux = *li;

  // percorre a lista at� o �ltimo elemento
  while(aux->prox != (*li)){
    aux = aux->prox;
  }

  // remove o primeiro elemento da lista
  aux->prox = no->prox; // 'no->prox' � o pr�ximo elemento na lista circular ap�s o �ltimo
  *li = no->prox;       // primeiro elemento da lista '*li' passa a ser o 'no->prox'

  // libera Elemento 'no'
  free(no);

  return 1;
}


/****************************************************************************/
int remover_lista_final(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista est� vazia (n�o existem elementos a serem removidos)
  if((*li) == NULL){
    return 0;
  }

  // verifica se existe apenas um elemento na lista (ap�s remo��o a lista fica vazia)
  if ((*li)->prox == (*li)){

    // libera elemento �nico
    free(*li);
    // indica que a lista ficou vazia
    *li = NULL;

    return 1;
  }

  Elemento *anterior, *no;
  no = *li; // 'no' � o elemento a ser removido
  
  // percorre a lista at� 'no' ser o �ltimo elemento, armazenando o elemento anterior
  while(no->prox != (*li)){
    anterior = no;
    no = no->prox;
  }

  // remove o �ltimo elemento da lista
  anterior->prox = no->prox; // 'no->prox' passa a ser o pr�ximo elemento na lista circular ap�s o 'anterior'

  // libera Elemento 'no'
  free(no);

  return 1;

}


/****************************************************************************/
int remover_lista_meio(Lista *li, int codigo)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista est� vazia (n�o existem elementos a serem removidos)
  if((*li) == NULL){
    return 0;
  }

  Elemento *no;
  no = *li;

  // elemento a ser removido est� no in�cio da lista
  if(no->produto->codigo == codigo){

    // verifica se existe apenas um elemento na lista (ap�s remo��o a lista fica vazia)
    if (no->prox == no){

      // indica que a lista ficou vazia e remove o 'no'      
      *li = NULL;
      free(no);

      // libera Elemento 'no'
      return 1;

    // remove o primeiro elemento
    }else{

      Elemento *ultimo;
      ultimo = *li;

      // percorre a lista at� o �ltimo elemento
      while(ultimo->prox != (*li)){
        ultimo = ultimo->prox;
      }  
      
      // remove primeiro elemento 'no' (no = *li)
      ultimo->prox = no->prox;
      *li = no->prox;

      // libera Elemento 'no'
      free(no);

      return 1;      
    }

  }

  Elemento *anterior;
  anterior = no;
  no = no->prox; 

  // percorre a lista at� achar o elemento a ser removido, ou at� encontrar o primeiro elemento
  while(no != (*li) && no->produto->codigo != codigo){
    anterior = no;
    no = no->prox;
  }

  // elemento a ser removido n�o foi encontrado
  if(no == (*li)){
    return 0;
  }

  // remove o elemento 'no'
  anterior->prox = no->prox;  // 'no->prox' passa a ser o pr�ximo elemento na lista circular ap�s o 'anterior'

  // libera Elemento 'no'
  free(no);

  return 1;

}


/****************************************************************************/
Produto *buscar_lista_posicao(Lista *li, int pos)
{
  // verifica se a lista foi criada corretamente, se est� vazia ou se a posi��o 'pos' � inv�lida
  if(li == NULL || (*li) == NULL || pos <= 0){
    return NULL;  
  }

  int i = 1;
  Elemento *no;
  no = *li;

  // percorre a lista at� achar posicao desejada, ou at� encontrar o �ltimo elemento
  while( no->prox != (*li) && i < pos){
    no = no->prox;
    i++;
  }

  // verifica se a posicao desejada existe na lista
  if(i != pos){
    return NULL;
  }

  // retorna o valor do elemento na posicao 'pos'
  return no->produto;

}


/****************************************************************************/
Produto *buscar_lista_dado(Lista *li, int codigo)
{
  // verifica se a lista foi criada corretamente ou se est� vazia
  if(li == NULL || (*li) == NULL){
    return NULL;  
  }

  int i = 1;
  Elemento *no;
  no = *li;

  // percorre a lista at� achar o elemento desejado, ou at� encontrar o �ltimo elemento
  while( no->prox != (*li) && no->produto->codigo != codigo){
    no = no->prox;
    i++;
  }

  // verifica se a posicao desejada existe na lista
  if(no->produto->codigo != codigo){
    return NULL;
  }

  // retorna a posicao do elemento buscado na lista
  return no->produto;

}


/****************************************************************************/
int imprimir_lista(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  if((*li) == NULL){
    printf(" Lista vazia!");
  }

  // imprime primeiro elemento
  Elemento *no;
  no = (*li);

  // percorre lista at� o �ltimo elemento
  while(no->prox != (*li)){
    imprimir_produto(no->produto);
    no = no->prox;
  }

  // imprime �ltimo elemento
  imprimir_produto(no->produto);
  
  return 1;
}
