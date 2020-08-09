#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*6. Elabore uma função que receba uma matriz de nomes e um nome e retorne -1
se o nome não está na matriz. Caso o nome seja encontrado, retorne o índice da linha.
Use esta função e a função do exercício 3 para preencher uma matriz de nomes digitados
pelo usuário e verificar se o nome “João Francisco da Silva” foi digitado.
A quantidade de nomes que deverão ser preenchidos deverá ser fornecida pelo usuário. */

void preenche (char m[][101], char nome[], int *retorna, int n);
void nomes (char m[][101], char nome[], int *retorna, int n);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    char m[100][101], nome[101];
    int retorna, n, i, semafaro=0;

    printf ("Digite a quantidade de nomes da lista: ");
    scanf ("%d",&n);

    preenche (m, nome, &retorna, n);

    nomes (m, nome, &retorna, n);
    printf ("\nÍncice da linha %d que o nome %s se encontra\n",retorna, nome);

    for (i=0; i<n; i++)
        if (strcmp(m[i], "joao francisco da silva")==0)
            semafaro = 1;

    if (semafaro == 1)
        printf ("\nO nome completo do João foi digitado\n");
    else
        printf ("\nO nome completo do João NÃO foi digitado\n");

    return 0;
}

void preenche (char m[][101], char nome[], int *retorna, int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",m[i]);
    }
    printf ("\n");

    printf ("Digite um nome: ");
    scanf (" %[^\n]",nome);

    return ;
}

void nomes (char m[][101], char nome[], int *retorna, int n)
{
    int i;
    *retorna = -1;
    for (i=0; i<n; i++)
        if (strcmp(m[i], nome)==0)
            *retorna = i+1;

    return ;
}
