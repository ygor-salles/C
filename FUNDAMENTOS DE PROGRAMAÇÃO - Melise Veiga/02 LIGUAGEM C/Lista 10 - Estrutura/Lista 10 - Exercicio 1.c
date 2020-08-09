#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/*1. Crie uma estrutura para representar as informa��es de um aluno contendo os seguintes dados:
matr�cula (inteiro), c�digo do curso (inteiro) e rendimento acad�mico (float).
a. No programa principal, use a estrutura elaborada para preencher as informa��es de um
aluno com dados digitados no teclado.
b. Imprima estas informa��es na tela.
c. Crie um campo nome na estrutura que deve ser uma cadeia de caractere de tamanho
m�ximo = 100.
d. No programa, depois de imprimir as informa��es do aluno, verifique se o nome do aluno
� �Jo�o Jose da Silva�. Se for, imprima a matr�cula do aluno. Caso contr�rio, imprima
�Aluno n�o encontrado�. */

typedef struct
{
    int mat, cod;
    float rend;
    char nome[101];
} aluno;

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    aluno a;
    printf ("Digite o nome: ");
    scanf (" %[^\n]",a.nome);
    printf ("Digite a matr�cula: ");
    scanf ("%d",&a.mat);
    printf ("Digite o c�digo: ");
    scanf ("%d",&a.cod);
    printf ("Digite o rendimento: ");
    scanf ("%f",&a.rend);

    printf ("\n\n*****************************\n\n");

    printf ("Os dados s�o: \n%s \n%d \n%d \nR$%.2f\n",a.nome, a.mat, a.cod, a.rend);

    if (strcmp(a.nome, "joao jose da silva")==0)
        printf ("\nMatr�cula: %d\n",a.mat);
    else
        printf ("\nAluno n�o encontrado\n");

    return 0;
}
