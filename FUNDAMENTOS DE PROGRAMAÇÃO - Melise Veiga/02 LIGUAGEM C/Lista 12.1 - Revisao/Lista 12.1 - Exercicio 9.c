#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*9. Resolver o exercício anterior representando os dados em um tipo novo: tAluno que deve ser definido a partir da seguinte estrutura:
o int código
o int notas[4]
Crie o vetor de tAlunos de tamanho n (n<=50) e elabore as funções especificadas no exercício anterior.*/

typedef struct alunos
{
    int cod, notas[4];
} talunos;

void funcao1 (talunos lista[], float media[], int n)
{
    int soma[n], i, j;
    for (i=0; i<n; i++){
        soma[i] = 0;
        for (j=0; j<4; j++)
            soma[i] = soma[i] + lista[i].notas[j];

        media[i] = (float)soma[i]/4;
    }
    return ;
}

void funcao2 (talunos lista[], int bimestre, float *media_bimestre, int n)
{
    int i, j;
    *media_bimestre=0;
    for (i=0; i<n; i++)
        for (j=0; j<4; j++)
            if (bimestre == j+1)
                *media_bimestre = *media_bimestre + lista[i].notas[j];

    *media_bimestre = *media_bimestre/n;

    return ;
}

void funcao3 (talunos lista[], int aluno, int n, int *pmaior_nota)
{
    int i, j;
    *pmaior_nota = lista[0].notas[0];
    for (i=0; i<n; i++){
        for (j=0; j<4; j++)
            if (aluno == i+1)
                if (lista[i].notas[j] > *pmaior_nota)
                    *pmaior_nota = lista[i].notas[j];
    }

    return ;
}

void funcao4 (talunos lista[], int aluno, float *media_aluno, int n)
{
    int i, j, soma=0;
    for (i=0; i<n; i++)
        for (j=0; j<4; j++)
            if (aluno == i+1)
                soma = soma + lista[i].notas[j];

    *media_aluno = (float)soma/4;
}

void funcao5 (talunos lista[], int bim, int *qtd, int n)
{
    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<4; j++)
            if (bim == j+1)
                if (lista[i].notas[j]<5)
                    ++(*qtd);

    return ;
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j, n;

    printf ("Digite o valor de n: ");
    scanf ("%d",&n);
    if (n>50 || n<0){
        printf ("Digite valor <= 50!\n");
        return 0;
    }
    talunos lista[n];

    for (i=0; i<n; i++){
        lista[i].cod = i+1;
        printf (" %d",lista[i].cod);
        for (j=0; j<4; j++){
            lista[i].notas[j] = rand() % 100;
            printf (" %d",lista[i].notas[j]);
        }
        printf ("\n");
    }

    //funcao i
    float media[n];
    funcao1 (lista, media, n);
    for (i=0; i<n; i++)
        printf ("\nMedia aluno[%d]: %.1f",i+1, media[i]);
    printf ("\n");

    //funcao ii
    int bimestre;
    float media_bimestre;
    printf ("\nDigite o número do bimestre: ");
    scanf ("%d",&bimestre);
    funcao2 (lista, bimestre, &media_bimestre, n);
    printf ("A média das notas do bimestre [%d] é: %.1f\n",bimestre, media_bimestre);

    //funcao iii
    int aluno, maior_nota;
    printf ("\nDigite o número do aluno: ");
    scanf ("%d",&aluno);
    funcao3 (lista, aluno, n, &maior_nota);
    printf ("A maior nota do aluno [%d] é: %d\n",aluno, maior_nota);

    //função iv
    float media_aluno;
    funcao4 (lista, aluno, &media_aluno, n);
    printf ("A média do aluno [%d] é: %.1f\n",aluno, media_aluno);

    //função v
    int bim, qtd=0;
    printf ("\nDigite o número do bimestre: ");
    scanf ("%d",&bim);
    funcao5 (lista, bim, &qtd, n);
    printf ("A quantidade de pessoas do bimestre [%d] com notas menores que 5 é: %d\n",bim, qtd);

    return 0;
}
