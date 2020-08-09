#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 3. A partir da estrutura criada no exercício 1, crie um vetor para armazenar uma lista de, no máximo, 40 alunos.
a. Elabore uma função que preencha o vetor com informações digitadas pelo usuário. A quantidade de alunos da lista também deve ser passada como parâmetro.
b. Elabore uma função que retorne a quantidade de alunos que possuem rendimento maior que X, X deve ser passado como parâmetro. Analise a função e veja se é necessário definir outros parâmetros.
c. Elabore uma função para aumente em X% os rendimentos acadêmicos de todos os alunos do curso de código = Y. O valor de X e Y devem ser passados como parâmetro. Analise a função e veja se é necessário definir outros parâmetros.
d. Elabore uma função que receba a lista de alunos e um código de curso e imprima as informações dos alunos que possuem código recebido. As informações de cada aluno devem ser impressas em linhas separadas */

typedef struct aluno
{
    char nome[51];
    int cod, mat;
    float rend;
} taluno;

void funcaoA (taluno list[], int n);
void funcaoB (taluno list[], int n, float x, int *pretorna);
void funcaoC (taluno list[], int n, float x, int y);
void funcaoD (taluno list[], int codigo, int n);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, n, retorna, y, codigo;
    float x;

    printf ("Digite a quantidade de alunos: ");
    scanf ("%d",&n);

    taluno lista[n];

    //Função A
    funcaoA (lista, n);

    //Função B
    printf ("Digite o rendimento de X: ");
    scanf ("%f",&x);
    funcaoB (lista, n, x, &retorna);
    printf ("\nA quantidade de alunos com rendimento maior que %.2f é: %d\n",x, retorna);

    //Função C
    printf ("\nDigite o código de Y: ");
    scanf ("%d",&y);
    funcaoC (lista, n, x, y);

    //Função D
    printf ("\nDigite um código: ");
    scanf ("%d",&codigo);
    funcaoD (lista, codigo, n);

    return 0;
}

void funcaoA (taluno list[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",list[i].nome);
        printf ("Digite a matricula: ");
        scanf ("%d",&list[i].mat);
        printf ("Digite código: ");
        scanf ("%d",&list[i].cod);
        printf ("Digite rendimento: ");
        scanf ("%f",&list[i].rend);
        printf ("\n");
    }
    return ;
}

void funcaoB (taluno list[], int n, float x, int *pretorna)
{
   int i;
   *pretorna = 0;
   for (i=0; i<n; i++)
        if (list[i].rend>x)
            *pretorna = *pretorna + 1;

   return ;
}

void funcaoC (taluno list[], int n, float x, int y)
{
    int i;
    for (i=0; i<n; i++){
        if (list[i].cod == y){
            list[i].rend = list[i].rend+(x*(list[i].rend/100));
        }
        printf ("%.2f\n",list[i].rend);
    }

    return ;
}

void funcaoD (taluno list[], int codigo, int n)
{
    int i;
    printf ("\nA lista de alunos com código %d é: \n",codigo);
    for (i=0; i<n; i++)
        if (list[i].cod == codigo)
            printf ("\n%s\n %d\n %d\n %.2f\n\n",list[i].nome, list[i].mat, list[i].cod, list[i].rend);

    return ;
}


