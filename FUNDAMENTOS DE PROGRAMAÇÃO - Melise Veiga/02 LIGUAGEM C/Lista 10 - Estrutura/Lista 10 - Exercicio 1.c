#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/*1. Crie uma estrutura para representar as informações de um aluno contendo os seguintes dados:
matrícula (inteiro), código do curso (inteiro) e rendimento acadêmico (float).
a. No programa principal, use a estrutura elaborada para preencher as informações de um
aluno com dados digitados no teclado.
b. Imprima estas informações na tela.
c. Crie um campo nome na estrutura que deve ser uma cadeia de caractere de tamanho
máximo = 100.
d. No programa, depois de imprimir as informações do aluno, verifique se o nome do aluno
é “João Jose da Silva”. Se for, imprima a matrícula do aluno. Caso contrário, imprima
“Aluno não encontrado”. */

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
    printf ("Digite a matrícula: ");
    scanf ("%d",&a.mat);
    printf ("Digite o código: ");
    scanf ("%d",&a.cod);
    printf ("Digite o rendimento: ");
    scanf ("%f",&a.rend);

    printf ("\n\n*****************************\n\n");

    printf ("Os dados são: \n%s \n%d \n%d \nR$%.2f\n",a.nome, a.mat, a.cod, a.rend);

    if (strcmp(a.nome, "joao jose da silva")==0)
        printf ("\nMatrícula: %d\n",a.mat);
    else
        printf ("\nAluno não encontrado\n");

    return 0;
}
