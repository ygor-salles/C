#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "tad.h"

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  Lista *li;
  int opcao, num, pos;

  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Inserir elemento no início");
    printf("\n3 - Inserir elemento no fim");
    printf("\n4 - Inserir elemento ordenado");
    printf("\n5 - IMPRIME LISTA");
    printf("\n6 - Remove elemento no início");
    printf("\n7 - Remove elemento no fim");
    printf("\n8 - Remove elemento dado");
    printf("\n9 - Buscar número pela posição digitada");
    printf("\n10 - Buscar posição pelo número digitado");
    printf("\n11 - Tamanho da Lista");
    printf("\n12 - Verifica se a lista está vazia");
    printf("\n13 - Esvazia Lista");
    printf("\n14 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    system("CLS");

    switch(opcao){
      case 1:
        li = criar_lista();
        if(li != NULL)
          printf("Lista criada com sucesso!");
        else
          printf("Lista não criada, espaço insuficiente!");
        break;

      case 2:
        printf("\nElemento a ser inserido: ");
        scanf("%d",&num);
        if(inserir_lista_inicio(li, num) == 1)
          printf("\nInserção realizada com sucesso!");
        else
          printf("\nInserção não realizada, espaço insuficiente!");
        break;

      case 3:
        printf("\nElemento a ser inserido: ");
        scanf("%d",&num);
        if(inserir_lista_fim(li, num) == 1)
          printf("\nInserção realizada com sucesso!");
        else
          printf("\nInserção não realizada, espaço insuficiente!");
        break;

      case 4:
        printf("\nElemento a ser inserido: ");
        scanf("%d",&num);
        if(inserir_lista_ordenada(li, num) == 1)
          printf("\nInserção realizada com sucesso!");
        else
          printf("\nInserção não realizada, espaço insuficiente!");
        break;

      case 5:
        if(imprimir_lista(li) == 1)
          printf("\nImpressão realizada com sucesso!");
        break;

      case 6:
        if(remover_elemento_inicio(li) == 1)
          printf("\nRemoção realizada com sucesso!");
        break;

      case 7:
        if(remover_elemento_fim(li) == 1)
          printf("\nRemoção realizada com sucesso!");
        break;

      case 8:
        printf("\nNúmero a ser removido: ");
        scanf("%d",&num);
        if(remover_elemento_dado(li, num) == 1)
          printf("\nRemoção realizada com sucesso!");
        break;

      case 9:
        printf("\nDigite a posição: ");
        scanf("%d",&pos);
        if (buscar_lista_posicao(li, pos) != 0){
           printf("\nO número da posição %d é %d",pos, buscar_lista_posicao(li, pos));
           printf ("\n\nLista inteira: ");
           imprimir_lista(li);
        }
        else
            printf("\nPosição não encontrada!");
        break;

      case 10:
        printf("\nNúmero a ser buscado: ");
        scanf("%d",&num);
        if (buscar_lista_dado(li, num) != 0){
           printf("\nA posição do número %d é %d\n",num, buscar_lista_dado(li, num));
           printf ("\n\nLista inteira: ");
           imprimir_lista(li);
        }
        else
            printf("\nNúmero não encontrado!");
        break;

      case 11:
          printf("\nO tamanho da lista é: %d",tamanho_lista(li));
        break;

      case 12:
        if(lista_vazia(li) == 1)
            printf("\nLista vazia!");
        else
            printf("\nA lista não está vazia!");
        break;

      case 13:
        if(esvaziar_lista(li) == 1)
          printf("\nLista Esvaziada!");
        break;

      case 14:
        esvaziar_lista(li);
        printf("\nFinalizando...");
        break;
      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 14);

  return 0;
}
