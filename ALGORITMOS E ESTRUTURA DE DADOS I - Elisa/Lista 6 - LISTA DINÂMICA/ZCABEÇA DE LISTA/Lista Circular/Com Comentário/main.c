
// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "listadec.h"

// funcao principal
int main(void) {
  
  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  Produto *produto; 
  int opcao, dado, ok, pos;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de op��es");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no in�cio");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do in�cio");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posi��o");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Imprimir lista");
    printf("\n12 - Sair");
    printf("\nOp��o: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1: 

        // criar lista
        li = criar_lista();

        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista n�o criada!");
        }
        break;


      case 2: 
        
        // liberar lista
        ok = liberar_lista(li);

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista n�o liberada!");
        }
        break;

      case 3:

        // inserir elemento no início
        ok = criar_produto(&produto);               
        ok = inserir_lista_inicio(li, produto);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inser��o!");
        }

        break;

      case 4:

        // inserir elemento no final
        ok = criar_produto(&produto);
        ok = inserir_lista_final(li, produto);

        if(ok == 1){
          printf("\n Inser��o realizada com sucesso!");
        }else{
          printf("\n Falha na inser��o!");
        }

        break;

      case 5:

        // inserir elemento de forma ordenada
        ok = criar_produto(&produto);
        ok = inserir_lista_ordenada(li, produto);

        if(ok == 1){
          printf("\n Inser��o realizada com sucesso!");
        }else{
          printf("\n Falha na inser��o!");
        }

        break;

      case 6:    

        // remover elemento do início 
        ok = remover_lista_inicio(li);

        if(ok == 1){
          printf("\n Remo��o realizada com sucesso!");
        }else{
          printf("\n Falha na remo��o!");
        }
        break;

      case 7:    

        // remover elemento do final 
        ok = remover_lista_final(li);

        if(ok == 1){
          printf("\n Remo��o realizada com sucesso!");
        }else{
          printf("\n Falha na remo��o!");
        }
        break;

      case 8:    
      
        // remover elemento do meio 
        printf("\n C�digo do produto a ser removido: ");
        scanf("%d", &dado); 

        ok = remover_lista_meio(li, dado);

        if(ok == 1){
          printf("\n Remo��o realizada com sucesso!");
        }else{
          printf("\n Falha na remo��o!");
        }
        break;


      case 9:
      
        // busca elemento pela posicao
        printf("\n Posi��o do elemento a ser buscado: ");
        scanf("%d", &pos); 

        produto = buscar_lista_posicao(li, pos);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %d� posi��o: ", pos);
          imprimir_produto(produto);
        }else{
          printf("\n Posi��o n�o existe!");
        }

        break;

      case 10:
      
        // busca elemento pelo dado
        printf("\n C�digo do produto a ser buscado: ");
        scanf("%d", &dado); 

        produto = buscar_lista_dado(li, dado);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento com c�digo %d na lista: ", dado);
          imprimir_produto(produto);
        }else{
          printf("\n Elemento n�o encontrado!");
        }

        break;

      case 11:

        // imprime a lista
        printf("\n Lista encadeada circular: ");
        ok = imprimir_lista(li);  
        
        break;
      
      case 12:

        // libera memória e finaliza programa
        liberar_lista(li);
        printf("\nFinalizando...");
        break;

      default: 
        printf("\nOp��o inv�lida!");
        break;
    }

  }while(opcao != 12);

  return 0;
}
