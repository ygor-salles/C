#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/* 5. Utilizando a estrutura do exercício 1, crie um programa para facilitar o gerenciamento das
informações dos alunos de uma turma. A turma tem, no máximo, 50 alunos. A quantidade de
alunos deve ser fornecida pelo usuário. Crie funções para:
a. Preencher a lista de alunos;
b. Imprimir os dados de todos os alunos da lista;
c. Dado um número de matrícula, verificar se o aluno existe na lista. Se existir, imprima o
nome. Caso contrário, imprima uma mensagem de notificação;
d. Dado um nome, imprimir os dados de todos os alunos com o mesmo nome. Considere
que há alunos com nomes repetidos.
e. Dado um nome, retornar a quantidade de alunos com o nome fornecido. */

typedef struct aluno
{
    int mat, cod;
    float rend;
    char nome[51];
} taluno;

void funcaoA (taluno lista[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",lista[i].nome);
        printf ("Digite matricula: ");
        scanf ("%d",&lista[i].mat);
        printf ("Digite código: ");
        scanf ("%d",&lista[i].cod);
        printf ("Digite a renda: ");
        scanf ("%f",&lista[i].rend);
        printf ("\n");
    }
    return ;
}

void funcaoB (taluno lista[], int n)
{
    int i;
    printf ("\nSeguido por: Nome / Matricula / Código / Rendimento\n");
    for (i=0; i<n; i++){
        printf ("\n %s %7d %10d %9.2f", lista[i].nome, lista[i].mat, lista[i].cod, lista[i].rend);
        printf ("\n");
    }
    return ;
}

void funcaoC (taluno lista[], int n)
{
    int i, matricula, semafaro=0;
    printf ("\n\nDigite uma matrícula: "); scanf ("%d",&matricula);
    for (i=0; i<n; i++){
        if (lista[i].mat == matricula){
            printf ("%s",lista[i].nome);
            semafaro=1;
            printf ("\n");
            break;
        }
    }
    if (semafaro == 0)
        printf ("A matrícula não existe na lista!\n");
    return ;
}

void funcaoD (taluno lista[], int n)
{
    int i;  char nome[51];
    printf ("\nDigite um nome: ");    scanf (" %[^\n]",nome);

    for (i=0; i<n; i++){
        if (strcmp(lista[i].nome,nome)==0)
            printf ("\n %s %7d %10d %9.2f", lista[i].nome, lista[i].mat, lista[i].cod, lista[i].rend);
    }
    printf ("\n");
    return ;
}

void funcaoE (taluno lista[], int n, int *cont, char nome[])
{
    int i;
    *cont=0;
    printf ("\n\nDigite um nome: ");    scanf (" %[^\n]",nome);
    for (i=0; i<n; i++){
        if (strcmp(lista[i].nome,nome)==0)
            ++(*cont);
    }
    return ;
}

int main ()
{
    setlocale (LC_ALL, "Portuguese");
    int n, cont;
    char nome[51];
    taluno lista[50];

    printf ("Digite quantidade de alunos: ");
    scanf ("%d",&n);

    printf ("\n");
    funcaoA (lista, n);
    funcaoB (lista, n);
    funcaoC (lista, n);
    funcaoD (lista, n);
    funcaoE (lista, n, &cont, nome);
    printf ("A quantidade de alunos com o nome %s são: %d\n",nome, cont);

    return 0;
}
