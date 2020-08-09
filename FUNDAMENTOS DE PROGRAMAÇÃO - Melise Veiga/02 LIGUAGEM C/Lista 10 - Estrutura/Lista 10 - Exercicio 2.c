#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/* 2. Elabore uma estrutura para armazenar as informa��es de um livro contendo os seguintes dados: c�digo (inteiro), t�tulo (cadeia de caractere de tamanho m�ximo = 100) e ano de publica��o (inteiro)
a. No programa principal, use a estrutura elaborada para preencher as informa��es de um livro com dados digitados no teclado.
b. Imprima estas informa��es na tela.
c. Elabore uma fun��o que receba as informa��es de um livro, um c�digo e um valor de ano. Caso o livro recebido tenha o c�digo igual ao que foi passado como par�metro, altere o ano do livro para o novo valor. Como essa estrutura deve ser passada como par�metro? Refer�ncia ou valor? E os demais par�metros?
d. Elabore uma fun��o que receba uma estrutura livro e imprima as informa��es do livro na tela (um dado por linha).
e. Elabore uma fun��o que receba um livro e um t�tulo, caso o t�tulo do livro seja igual ao t�tulo recebido, imprimir uma mensagem informando que o livro foi encontrado, caso contr�rio, informar que o livro n�o existe.
f. Nas fun��es (d) e (e), como foi a passagem de par�metro? Foi necess�rio passar a refer�ncia (ou o endere�o) da estrutura livro?
g. Modifque a fun��o da letra (e) de maneira que, caso o t�tulo do livro seja igual ao t�tulo recebido pela fun��o, o ano de publica��o do livro deve ser alterado somando 10 ao valor atual. Nesse caso, � necess�rio passar o endere�o do livro?
h. Crie um vetor de, no m�ximo, 50 livros e preencha as informa��es dos livros com dados digitados no teclado. A quantidade de livros na lista a ser preenchida deve ser fornecida pelo usu�rio.
i. Altere a estrutura criada e adicione um campo que deve ser chamado de status que dever� receber uma letra (A (ativo) ou I (inativo)).
j. Elabore uma fun��o que receba as informa��es dos livros (a lista de livros) e caso o livro tenha sido publicado antes do ano 1950, preencher o status do livro com o valor I, caso contr�rio, preencher o status do livro com o valor A. */

typedef struct livro
{
    int cod, ano;
    char tit[100], status;
}tlivro;

void imprimeLivro (tlivro l);
void alteraAno (tlivro *pl, int cd, int an);
void imprimeLivro2 (tlivro *pl, int cd, int an);
void verificaLivro (tlivro l, char titulo[]);
void verificaLivro2 (tlivro *pl, char titulo[]);
void alteraStatus (tlivro lista[], int n);

int main ()
{
   setlocale(LC_ALL, "Portuguese");
   tlivro l;

   //Quest�o A
   printf ("Digite t�tulo, c�digo e ano, respectivamente: \n");
   scanf (" %[^\n] %d %d", l.tit, &l.cod, &l.ano);

   //Quest�o B
   imprimeLivro (l);

   //Quest�o C
   int cd, an;
   printf ("\nDigite codigo e ano para compara��o, respectivamente: \n");
   scanf (" %d %d",&cd, &an);
   alteraAno (&l, cd, an);

   //Quest�o D
   imprimeLivro2 (&l, cd, an);

   //Quest�o E
   char titulo[51];
   printf ("\nDigite um titulo para compara��o: ");
   scanf (" %[^\n]",titulo);
   verificaLivro (l, titulo);

   //Quest�o G
   verificaLivro2 (&l, titulo);
   printf ("\nO novo valor do ano �: %d\n",l.ano);

   //Quest�o H I J
   tlivro lista[50];
   int i, n;

    printf ("\nDigite a quantidade n da lista de livros: ");
    scanf ("%d",&n);
    if (n>0 && n<=50){
        for (i=0; i<n; i++){
            printf ("\nDigite titulo, c�digo e ano respectivamente: \n");
            scanf (" %[^\n] %d %d", lista[i].tit, &lista[i].cod, &lista[i].ano);
        }
        alteraStatus (lista, n);
    }

    return 0;
}

void imprimeLivro (tlivro l)
{
    printf ("\nOs dados s�o: \n %d\n %d\n %s\n", l.cod, l.ano, l.tit);
}

void alteraAno (tlivro *pl, int cd, int an)
{
    if (pl->cod==cd)
        pl->ano = an;
}

void imprimeLivro2 (tlivro *pl, int cd, int an)
{
    printf ("\nAs novas informa��es do livro s�o: \n%s \n%d \n%d\n",pl->tit, pl->cod, pl->ano);
}

void verificaLivro (tlivro l, char titulo[])
{
    if (strcmp(l.tit,titulo)==0)
        printf ("Livro encontrado!\n");
    else
        printf ("Livro n�o existe!\n");
}

void verificaLivro2 (tlivro *pl, char titulo[])
{
    if (strcmp(pl->tit,titulo)==0)
        pl->ano = pl->ano+10;
}

void alteraStatus (tlivro lista[], int n)
{
    int i;
    for (i=0; i<n; i++)
        if (lista[i].ano>1950)
            lista[i].status = 'A';
        else
            lista[i].status = 'N';
}
