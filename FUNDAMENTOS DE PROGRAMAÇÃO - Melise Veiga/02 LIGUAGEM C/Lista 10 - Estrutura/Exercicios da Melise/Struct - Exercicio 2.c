#include<stdio.h>
#include<stdlib.h>

struct aluno //Struct aluno ser� o tipo de vari�vel inserida na main
{
    int mat, cod_turma;
    float rend;
};

int main ()
{
    struct aluno a; //a � a vari�vel do tipo struct aluno ja definido
    printf ("Digite os dados do aluno: \n");
    scanf (" %d %d %f", &a.mat, &a.cod_turma, &a.rend);

    printf ("\nOs dados do aluno sao: %d %d %.2f\n",a.mat, a.cod_turma, a.rend);
    return 0;
}
