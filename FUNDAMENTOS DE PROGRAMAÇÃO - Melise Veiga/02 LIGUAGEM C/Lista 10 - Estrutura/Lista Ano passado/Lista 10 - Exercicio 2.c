#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*2. Elabore uma estrutura para armazenar as informa��es de um livro contendo os seguintes dados:
c�digo (inteiro), t�tulo (cadeia de caracter de tamanho m�ximo = 100) e ano de publica��o (inteiro)
a. No programa principal, use a estrutura elaborada para preencher as informa��es de um livro com dados digitados no teclado.
b. Imprima estas informa��es na tela. */

struct livro
{
    int cod, ano;
    char titulo[101];
};

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    struct livro x;
    printf ("Digite o c�digo, ano e t�tulo de publica��o respectivamente: \n");
    scanf (" %d %d %[^\n]", &x.cod, &x.ano, x.titulo);

    printf ("\n*****************************************\n");

    printf ("\n%d\n",x.cod);
    printf ("%d\n",x.ano);
    printf ("%s\n",x.titulo);

    return 0;
}
