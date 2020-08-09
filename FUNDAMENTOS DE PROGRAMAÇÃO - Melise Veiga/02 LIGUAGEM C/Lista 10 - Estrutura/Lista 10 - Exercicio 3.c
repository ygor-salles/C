#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 3. A partir da estrutura criada no exerc�cio 1, crie um vetor para armazenar uma lista de, no m�ximo, 40 alunos.
a. Elabore uma fun��o que preencha o vetor com informa��es digitadas pelo usu�rio. A quantidade de alunos da lista tamb�m deve ser passada como par�metro.
b. Elabore uma fun��o que retorne a quantidade de alunos que possuem rendimento maior que X, X deve ser passado como par�metro. Analise a fun��o e veja se � necess�rio definir outros par�metros.
c. Elabore uma fun��o para aumente em X% os rendimentos acad�micos de todos os alunos do curso de c�digo = Y. O valor de X e Y devem ser passados como par�metro. Analise a fun��o e veja se � necess�rio definir outros par�metros.
d. Elabore uma fun��o que receba a lista de alunos e um c�digo de curso e imprima as informa��es dos alunos que possuem c�digo recebido. As informa��es de cada aluno devem ser impressas em linhas separadas */

typedef struct aluno
{
    char nome[51];
    int cod, mat;
    float rend;
} taluno;

void funcaoA (taluno lista[], int n);
void funcaoB (taluno lista[], int n, float x, int *retorna);
void funcaoC (taluno lista[], int n, float x, int y);
void funcaoD (taluno lista[], int codigo, int n);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, n, retorna, y, codigo;
    float x;

    printf ("Digite a quantidade de alunos: ");
    scanf ("%d",&n);

    taluno lista[n];

    //Fun��o A
    funcaoA (lista, n);

    //Fun��o B
    printf ("Digite o rendimento de X: ");
    scanf ("%f",&x);
    funcaoB (lista, n, x, &retorna);
    printf ("\nA quantidade de alunos com rendimento maior que %.2f �: %d\n",x, retorna);

    //Fun��o C
    printf ("\nDigite o c�digo de Y: ");
    scanf ("%d",&y);
    funcaoC (lista, n, x, y);

    //Fun��o D
    printf ("\nDigite um c�digo: ");
    scanf ("%d",&codigo);
    funcaoD (lista, codigo, n);

    return 0;
}

void funcaoA (taluno lista[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",lista[i].nome);
        printf ("Digite a matricula: ");
        scanf ("%d",&lista[i].mat);
        printf ("Digite c�digo: ");
        scanf ("%d",&lista[i].cod);
        printf ("Digite rendimento: ");
        scanf ("%f",&lista[i].rend);
        printf ("\n");
    }
    return ;
}

void funcaoB (taluno lista[], int n, float x, int *retorna)
{
   int i;
   *retorna = 0;
   for (i=0; i<n; i++)
        if (lista[i].rend>x)
            *retorna = *retorna + 1;

   return ;
}

void funcaoC (taluno lista[], int n, float x, int y)
{
    int i;
    for (i=0; i<n; i++){
        if (lista[i].cod == y){
            lista[i].rend = lista[i].rend+(x*(lista[i].rend/100));
        }
        printf ("%.2f\n",lista[i].rend);
    }

    return ;
}

void funcaoD (taluno lista[], int codigo, int n)
{
    int i;
    printf ("\nA lista de alunos com c�digo %d �: \n",codigo);
    for (i=0; i<n; i++)
        if (lista[i].cod == codigo)
            printf ("\n%s\n %d\n %d\n %.2f\n\n",lista[i].nome, lista[i].mat, lista[i].cod, lista[i].rend);

    return ;
}

