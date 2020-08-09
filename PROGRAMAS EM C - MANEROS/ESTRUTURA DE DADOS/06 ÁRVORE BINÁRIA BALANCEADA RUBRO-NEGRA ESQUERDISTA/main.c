#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "tad.h"

int main(void)
{

  setlocale(LC_ALL, "Portuguese");
  Pno *raiz;

  int chave;
  char nome[20], op;

    do{
    printf("\n\n***MENU DE OPCOES***");
    printf("\nESCOLHA O CARACTER CONFORME OPCAO DESEJADA");
    printf("\n[y] - Criar arvore");
    printf("\n[i] - Inserir registro");
    printf("\n[c] - Cosulta registro");
    printf("\n[r] - Remove registro");
    printf("\n[p] - Imprimir em ordem");
    printf("\n[q] - Imprimir em pos ordem");
    printf("\n[s] - Imprimir em pre ordem");
    printf("\n[t] - Imprimir em formato arvore");
    printf("\n[a] - Altura da Árvore");
    printf("\n[n] - Total de Nós");
    printf("\n[e] - Esvazia Árvore");
    printf("\n[x] - Encerrar");
    printf("\nOpcao: "); scanf(" %c",&op);
    printf("\n\n");

    switch (op){
        case 'y':
            raiz = criar();
            if(raiz != NULL) printf("Arvore criada com sucesso!");
            else printf("Arvore não criada!");
            break;

        case 'i':
            printf("Informe CHAVE: "); scanf("%d",&chave);
            printf("Informe NOME: "); scanf(" %[^\n]",nome);
            inserir(raiz, chave, nome);
            break;

        case 'c':
            printf("\nInforme CHAVE: "); scanf("%d",&chave);
            if(consultar(raiz, chave) == 1)
              printf("\n %d %s",chave, nome);
            else
              printf("Nao encontrado!");
            break;

        case 'r':
            printf("\nInforme CHAVE: "); scanf("%d",&chave);
            remover(raiz, chave);

        case 'p':
            percorrer_em_ordem(raiz); break;

        case 'q':
            percorrer_pos_ordem(raiz); break;

        case 's':
            percorrer_pre_ordem(raiz); break;

        case 't':
            print_arvore(raiz); break;

        case 'a':
            printf("%d\n", altura(raiz)); break;

        case 'n':
            printf("%d\n", quantidade_nos(raiz)); break;

        case 'e':
            if(liberar(raiz) == 1)
                printf("\n Árvore liberada com sucesso!");
            else
                printf("\n Árvore não liberada!");
            break;

        case 'x':
            liberar(raiz);
            printf("Finalizando...");
            break;

        default:
            printf("Opcao invalida!");
            break;
    }

    printf("\n");
    // system("pause");
    // system("clear");

  } while(op != 'x');

  return 0;
}
