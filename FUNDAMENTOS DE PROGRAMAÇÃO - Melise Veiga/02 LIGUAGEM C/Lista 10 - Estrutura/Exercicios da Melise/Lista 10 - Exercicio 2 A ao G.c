#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct livro
{
    int cod, ano;
    char tit[100];
}tlivro;

int main ()
{
   tlivro l;
   printf ("Digite as informa��es do livro: ");
   scanf (" %[^\n] %d %d", l.tit, &l.cod, &l.ano); 
   
   printf ("Os dados do livro s�o: %s %d %d");
}

void alteraAno (tlivro *pl, int cd, int ano)
{
    if (pl->cod==cd)
        pl->ano = ano;
}

void imprimeLivro (tlivro l)
{
    printf ("Os dados s�o: %d\n %d\n %s\n", l.cod, l.ano, l.tit);
}

void verificaLivro (tlivro l, char t[])
{
    if (strcmp(l.tit,t)==0)
        printf ("Livro encontrado!\n");
    else
        printf ("Livro n�o existe!\n");
}

void verificaLivro (tlivro *pl, char t[])
{
    if (strcmp(pl->tit,t)==0)
        pl->ano = pl->ano+10;
}
