#include<stdio.h>
#include<stdlib.h>

/*1. Crie uma estrutura para representar as informa��es de um aluno contendo os seguintes
dados: matr�cula (inteiro), c�digo do curso (inteiro) e rendimento acad�mico (float).
a. No programa principal, use a estrutura elaborada para preencher as informa��es de um aluno com dados digitados no teclado.
b. Imprima estas informa��es na tela. */

typedef struct aluno
{
    int mat, cod;
    float rend;
} aluno;

int main ()
{
    aluno a;
    printf ("Digite a matricula, codigo e rendimento respectivamente: \n");
    scanf ("%d %d %f", &a.mat, &a.cod, &a.rend);

    printf ("\n***********************************************\n");
    printf ("\n\n %d %d %.2f\n",a.mat, a.cod, a.rend);
    return 0;
}
