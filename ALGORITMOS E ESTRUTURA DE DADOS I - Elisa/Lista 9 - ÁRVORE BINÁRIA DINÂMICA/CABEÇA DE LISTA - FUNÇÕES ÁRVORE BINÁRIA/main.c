#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  Pno *raiz;
  int opcao, chave, ok;

  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar árvore binária");
    printf("\n2 - Liberar árvore binária");
    printf("\n3 - Inserir nó na árvore binária");
    printf("\n4 - Remover nó da árvore binária");
    printf("\n5 - Consultar nó na árvore binária");
    printf("\n6 - Percurso pré-ordem");
    printf("\n7 - Percurso em-ordem");
    printf("\n8 - Percurso pós-ordem");
    printf("\n9 - Altura da árvore binária");
    printf("\n10 - Total de nós");
    printf("\n11 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    system("CLS");

    switch(opcao){

      case 1:
        raiz = criar_arvore_binaria();
        if(raiz != NULL)
            printf("\n Árvore criada com sucesso!");
        else
            printf("\n Árvore não criada!");
        break;

      case 2:
        ok = liberar_arvore_binaria(raiz);
        if(ok == 1)
            printf("\n Árvore liberada com sucesso!");
        else
            printf("\n Árvore não liberada!");
        break;

      case 3:
        printf("\n chave a ser inserido: ");
        scanf("%d", &chave);
        ok = inserir_arvore_binaria(raiz, chave);
        if(ok == 1)
            printf("\n Inserção realizada com sucesso!");
        else
            printf("\n Falha na inserção!");
        break;

      case 4:
        printf("\n chave a ser removido: ");
        scanf("%d", &chave);
        ok = remover_arvore_binaria(raiz, chave);
        if(ok == 1)
          printf("\n Remoção realizada com sucesso!");
        else
          printf("\n Falha na remoção!");
        break;

      case 5:
        printf("\n chave a ser buscado: ");
        scanf("%d", &chave);
        ok = consultar_arvore_binaria(raiz, chave);
        if(ok == 1)
          printf("\n Busca realizada com sucesso!");
        else
          printf("\n chave não encontrado na árvore!");
        break;

      case 6:
        percorrer_pre_ordem_arvore_binaria(raiz);
        break;

      case 7:
        percorrer_em_ordem_arvore_binaria(raiz);
        break;

      case 8:
        percorrer_pos_ordem_arvore_binaria(raiz);
        break;

      case 9:
        printf("%d\n", altura_arvore_binaria(raiz));
        break;

      case 10:
        printf("%d\n", quantidade_nos_arvore_binaria(raiz));
        break;

      case 11:
        liberar_arvore_binaria(raiz);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 11);

  return 0;
}
