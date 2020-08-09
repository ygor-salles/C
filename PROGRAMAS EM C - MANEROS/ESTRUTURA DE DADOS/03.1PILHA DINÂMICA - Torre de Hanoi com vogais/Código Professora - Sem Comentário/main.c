#include  <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "tad.h"


int menu();

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha *tubo1;
    Pilha *tubo2;
    Pilha *tubo3;
    int ok, i, op, op2;
    char vet[5] = {'u', 'o', 'i', 'e', 'a'};
    char aux, compT1, compT2, compT3;

    tubo1 = criar_pilha();
    tubo2 = criar_pilha();
    tubo3 = criar_pilha();

    printf("|------------- Bem Vindo ao Jogo ----------------------| \n");
    printf("|                                                      |\n");
    printf("|Objetivo é passar todas as vogais do pote 1 ao pote 3,| \n");
    printf("|mantendo a mesma ordem seguindo as regras             | \n");
    printf("|                                                      |\n");
    printf("|   1 - A entrada nos tubos é por cima, a ultima vogal |\n");
    printf("|     a entrar será a primeira a sair                  |\n");
    printf("|   2 - Nunca em hipótese alguma, a vogal de cima      |\n");
    printf("|     será maior que a de baixo                        |\n");
    printf("|                                                      |\n");
    printf("|Boa Sorte                                             |\n");
    printf("|------------------------------------------------------|\n\n");

    for(i = 0; i < 5; i++)
        ok = empilhar(tubo1, vet[i]);


    do{
        consulta_pilha(tubo1, tubo2, tubo3);
        printf("\nOnde deseja colocar a primeira vogal\n\n");
        printf("1 - P2\n");
        printf("2 - P3\n");
        printf(">");
        scanf("%d", &op);
        system("CLS");
    }while(op != 1 && op != 2);

    if(op == 1){
      aux = desempilhar(tubo1);
      empilhar(tubo2, aux);
      system("CLS");
    }
    if(op == 2){
      aux = desempilhar(tubo1);
      empilhar(tubo3, aux);
      system("CLS");
    }

    do{
        do{
            consulta_pilha(tubo1, tubo2, tubo3);
            op = menu();
            system("CLS");
        }while (op != 1 && op != 2 && op != 3);


        //Opção 1
        if(op == 1){
            compT1 = pegaVogal(tubo1);
            if(compT1 == 'z'){
                printf("\nOperação nao permitida, pois pote esta vazio\n\n");
                consulta_pilha(tubo1, tubo2, tubo3);
            }
            else{

                do{
                  consulta_pilha(tubo1, tubo2, tubo3);
                  printf("\nOnde colocar a vogal retirada\n\n");
                  printf("1 - P2\n");
                  printf("2 - P3\n");
                  printf(">");
                  scanf("%d", &op2);
                  system("CLS");
                }while(op2 != 1 && op2 != 2);

                if(op2 == 1){
                    compT2 = pegaVogal(tubo2);
                    if(compT2 == 'z'){
                        aux = desempilhar(tubo1);
                        empilhar(tubo2, aux);
                        system("CLS");
                    }
                    else{
                      if(compT1 < compT2){
                        aux = desempilhar(tubo1);
                        empilhar(tubo2, aux);
                        system("CLS");
                      }
                      else
                          printf("\nOperação nao permitida pois %c > %c\n\n",compT1, compT2);
                    }
                }

                if(op2 == 2){
                    compT3 = pegaVogal(tubo3);
                    if(compT3 == 'z'){
                        aux = desempilhar(tubo1);
                        empilhar(tubo3, aux);
                        system("CLS");
                    }
                    else{
                        if(compT1 < compT3){
                            aux = desempilhar(tubo1);
                            empilhar(tubo3, aux);
                            system("CLS");
                        }
                        else
                            printf("\nOperação nao permitida pois %c > %c\n\n",compT1, compT3);
                    }
                }
            }
        }


        //Opção 2
        if(op == 2){
            compT2 = pegaVogal(tubo2);
            if(compT2 == 'z'){
                printf("\nOperação nao permitida, pois pote esta vazio\n\n");
            }
            else{
                do{
                    consulta_pilha(tubo1, tubo2, tubo3);
                    printf("\nOnde colocar a vogal retirada\n\n");
                    printf("1 - P1\n");
                    printf("2 - P3\n");
                    printf(">");
                    scanf("%d", &op2);
                    system("CLS");
                }while(op2 != 1 && op2 != 2);

                if(op2 == 1){
                    compT1 = pegaVogal(tubo1);
                    if(compT1 == 'z'){
                        aux = desempilhar(tubo2);
                        empilhar(tubo1, aux);
                        system("CLS");
                    }
                    else{
                        if(compT2 < compT1){
                            aux = desempilhar(tubo2);
                            empilhar(tubo1, aux);
                            system("CLS");
                        }
                        else
                            printf("Operação nao permitida pois %c > %c\n\n",compT2, compT1);
                    }
                }
                else if(op == 2){
                    compT3 = pegaVogal(tubo3);
                    if(compT3 == 'z'){
                        aux = desempilhar(tubo2);
                        empilhar(tubo3, aux);
                        system("CLS");
                    }
                    else{
                        if(compT2 < compT3){
                            aux = desempilhar(tubo2);
                            empilhar(tubo3, aux);
                            system("CLS");
                        }
                        else
                            printf("Operação nao permitida pois %c > %c\n\n",compT2, compT3);
                    }
                }
            }
        }


        //Opção 3
        if(op == 3){
            compT3 = pegaVogal(tubo3);
            if(compT3 == 'z')
                printf("Operação nao permitida, pois pote esta vazio\n");
            else{
                do{
                    consulta_pilha(tubo1, tubo2, tubo3);
                    printf("Onde colocar a vogal retirada\n");
                    printf("1 - P1\n");
                    printf("2 - P2\n");
                    printf(">");
                    scanf("%d", &op2);
                    system("CLS");
                }while(op2 != 1 && op2 != 2);

                if(op2 == 1){
                    compT1 = pegaVogal(tubo1);
                    if(compT1 == 'z'){
                        aux = desempilhar(tubo3);
                        empilhar(tubo1, aux);
                        system("CLS");
                    }
                    else{
                        if(compT3 < compT1){
                            aux = desempilhar(tubo3);
                            empilhar(tubo1, aux);
                            system("CLS");
                        }
                        else
                            printf("Operação nao permitida pois %c > %c\n\n",compT3, compT1);
                    }
                }
                else if(op2 == 2){
                    compT2 = pegaVogal(tubo2);
                    if(compT2 == 'z'){
                        aux = desempilhar(tubo3);
                        empilhar(tubo2, aux);
                        system("CLS");
                    }
                    else{
                        if(compT3 < compT2){
                            aux = desempilhar(tubo3);
                            empilhar(tubo2, aux);
                            system("CLS");
                        }
                        else
                            printf("Operação nao permitida pois %c > %c\n\n",compT3, compT2);
                    }
                }
            }
        }

        ok = verificaCerto(tubo3);
    }while(ok != 1);

    libera_pilha(tubo1);
    libera_pilha(tubo2);
    libera_pilha(tubo3);

    printf("\n\nPARABENS!!!!!!!!!!!!!!!!!!\n");

    printf("\n\nfim do programa\n\n");

    return 0;
}

int menu(){
  int op;

  printf("\nOnde deseja retirar a vogal\n\n");
  printf("1 - P1\n");
  printf("2 - P2\n");
  printf("3 - P3\n");
  printf(">");
  scanf("%d", &op);
  return op;
}
