#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/* 3. Crie um registro (struct) ALUNO que contenha os seguintes campos:
(a) int matricula;
(b) char nome[50];
(c) int dia_nasc;
(d) int mes_nasc;
(e) int ano_nasc;
(f) oat nota;
Escreva um programa que leia o número n de alunos a serem cadastrados. Em seguida, um
vetor V com n posições deve ser alocado dinamicamente usando uma função que retorna um
ponteiro do tipo ALUNO. O programa deve preencher o vetor V e imprimir o registro dos
alunos aprovados, isto é, com nota maior ou igual a 6,0. Para executar tais tarefas devem ser
criadas funções para:
(a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
(b) Preencher o vetor de alunos.
(c) Imprimir o vetor de alunos.
(d) Preencher o registro de um aluno.
(e) Imprimir o registro de um aluno. */

typedef struct
{
    long matricula;
    int dia_nasc, mes_nasc, ano_nasc;
    char nome[51];
    float nota;
} aluno;

aluno *alocar_vetor(int n);
void preencher_vetor (int n, aluno *v);
void imprimir_vetor (int n, aluno *v);
void preencher_registro (int n, aluno *v, char registro[][51], int *k);
void imprimir_registro (int n, aluno *v, char registro[][51], int k);

int main ()
{
    setlocale (LC_ALL, "Portuguese");
    aluno *v;
    int n;
    printf ("Digite a qtd N de alunos: "); scanf ("%d",&n);

    //vetor v Alocado Dinamicamente
    v = alocar_vetor(n);
    preencher_vetor (n, v);
    imprimir_vetor (n, v);

    //vetor registro Alocado Estaticamente
    char registro[n][51]; int k=0;
    preencher_registro(n, v, registro, &k);
    imprimir_registro (n, v, registro, k);

    free(v);

    printf ("\n\n");
    system("pause");
    return 0;
}

aluno *alocar_vetor (int n)
{
    aluno *v;
    v = (aluno*) malloc(n * sizeof(aluno));
    if (v==NULL)
        printf ("Memoria insuficiente!");

    return v;
}

void preencher_vetor (int n, aluno *v)
{
    int i;
    for (i=0; i<n; i++){
        printf ("\nDigite nome: ");
        scanf (" %[^\n]",v[i].nome);
        printf ("Digite matrícula: ");
        scanf ("%d",&v[i].matricula);
        printf ("Digite dia de nascimento: ");
        scanf ("%d",&v[i].dia_nasc);
        printf ("Digite mês nacimento: ");
        scanf ("%d",&v[i].mes_nasc);
        printf ("Digite ano nascimento: ");
        scanf ("%d",&v[i].ano_nasc);
        printf ("Digite a nota: ");
        scanf ("%f",&v[i].nota);
    }
    printf ("\n");
    return ;
}

void imprimir_vetor (int n, aluno *v)
{
    int i;
    for (i=0; i<n; i++){
        printf ("\nNome: %s",v[i].nome);
        printf ("\nMatrícula: %d     Data de nascimento: %d/%d/%d",v[i].matricula, v[i].dia_nasc, v[i].mes_nasc, v[i].ano_nasc);
        printf ("\nNOTA: %.2f\n",v[i].nota);
    }
    return ;
}

void preencher_registro (int n, aluno *v, char registro[][51], int *k)
{
    int i;
    for (i=0; i<n; i++)
        if (v[i].nota >= 6){
            strcpy(registro[*k], v[i].nome);
            ++(*k);
        }
    return ;
}

void imprimir_registro (int n, aluno *v, char registro[][51], int k)
{
    int i;
    printf ("\nO registro de alunos aprovados é: ");
    for (i=0; i<k; i++)
        printf ("\n%s",registro[i]);

    return;
}
