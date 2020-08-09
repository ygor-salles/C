#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

void inicializaMatriz(char m[][10])
{
    int i, j;
    for (i=0; i<10; i++)
        for(j=0; j<10; j++)
            m[i][j] = (' ');

    return ;
}

void imprimeMatriz(char m[][10])
{
    int i, j;
    for (i=0; i<10; i++){
        for(j=0; j<10; j++)
            printf(" %c",m[i][j]);
        printf("\n");
    }

    return ;
}

void imprimeOpcoes()
{
    printf("\n1 – Caneta para cima: Robô desenha a partir do próximo movimento");
    printf("\n2 – Caneta para baixo: Robô pode se mover sem desenhar");
    printf("\n3 – Anda para esquerda: Verifica se é possível andar para esquerda. Caso seja, anda e exibe matriz.");
    printf("\n4 – Anda para direita: Verifica se é possível andar para direita. Caso seja, anda e exibe matriz.");
    printf("\n5 – Anda para cima: Verifica se é possível andar para cima. Caso seja, anda e exibe matriz");
    printf("\n6 – Anda para baixo: Verifica se é possível andar para baixo. Caso seja, anda e exibe matriz.");
    printf("\n7 – Termina Desenho: Exibe a matriz pela última vez e sai do programa");
    printf("\nOpcao: ");
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    char piso[10][10];
    int linha = 0, coluna = 0;
    int pos_caneta = 0;
    int opcao;

    inicializaMatriz(piso);

    do{
        imprimeOpcoes(); scanf("%d",&opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            pos_caneta = 1;
            break;

        case 2:
            pos_caneta = 0;
            break;

        case 3:
            if(coluna > 0){
                coluna--;
                if(pos_caneta == 1)
                    piso[linha][coluna] = '*';
                imprimeMatriz(piso);
            }
            else
                printf("Operação impossível\n\n");
            break;

        case 4:
            if(coluna < 10-1){
                coluna++;
                if(pos_caneta == 1)
                    piso[linha][coluna] = '*';
                imprimeMatriz(piso);
            }
            else
                printf("Operação impossível\n\n");
            break;

        case 5:
            if(linha > 0){
                linha--;
                if(pos_caneta == 1)
                    piso[linha][coluna] = '*';
                imprimeMatriz(piso);
            }
            else
                printf("Operação impossível\n\n");
            break;

        case 6:
            if(linha < 10-1){
                linha++;
                if(pos_caneta == 1)
                    piso[linha][coluna] = '*';
                imprimeMatriz(piso);
            }
            else
                printf("Operação impossível\n\n");
            break;

        case 7:
            imprimeMatriz(piso);
            break;

        default:
            printf("Opção inválida!\n\n");
            break;

        }
        printf("\n\n");
        system("pause"); system("CLS");

    } while (opcao != 7);


    return 0;
}
