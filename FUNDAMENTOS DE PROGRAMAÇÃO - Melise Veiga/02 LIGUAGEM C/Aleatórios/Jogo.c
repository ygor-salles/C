#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//Struct responsável pelo tamanho do tabuleiro
struct{
    char* matriz;
    int linhas;
    int colunas;
}typedef matrizJogo;

//Aloca o tamanho da matriz
char* alocaTamanhoMatriz(char* matriz, int quantLinhas, int quantColunas){
    //Aloca dinamicamente a matriz com base na quantidade de linhas e colunas definidas pra ela
    matriz = (char *) calloc ((quantLinhas)*(quantColunas), sizeof(char));

    //Retorna o endereço do ponteiro com o espaço alocado
    return matriz;
}

matrizJogo setarMatriz(matrizJogo novaMatriz, int linhas, int colunas){
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;

    novaMatriz.matriz = alocaTamanhoMatriz(novaMatriz.matriz, novaMatriz.linhas, novaMatriz.colunas);

    return novaMatriz;
}

//Zera os valores da matriz, colocando um quadrado em todos os espaços reservados para as duas matrizes
void zeraValoresMatrizes(matrizJogo* comparativa, matrizJogo* original){
    int i, j;

    for(i=0;i<comparativa->linhas;i++){
        for(j=0;j<comparativa->colunas;j++){
            comparativa->matriz[(i*(comparativa->linhas)+j)]=254;
            original->matriz[i*(original->linhas)+j]=254;
        }
    }
}

//Mostra a matriz do jogo atual
void mostraMatriz(matrizJogo aparencia){
    int i, j, separacao;

    for(i=0;i<aparencia.linhas;i++){
        for(j=0;j<aparencia.colunas; j++){
            //Cria a parte inicial
            if(i==0 && j==0){
                printf("    ");

                for(separacao=0;separacao<aparencia.colunas;separacao++){
                    printf("%i ",separacao+1);
                }

                printf("\n   ");

            for(separacao=0;separacao<aparencia.colunas;separacao++){
                printf("__");
            }

            printf("_\n");
            }

            //Cria as colunas numerados a preenche com os quadrados
            if(j==0){
                printf("%i  |",i+1);
            }

            printf("%c|", aparencia.matriz[i*(aparencia.linhas)+j]);

            if(j==aparencia.colunas-1){
                    printf("\n");
            }
        }
    }

}

int main(){
    //Declaração das matrizes principais para o jogo
    matrizJogo comparativa, original;

    //Seta a matriz comparativa do jogo
    comparativa = setarMatriz(comparativa,5, 5);
    //Seta a matriz original, matriz que aparece para o usuário
    original = setarMatriz(original, 5, 5);

    //Zera o valores da ambas as matrizes
    zeraValoresMatrizes(&comparativa, &original);

    //Mostra a matriz atual do jogo do usuário
    mostraMatriz(original);

    return 0;
}
