#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*2. Elabore uma estrutura para armazenar as informações de um livro contendo os seguintes dados:
código (inteiro), título (cadeia de caracter de tamanho máximo = 100) e ano de publicação (inteiro)
a. No programa principal, use a estrutura elaborada para preencher as informações de um livro com dados digitados no teclado.
b. Imprima estas informações na tela. */

struct livro
{
    int cod, ano;
    char titulo[101];
};

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    struct livro x;
    printf ("Digite o código, ano e título de publicação respectivamente: \n");
    scanf (" %d %d %[^\n]", &x.cod, &x.ano, x.titulo);

    printf ("\n*****************************************\n");

    printf ("\n%d\n",x.cod);
    printf ("%d\n",x.ano);
    printf ("%s\n",x.titulo);

    return 0;
}
