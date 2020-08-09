#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/* 2. Elabore uma estrutura para armazenar as informações de um livro contendo os seguintes dados: código (inteiro), título (cadeia de caractere de tamanho máximo = 100) e ano de publicação (inteiro)
a. No programa principal, use a estrutura elaborada para preencher as informações de um livro com dados digitados no teclado.
b. Imprima estas informações na tela.
c. Elabore uma função que receba as informações de um livro, um código e um valor de ano. Caso o livro recebido tenha o código igual ao que foi passado como parâmetro, altere o ano do livro para o novo valor. Como essa estrutura deve ser passada como parâmetro? Referência ou valor? E os demais parâmetros?
d. Elabore uma função que receba uma estrutura livro e imprima as informações do livro na tela (um dado por linha).
e. Elabore uma função que receba um livro e um título, caso o título do livro seja igual ao título recebido, imprimir uma mensagem informando que o livro foi encontrado, caso contrário, informar que o livro não existe.
f. Nas funções (d) e (e), como foi a passagem de parâmetro? Foi necessário passar a referência (ou o endereço) da estrutura livro?
g. Modifque a função da letra (e) de maneira que, caso o título do livro seja igual ao título recebido pela função, o ano de publicação do livro deve ser alterado somando 10 ao valor atual. Nesse caso, é necessário passar o endereço do livro?
h. Crie um vetor de, no máximo, 50 livros e preencha as informações dos livros com dados digitados no teclado. A quantidade de livros na lista a ser preenchida deve ser fornecida pelo usuário.
i. Altere a estrutura criada e adicione um campo que deve ser chamado de status que deverá receber uma letra (A (ativo) ou I (inativo)).
j. Elabore uma função que receba as informações dos livros (a lista de livros) e caso o livro tenha sido publicado antes do ano 1950, preencher o status do livro com o valor I, caso contrário, preencher o status do livro com o valor A. */

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

   //Questão A
   printf ("Digite título, código e ano, respectivamente: \n");
   scanf (" %[^\n] %d %d", l.tit, &l.cod, &l.ano);

   //Questão B
   imprimeLivro (l);

   //Questão C
   int cd, an;
   printf ("\nDigite codigo e ano para comparação, respectivamente: \n");
   scanf (" %d %d",&cd, &an);
   alteraAno (&l, cd, an);

   //Questão D
   imprimeLivro2 (&l, cd, an);

   //Questão E
   char titulo[51];
   printf ("\nDigite um titulo para comparação: ");
   scanf (" %[^\n]",titulo);
   verificaLivro (l, titulo);

   //Questão G
   verificaLivro2 (&l, titulo);
   printf ("\nO novo valor do ano é: %d\n",l.ano);

   //Questão H I J
   tlivro lista[50];
   int i, n;

    printf ("\nDigite a quantidade n da lista de livros: ");
    scanf ("%d",&n);
    if (n>0 && n<=50){
        for (i=0; i<n; i++){
            printf ("\nDigite titulo, código e ano respectivamente: \n");
            scanf (" %[^\n] %d %d", lista[i].tit, &lista[i].cod, &lista[i].ano);
        }
        alteraStatus (lista, n);
    }

    return 0;
}

void imprimeLivro (tlivro l)
{
    printf ("\nOs dados são: \n %d\n %d\n %s\n", l.cod, l.ano, l.tit);
}

void alteraAno (tlivro *pl, int cd, int an)
{
    if (pl->cod==cd)
        pl->ano = an;
}

void imprimeLivro2 (tlivro *pl, int cd, int an)
{
    printf ("\nAs novas informações do livro são: \n%s \n%d \n%d\n",pl->tit, pl->cod, pl->ano);
}

void verificaLivro (tlivro l, char titulo[])
{
    if (strcmp(l.tit,titulo)==0)
        printf ("Livro encontrado!\n");
    else
        printf ("Livro não existe!\n");
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
