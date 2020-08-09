#include<stdio.h>
#include<stdlib.h>

struct aluno //Struct aluno será o tipo de variável inserida na main
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
    struct aluno a; //a é a variável do tipo struct aluno ja definido
    printf ("Digite os dados do aluno: \n");
    scanf (" %[^\n] %d %d %f", a.nome, &a.mat, &a.cod_turma, &a.rend);
    
    printf ("*****************************************");
    teste(a); //A função teste não muda o a.rend, teria que passar o endereço
    
    printf ("\n\n%s \n%d \n%d \n%.2f\n",a.nome, a.mat, a.cod_turma, a.rend);
    return 0;
}
