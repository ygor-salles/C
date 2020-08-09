#include<stdio.h>
#include<stdlib.h>

/*1. Crie uma estrutura para representar as informações de um aluno contendo os seguintes
dados: matrícula (inteiro), código do curso (inteiro) e rendimento acadêmico (float).
a. No programa principal, use a estrutura elaborada para preencher as informações de um aluno com dados digitados no teclado.
b. Imprima estas informações na tela. */

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
