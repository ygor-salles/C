#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*3. Seja uma estrutura para descrever os livros de uma loja, contendo os seguintes campos:
t�tulo: string de tamanho 15
autor: string de tamanho 20
estilo: string de tamanho 10
c�digo: inteiro
pre�o: real
a) Escrever a defini��o da estrutura livro.
b) Seja o seguinte trecho de programa: */

struct livro
{
    char titulo[15], autor[20], estilo[10];
    int cod;
    float preco;
};

// declara��o de vari�veis
struct livro vetlivro[50];
char ch;
int numlivros = 0, semafaro_media=0; // numero de livros


// defini��o da fun��o menu( ):
void menu( )
{
    printf(" Digite I para incluir um livro. \n");
    printf(" Digite L para listar o nome de todos os livros. \n");
    printf(" Digite A para procurar livro por autor. \n");
    printf(" Digite T para procurar livro por t�tulo. \n");
    printf(" Digite E para procurar livro por estilo. \n");
    printf(" Digite M para calcular a m�dia de pre�o de todos os livros. \n");
    printf( " Digite S para sair \n");
    scanf (" %c",&ch);
}

void incluir_liv();
void lista_liv();
void proc_autor ();
void proc_titulo ();
void proc_estilo ();
void media_preco ();

// defini��o da fun��o principal
main( )
{
    setlocale(LC_ALL, "Portuguese");
    printf ("Digite a quantidade de livros: ");
    scanf ("%d",&numlivros);
    int i;
    for (i=0; i<numlivros; i++){
        printf ("Digite titulo: ");
        scanf (" %[^\n]",vetlivro[i].titulo);
        printf ("Digite autor: ");
        scanf (" %[^\n]",vetlivro[i].autor);
        printf ("Digite estilo: ");
        scanf (" %[^\n]",vetlivro[i].estilo);
        printf ("Digite codigo: ");
        scanf ("%d",&vetlivro[i].cod);
        printf ("Digite preco: ");
        scanf ("%f",&vetlivro[i].preco);
        printf ("\n");
    }

    menu( );
    if (ch == 'S'){
        return 0;
    }
    else{
        while (ch != 'S') {
            switch(ch) {
            case 'I': incluir_liv( ); break;
            case 'L': lista_liv( ); break;
            case 'A': proc_autor( ); break;
            case 'T': proc_titulo( ); break;
            case 'E': proc_estilo( ); break;
            case 'M': media_preco( ); break;
            } // fim do switch
            if (ch == 'I')
                semafaro_media++;
            menu( );
        }
    }
    return 0;
} // fim da fun��o main.

void incluir_liv()
{
    int semafaro=0;
    if (semafaro>=1)
        numlivros++;

    printf ("Digite titulo: ");
    scanf (" %[^\n]",vetlivro[numlivros].titulo);
    printf ("Digite autor: ");
    scanf (" %[^\n]",vetlivro[numlivros].autor);
    printf ("Digite estilo: ");
    scanf (" %[^\n]",vetlivro[numlivros].estilo);
    printf ("Digite codigo: ");
    scanf ("%d",&vetlivro[numlivros].cod);
    printf ("Digite preco: ");
    scanf ("%f",&vetlivro[numlivros].preco);
    printf ("\n");
    semafaro++;

    return ;
}

void lista_liv()
{
    int i;
    if (semafaro_media >= 1){
        for (i=0; i<=numlivros; i++){
            printf ("\n%s\n %s\n %s\n %d\n %.2f\n",vetlivro[i].titulo, vetlivro[i].autor, vetlivro[i].estilo, vetlivro[i].cod, vetlivro[i].preco);
        }
        printf ("\n");
    }
    else{
        for (i=0; i<numlivros; i++){
            printf ("\n%s\n %s\n %s\n %d\n %.2f\n",vetlivro[i].titulo, vetlivro[i].autor, vetlivro[i].estilo, vetlivro[i].cod, vetlivro[i].preco);
        }
        printf ("\n");
    }
    return ;
}

void proc_autor ()
{
    int i, semafaro=0;
    char autor[20];
    printf ("Digite o autor requirido: ");
    scanf (" %[^\n]",autor);
    for (i=0; i<=numlivros; i++){
        if (strcmp(vetlivro[i].autor, autor)==0){
            printf ("Autor Encontrado!\n\n");
            semafaro=1;
            break;
        }
    }
    if (semafaro==0)
        printf ("Autor n�o encontrado!\n\n");

    return ;
}

void proc_titulo ()
{
    int i, semafaro=0;
    char titulo[15];
    printf ("Digite o titulo requirido: ");
    scanf (" %[^\n]",titulo);
    for (i=0; i<=numlivros; i++){
        if (strcmp(vetlivro[i].titulo, titulo)==0){
            printf ("T�tulo Encontrado!\n\n");
            semafaro=1;
            break;
        }
    }
    if (semafaro==0)
        printf ("T�tulo n�o encontrado!\n\n");

    return ;
}

void proc_estilo ()
{
    int i, semafaro=0;
    char estilo[20];
    printf ("Digite o estilo requirido: ");
    scanf (" %[^\n]",estilo);
    for (i=0; i<=numlivros; i++){
        if (strcmp(vetlivro[i].estilo, estilo)==0){
            printf ("Estilo Encontrado!\n\n");
            semafaro=1;
            break;
        }
    }
    if (semafaro==0)
        printf ("Estilo n�o encontrado!\n\n");

    return ;
}

void media_preco ()
{
    int i;
    float media=0;
    if (semafaro_media >= 1){
        for (i=0; i<=numlivros; i++){
            media = media + vetlivro[i].preco;
        }
        printf ("A m�dia de pre�os dos livros �: R$%.2f\n\n",media/(numlivros+1));
    }
    else{
        for (i=0; i<numlivros; i++){
            media = media + vetlivro[i].preco;
        }
        printf ("A m�dia de pre�os dos livros �: R$%.2f\n\n",media/(numlivros));
    }

    return ;
}
