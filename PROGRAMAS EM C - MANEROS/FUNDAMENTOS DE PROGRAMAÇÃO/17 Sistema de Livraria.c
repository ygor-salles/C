#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/* 12. Seja uma estrutura para descrever os livros de uma loja, contendo os seguintes campos:
• título: string de tamanho 15
• autor: string de tamanho 20
• estilo: string de tamanho 10
• código: inteiro
• preço: real
a) Escrever a definição da estrutura livro.
b) Crie o tipo tlivro a partir da estrutura criada na letra a.
Seja o seguinte trecho de programa:
[...]
c) Altere a função main substituindo a estrutura de repetição while por repeat.
d) Escrever a funções que estão faltando. Para cada função, verifique o objetivo
definido no comentário da função menu e defina quais parâmetros serão
necessários. */

typedef struct
{
    char titulo[15], autor[20], estilo[10];
    int codigo;
    float preco;
} tlivro;

void menu( )
{
    printf(" \nDigite I para incluir um livro. \n");
    printf(" Digite L para listar o nome de todos os livros. \n");
    printf(" Digite A para procurar livro por autor. \n");
    printf(" Digite T para procurar livro por título. \n");
    printf(" Digite E para procurar livro por estilo. \n");
    printf(" Digite M para calcular a média de preço de todos os livros. \n");
    printf( " Digite S para sair \n");
    printf(" --->: ");

    return ;
}

void printar(tlivro vetlivro[], int i)
{
    printf("\nTÍTULO: %s",vetlivro[i].titulo);
    printf("\nAUTOR: %s",vetlivro[i].autor);
    printf("\nESTILO: %s",vetlivro[i].estilo);
    printf("\nCÓDIGO: %d",vetlivro[i].codigo);
    printf("\nPREÇO: $%.2f",vetlivro[i].preco);

    printf("\n\n"); system("pause");
    system("CLS");
    return ;
}

void incluir_liv(tlivro vetlivro[], int *numlivros)
{
    printf("\nDigite o título: "); scanf(" %[^\n]",vetlivro[*numlivros].titulo);
    printf("Digite o autor: "); scanf(" %[^\n]",vetlivro[*numlivros].autor);
    printf("Digite o estilo: "); scanf(" %[^\n]",vetlivro[*numlivros].estilo);
    printf("Digite o código: "); scanf("%d",&vetlivro[*numlivros].codigo);
    printf("Digite o preço: "); scanf("%f",&vetlivro[*numlivros].preco);
    ++(*numlivros); printf ("\nQTD DE LIVROS CADASTARADOS: %d",*numlivros);

    printf("\n"); system("pause");
    system("CLS");
    return ;
}

void lista_liv(tlivro vetlivro[], int *numlivros)
{
    int i;
    printf ("\nLISTA NOME DE LIVROS: %d\n",*numlivros);
    for (i=0; i<*numlivros; i++)
        printf ("\n %s\n",vetlivro[i].titulo);

    printf("\n\n"); system("pause");
    system("CLS");
    return ;
}

void proc_autor(tlivro vetlivro[], int *numlivros)
{
    int i, semafaro=0;
    char autor[20];
    printf ("\nDigite o autor a ser proucurado: "); scanf(" %[^\n]",autor);

    for (i=0; i<*numlivros; i++)
        if (strcmp(vetlivro[i].autor,autor)==0){
            printar(vetlivro, i); semafaro=1;
        }

    if (semafaro==0){
        printf("\nAUTOR INEXISTENTE!\n");
        printf("\n"); system("pause");
        system("CLS");
    }

    return ;
}

void proc_titulo(tlivro vetlivro[], int *numlivros)
{
    int i, semafaro=0;
    char titulo[15];
    printf ("\nDigite o título a ser proucurado: "); scanf(" %[^\n]",titulo);

    for (i=0; i<*numlivros; i++)
        if (strcmp(vetlivro[i].titulo,titulo)==0){
            printar(vetlivro, i); semafaro=1;
        }

    if (semafaro==0){
        printf("\nTÍTULO INEXISTENTE!\n");
        printf("\n"); system("pause");
        system("CLS");
    }

    return ;
}

void proc_estilo(tlivro vetlivro[], int *numlivros)
{
    int i, semafaro=0;
    char estilo[10];
    printf ("\nDigite o estilo a ser proucurado: "); scanf(" %[^\n]",estilo);

    for (i=0; i<*numlivros; i++)
        if (strcmp(vetlivro[i].estilo,estilo)==0){
            printar(vetlivro, i); semafaro=1;
        }

    if (semafaro==0){
        printf("\nESTILO INEXISTENTE!\n");
        printf("\n"); system("pause");
        system("CLS");
    }

    return ;
}

void media_preco(tlivro vetlivro[], int *numlivros)
{
    int i;
    float media=0;
    for(i=0; i<*numlivros; i++)
        media = media + vetlivro[i].preco;

    printf ("\nA MÉDIA DE TODOS OS PREÇOS É: %.2f\n",media/(float)*numlivros);

    printf("\n\n"); system("pause");
    system("CLS");
    return ;
}

int main( )
{
    setlocale(LC_ALL, "Portuguese");
    tlivro vetlivro[50];
    char ch;
    int numlivros = 0;

    printf ("\n**** HABILITE O CAPS LOOK OU FIXA DO TECLADO, PARA QUE O PROGRAMA FUNCIONE CORRETAMENTE ****\n");
    menu( );
    scanf(" %c", &ch);

    while (ch != 'S') {
        switch(ch) {
            case 'I': incluir_liv(vetlivro, &numlivros); break;
            case 'L': lista_liv(vetlivro, &numlivros); break;
            case 'A': proc_autor(vetlivro, &numlivros); break;
            case 'T': proc_titulo(vetlivro, &numlivros); break;
            case 'E': proc_estilo(vetlivro, &numlivros); break;
            case 'M': media_preco(vetlivro, &numlivros); break;
        }
    menu( );
    scanf(" %c", &ch);
    }
    return 0;
}
