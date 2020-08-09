#include <stdio.h>
#include "listade.h"

int main(void) 
{
  Lista *li;
  int opcao, dado;
  
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Remover elemento do início");
    printf("\n5 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    system("CLS");

    switch(opcao){
      case 1:
        li = criar_lista();
        if(li != NULL)
          printf("Lista criada com sucesso!");
        else
          printf("Lista não criada!");
        break;

      case 2:
        liberar_lista(li);
        break;

      case 3:
        printf("\nElemento a ser inserido: ");
        scanf("%d", &dado);
        if(inserir_lista_inicio(li, dado) == 1)
          printf("Inserção realizada com sucesso!");
        break;

      case 4:        
        if(remover_lista_inicio(li) == 1)
          printf("Remoção realizada com sucesso!");
        break;

      case 5:
        liberar_lista(li);
        printf("\nFinalizando...");
        break;
      default: 
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 5);

  return 0;
}