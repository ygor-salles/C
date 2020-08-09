#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void imprime(int i, int numero[], int lugares[], char origem[][50], char destino[][50]);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, numero[4],  lugares[4], num, semafaro=0;
    char op, opcao, origem[4][50], destino[4][50], org[50], dest[50];


    printf("\n CADASTRE AS INFORMACOES DOS AVIÕES: \n\n");
    for (i=0; i<4; i++){
        printf("%dº avião\n",i+1);
        printf("Informe o código: "); scanf("%d",&numero[i]);
        printf("Informe número de lugares disponíveis: "); scanf("%d",&lugares[i]);
        printf("Informe o origem: "); scanf(" %[^\n]",origem[i]);
        printf("Informe o destino: "); scanf(" %[^\n]",destino[i]);
        printf("\n");
    }

    system("pause"); system("CLS");

    do{
        printf("\n\n>>>> MENU <<<<\n");
        printf("\nDigite (a) para consultar");
        printf("\nDigite (b) para efetuar reserva");
        printf("\nDigite (c) para sair");
        printf("\nOpção: "); scanf(" %c",&op);

        switch (op)
        {
            /* Efetuar Consulta */
            case 'a':
                printf("\n(a) Consultar por numero de voo");
                printf("\n(b) Consultar por origem");
                printf("\n(c) Consultar por destino");
                printf("\nOpção: "); scanf(" %c",&opcao);

                printf("\n\n");
                system("CLS");

                if (opcao == 'a'){
                    printf("\nDigite o numero de voo a ser consultado: "); scanf("%d",&num);
                    semafaro = 0;
                    for(i=0; i<4; i++)
                        if(numero[i] == num){
                            imprime(i, numero, lugares, origem, destino);
                            semafaro = 1;
                        }
                    if(semafaro == 0)
                        printf("\nVoo não encontrado!\n\n");
                }

                else if (opcao == 'b'){
                    printf("\nDigite a origem a ser consultada: "); scanf(" %[^\n]",org);
                    semafaro = 0;
                    for(i=0; i<4; i++)
                        if(strcmp(origem[i],org)==0){
                            imprime(i, numero, lugares, origem, destino);
                            semafaro = 1;
                        }
                    if(semafaro == 0)
                        printf("\nOrigem não encontrada!\n\n");
                }

                else if (opcao == 'c'){
                    printf("\nDigite o destino a ser consultado: "); scanf(" %[^\n]",dest);
                    semafaro = 0;
                    for(i=0; i<4; i++)
                        if(strcmp(destino[i],dest)==0){
                            imprime(i, numero, lugares, origem, destino);
                            semafaro = 1;
                        }
                    if(semafaro == 0)
                        printf("\nDestino não encontrado!\n\n");
                }
                else
                    printf("\nOpção inválida!\n\n");

                break;


            /* Efetuar Reserva */
            case 'b':
                printf("\nQual o numero de voo?: "); scanf("%d",&num);
                semafaro = 0;
                for(i=0; i<4; i++){
                    if (num == numero[i] && lugares[i] > 0){
                        semafaro = 1;
                        lugares[i]--;
                    }
                    else if(lugares[i] == 0 && num == numero[i])
                        semafaro = 2;
                }

                if (semafaro == 0)
                    printf("\nVoo inexistente!\n\n");
                else if (semafaro == 1)
                    printf("\nReserva confirmada!\n\n");
                else
                    printf("\nVoo lotado!\n\n");
                break;

            case 'c':
                printf("\nFinalizando programa...\n\n");
                break;

            default:
                printf("\nOpção inválida!\n\n");
                break;
        }

        printf("\n\n");
        system("pause"); system("CLS");

    } while(op != 'c');

    return 0;
}

void imprime(int i, int numero[], int lugares[], char origem[][50], char destino[][50])
{
    printf("\nVoo: %d",numero[i]);
    printf("\nCapacidade de lugares: %d",lugares[i]);
    printf("\nOrigem: %s",origem[i]);
    printf("\nDestino: %s",destino[i]);
    return ;
}
