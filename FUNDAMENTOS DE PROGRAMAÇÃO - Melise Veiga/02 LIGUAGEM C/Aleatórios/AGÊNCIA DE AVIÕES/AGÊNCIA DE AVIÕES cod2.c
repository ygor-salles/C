#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int nvoo[4], lugares[4],opc,opc2,i,escvoo,n,esc,cont,j,conta,rec,alou[4];
    char local[50], dest[50];

    char origem[4][50];
    char destino[4][50];
    conta =0;
    rec=0;

    n=1;

    for (i=0; i<4; i++){
        printf ("\n\nDigite as informacoes sobre o %dº voo\n\n", n++);
        printf ("Numero do voo: ");
        scanf ("%d", &nvoo[i]);
        printf ("Numero de lugares disponiveis: ");
        scanf ("%d", &lugares[i]);
        printf ("Origem do voo: ");
        scanf (" %[^\n]", &origem[i]);// ler uma cadeia de caracteres até encontrar um
        // caracter da lista de caracteres
        printf ("Destino do voo: ");
        scanf (" %[^\n]", &destino[i]);
    }

    while (opc != 3){
        printf ("\n\n========== MENU DE OPCOES==========\n\n");
        printf ("Digite 1 para consultar: \n");
        printf ("Digite 2 para efetuar reserva: \n");
        printf ("Digite 3 para sair: \n");
        printf ("\n\nSua escolha: ");
        scanf ("%d", &opc);

        if (opc==1){
            //system("cls");
            printf ("Digite 1 para consultar por numero do voo: \n");
            printf ("Digite 2 para consultar por origem: \n");
            printf ("Digite 3 para consultar por destino: ");
            printf ("\n\nSua escolha: ");
            scanf ("%d", &opc2);

            if (opc2 == 1){
                printf ("Digite o numero do voo: ");
                scanf ("%d", &esc);

                for (i=0; i<4; i++){
                    cont = 0;
                    for (j=0; j<nvoo[i]; j++)
                        if (nvoo[i] != esc)
                            cont=1;

                    if ( cont == 0)
                        printf ("voo numero: %d, origem: %s, destino: %s, lugares disponiveis: %d\n\n", nvoo[i], origem[i], destino[i], lugares[i]);
                }

                if (i ==  3)
                    printf ("Nao ha mais voos disponiveis.");
                printf ("\n\n\n\n");
            }

            else if (opc2 == 2){
                printf ("Digite o local do voo: ");
                scanf (" %[^\n]", &local);
                cont =0;
                for (i=0; i<4; i++)
                    if (strcmp(origem[i],local)==0){
                        printf ("Origem: %s, destino: %s, numero do voo: %d, lugares disponiveis: %d\n\n", origem[i], destino[i], nvoo[i], lugares[i]);
                        cont =1;
                    }

                if ( cont==0)
                    printf ("Esse local nao existe");
            }

            else if (opc2 == 3){
                printf ("Digite o destino do voo: ");
                scanf (" %[^\n]", &dest);
                cont =0;

                for (i=0; i<4; i++){
                    if (strcmp(destino[i],dest)==0){
                        printf ("Destino: %s, origem: %s, numero do voo: %d, lugares disponiveis: %d\n\n", destino[i], origem[i], nvoo[i], lugares[i]);
                        cont =1;
                    }
                }
                if ( cont==0)
                    printf ("Esse destino nao existe");
                printf ("\n\n\n\n");
            }
        }

        if (opc == 2){
            system ("cls");
            printf ("Em que voo deseja viajar ?");
            printf ("\n\nSua escolha: ");
            scanf ("%d", &escvoo);

            while (escvoo > 4){
                printf ("Voo nao encontrado, digite novamente: ");
                scanf ("%d", &escvoo);
            }

            i=0;
            while (escvoo != nvoo[i]) // SE NAO TIVER ISSO O INDICE DO VETOR LUGARES NAO DECREMENTA
                i++;

            if (lugares[i] != 0){
                printf ("\nSua reserva foi concluida com sucesso\n\n");
                lugares[i] = lugares[i] - 1; //DECREMENTANDO DO VETOR LUGAR
                printf ("\n\n\n\n");
            }
            else // CASO ALGUM INDICE DO VETOR LUGARES ZERE/ 1-1-3-5 ELE IRA INFORMAR.
            {
                printf("\nEsse voo esta cheio no momento!!\n\n");
                printf ("\n\n\n\n");

            }
        }
    }

    return 0;
}
