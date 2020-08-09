#include <stdio.h>
#include<locale.h>
#include<stdlib.h>
#include "tad.h"

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  Fila *fi;
  Aluno dados_aluno;
  int opcao, x, cont;

  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar fila");
    printf("\n2 - Enfileirar");
    printf("\n3 - Desenfileirar");
    printf("\n4 - Tamanho da fila");
    printf("\n5 - Verificar se a fila está vazia");
    printf("\n6 - Consulta fila");
    printf("\n7 - Imprimir fila");
    printf("\n8 - Esvaziar fila");
    printf("\n9 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    system("CLS")

    switch(opcao){
      case 1:
        fi = criar_fila();
        if(fi != NULL)
          printf("Fila criada com sucesso!");
        else
          printf("Fila não criada!");
        break;

      case 2:
        printf("\nDigite nome: "); scanf (" %[^\n]",dados_aluno.nome);
        printf("Digite matricula: "); scanf ("%d",&dados_aluno.matricula);
        printf("Digite nota "); scanf ("%f",&dados_aluno.n1);
        x = enfileirar(fi, dados_aluno);
        if(x == 1)
          printf("Enfileirado com sucesso!");
        break;

      case 3:
        x = desenfileirar(fi);
        if(x == 1)
          printf("Desenfileirado com sucesso!");
        break;

      case 4:
        cont = tamanho_fila(fi);
        printf ("O tamanho da fila é: %d",cont);
        break;

      case 5:
        x = fila_vazia(fi);
        if (x == 1)
            printf ("Fila vazia!");
        else
            printf ("A fila não está vazia!");
        break;

      case 6:
        x = consulta_fila(fi, &dados_aluno);
        if (x == 1){
            printf("\nNome: %s",dados_aluno.nome);
            printf("\nMatricula: %d",dados_aluno.matricula);
            printf("\nNota: %.2f",dados_aluno.n1);
        }
        break;

      case 7:
        x = imprimir_fila(fi);
        if (x == 1)
            printf("\nImpressão realizada com sucesso!");
        break;

      case 8:
        x = esvazia_fila(fi);
        break;

       case 9:
        esvazia_fila(fi);
        printf("\nFinalizando...\n");
        break;
      default:
        printf("\nOpção inválida!\n");
        break;
    }

  }while(opcao != 9);

  return 0;
}