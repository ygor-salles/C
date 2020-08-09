#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* BUSCA LINEAR COM STRUCT*/

typedef struct
{
    int matricula;
    char nome[30];
    int nota;
} Aluno;

int busca_Linear_nome (Aluno *V, int N, char nome[])
{
    int i;
    for(i=0; i<N; i++)
        if (strcmp(nome,V[i].nome)==0){
            printf ("\nNome: %s",V[i].nome);
            printf ("\nMatricula: %d",V[i].matricula);
            printf ("\nNota: %d\n",V[i].nota);
            return i;
        }

    return -1;
}

int main()
{
    Aluno *V;
    int N=4, i, retorna;
    char nome[30];

    V = (Aluno*) malloc(N*sizeof(Aluno));
    printf ("Preencha com nomes: \n");
    for (i=0; i<N; i++){
        scanf (" %[^\n]",V[i].nome);
        V[i].matricula = rand() % 100;
        V[i].nota = rand() % 10;
    }

    printf("\n"); system("pause");
    system("CLS");

    printf("\nDigite o nome a ser buscado no vetor: "); scanf(" %[^\n]",nome);
    retorna = busca_Linear_nome(V, N, nome);

    if (retorna == -1)
        printf("\nNao encontrado!\n");
    else
        printf("\nElemento encontrado conforme acima, indice %d \n",retorna);

    return 0;
}
