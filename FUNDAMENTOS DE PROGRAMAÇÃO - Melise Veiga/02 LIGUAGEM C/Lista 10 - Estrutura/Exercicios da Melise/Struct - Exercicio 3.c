#include<stdio.h>
#include<stdlib.h>

struct aluno //Struct aluno ser� o tipo de vari�vel inserida na main
{
    char nome[100];
    int mat, cod_turma;
    float rend;
};

void teste (struct aluno a)
{
    a.rend = a.rend*10
}

int main ()
{
    struct aluno a; //a � a vari�vel do tipo struct aluno ja definido
    printf ("Digite os dados do aluno: \n");
    scanf (" %[^\n] %d %d %f", a.nome, &a.mat, &a.cod_turma, &a.rend);
    
    printf ("*****************************************");
    teste(a); //A fun��o teste n�o muda o a.rend, teria que passar o endere�o
    
    printf ("\n\n%s \n%d \n%d \n%.2f\n",a.nome, a.mat, a.cod_turma, a.rend);
    return 0;
}
