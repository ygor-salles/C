#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 1. Foi realizada uma pesquisa sobre algumas características físicas de n habitantes de uma região.
Foram coletados os seguintes dados de cada habitante:
(a) sexo: M - masculino, ou F - feminino;
(b) cor dos olhos: A - azuis, ou C - castanhos;
(c) cor dos cabelos: L - louros, P - pretos, ou C - castanhos;
(d) idade.
Faça um programa em linguagem C que leia a quantidade n de habitantes da região e imprima
os valores calculados pelas funções a seguir:
(a) Que leia esses dados, armazenando-os em vetores (um vetor para cada característica).
(b) Que determine e devolva ao programa principal a média de idade das pessoas com olhos
castanhos e cabelos pretos.
(c) Que determine e devolva ao programa principal a maior idade entre os habitantes.

(d) Que determine e devolva ao programa principal a quantidade de indivíduos do sexo femi-
nino com idade entre 18 e 35 anos (inclusive) e que tenham olhos azuis e cabelos louros.

(e) Que preencha a diagonal principal de uma matriz M de tamanho nxn com a idade dos
habitantes, o restante das posições devem ter valor zero. */

void funcaoA (int n, char sexo[], char olho[], char cabelo[], int idade[]);
void funcaoB (int n, char olho[], char cabelo[], int idade[], float *media);
void funcaoC (int n, int idade[], int *maior_idade);
void funcaoD (int n, char sexo[], int idade[], char olho[], char cabelo[], int *individuo);
void funcaoE (int n, int idade[], int l, int c, int mat[][c]);
int i;

int main ()
{
    setlocale (LC_ALL, "Portuguese");
    int n;
    printf ("Digite N numero de habitantes: ");
    scanf ("%d",&n);
    printf ("\n");

    char sexo[n], olho[n], cabelo[n];
    int idade[n];

    funcaoA (n, sexo, olho, cabelo, idade);

    float media=0;
    funcaoB (n, olho, cabelo, idade, &media);
    printf ("\nA media de idade das pessoas com olhos castanhos e cabelos pretos é: %.2f\n",media);

    int maior_idade;
    funcaoC (n, idade, &maior_idade);
    printf ("\nA maior idade entre os habitantes é: %d\n",maior_idade);

    int individuo=0;
    funcaoD (n, sexo, idade, olho, cabelo, &individuo);
    printf ("\n%d Indivíduo(s) do sexo feminino com idade entre 18 e 35 anos (inclusive) e que possuem olhos azuis e cabelos louros\n",individuo);

    int l, c, j;
    printf ("\nDigite o numero de linhas da matriz: "); scanf ("%d",&l);
    printf ("Digite o numero de colunas da matriz: "); scanf ("%d",&c);
    int mat[l][c];
    funcaoE (n, idade, l, c, mat);
    for (i=0; i<l; i++){
        for (j=0; j<c; j++){
            printf ("_%d_|",mat[i][j]);
        }
        printf ("\n");
    }

    return 0;
}

void funcaoA (int n, char sexo[], char olho[], char cabelo[], int idade[])
{
    for (i=0; i<n; i++){
        printf ("Digite o sexo(F/M): ");
        scanf (" %c",&sexo[i]);
        printf ("Digite a cor dos olhos(A/C): ");
        scanf (" %c",&olho[i]);
        printf ("Digite a cor do cabelo(L/P/C): ");
        scanf (" %c",&cabelo[i]);
        printf ("Digite a idade: ");
        scanf ("%d",&idade[i]);
        printf ("\n");
    }
    return ;
}

void funcaoB (int n, char olho[], char cabelo[], int idade[], float *media)
{
    int cont=0;
    for (i=0; i<n; i++){
        if ((olho[i]=='c' || olho[i]=='C') && (cabelo[i]=='p' || cabelo[i]=='P')){
            *media = *media+idade[i];
            cont++;
        }
    }
    if (cont>0)
        *media = *media/(float)cont;
    else
        *media = 0;

    return ;
}

void funcaoC (int n, int idade[], int *maior_idade)
{
    *maior_idade = idade[0];
    for (i=0; i<n; i++)
        if (i>0)
            if (idade[i] > *maior_idade)
                *maior_idade = idade[i];
    return ;
}

void funcaoD (int n, char sexo[], int idade[], char olho[], char cabelo[], int *individuo)
{
    for (i=0; i<n; i++)
        if ((sexo[i]=='f' || sexo[i]=='F') && (idade[i]>=18 && idade[i]<=35) && (olho[i]=='a' || olho[i]=='A') && (cabelo[i]=='l' || cabelo[i]=='L'))
            ++(*individuo);
    return ;
}

void funcaoE (int n, int idade[], int l, int c, int mat[][c])
{
    int j;
    for (i=0; i<l; i++)
        for (j=0; j<c; j++){
            if (i == j)
                mat[i][j] = idade[i];
            else
                mat[i][j] = 0;
        }

    return ;
}
