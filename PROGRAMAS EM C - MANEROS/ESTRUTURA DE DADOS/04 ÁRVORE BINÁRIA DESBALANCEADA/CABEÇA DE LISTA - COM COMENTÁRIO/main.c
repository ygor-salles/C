// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// bibliotecas do projeto
#include "tad.h"

// funcao principal
int main(void) {

  setlocale(LC_ALL, "Portuguese");
  Pno *raiz;
  int opcao, chave, ok;

  // menu de op��es para execu��es de opera��es sobre a lista
  do
  {
    printf("\n\nMenu de op��es");
    printf("\n1 - Criar �rvore bin�ria");
    printf("\n2 - Liberar �rvore bin�ria");
    printf("\n3 - Inserir n� na �rvore bin�ria");
    printf("\n4 - Remover n� da �rvore bin�ria");
    printf("\n5 - Consultar n� na �rvore bin�ria");
    printf("\n6 - Percurso pr�-ordem");
    printf("\n7 - Percurso em-ordem");
    printf("\n8 - Percurso p�s-ordem");
    printf("\n9 - Altura da �rvore bin�ria");
    printf("\n10 - Total de n�s");
    printf("\n11 - Sair");
    printf("\nOp��o: ");
    scanf("%d", &opcao);
    system("CLS");

    switch(opcao){

      case 1:

        // criar arvore binaria
        raiz = criar_arvore_binaria();

        if(raiz != NULL){
          printf("\n �rvore criada com sucesso!");
        }else{
          printf("\n �rvore n�o criada!");
        }
        break;


      case 2:

        // liberar arvore binaria
        ok = liberar_arvore_binaria(raiz);

        if(ok){
          printf("\n �rvore liberada com sucesso!");
        }else{
          printf("\n �rvore n�o liberada!");
        }
        break;

      case 3:

        // inserir n� na �rvore bin�ria
        printf("\n chave a ser inserido: ");
        scanf("%d", &chave);

        ok = inserir_arvore_binaria(raiz, chave);

        if(ok == 1){
          printf("\n Inser��o realizada com sucesso!");
        }else{
          printf("\n Falha na inser��o!");
        }

        break;

      case 4:

        // remover n� com determinado chave
        printf("\n chave a ser removido: ");
        scanf("%d", &chave);

        ok = remover_arvore_binaria(raiz, chave);

        if(ok == 1){
          printf("\n Remo��o realizada com sucesso!");
        }else{
          printf("\n Falha na remo��o!");
        }

        break;

      case 5:

        // busca elemento pelo chave
        printf("\n chave a ser buscado: ");
        scanf("%d", &chave);

        ok = consultar_arvore_binaria(raiz, chave);

        if(ok == 1){
          printf("\n Busca realizada com sucesso!");
        }else{
          printf("\n chave n�o encontrado na �rvore!");
        }


        break;

      case 6:
        // imprime percurso pr�-ordem
        percorrer_pre_ordem_arvore_binaria(raiz);
        break;

      case 7:
        // imprime percurso em-ordem
        percorrer_em_ordem_arvore_binaria(raiz);
        break;

      case 8:
        // imprime percurso p�s-ordem
        percorrer_pos_ordem_arvore_binaria(raiz);
        break;


      case 9:
        // imprime a altura da �rvore bin�ria
        printf("%d\n", altura_arvore_binaria(raiz));
        break;

        break;

      case 10:
        // imprime o n�mero total de n�s na �rvore bin�ria
        printf("%d\n", quantidade_nos_arvore_binaria(raiz));
        break;

      case 11:

        // libera mem�ria e finaliza programa
        liberar_arvore_binaria(raiz);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOp��o inv�lida!");
        break;
    }

  }while(opcao != 11);

  return 0;
}
