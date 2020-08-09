#include<stdio.h>
#include<stdlib.h>

struct aluno //Struct aluno será o tipo de variável inserida na main
{
    char nome[100];
    int mat, cod_turma;
    float rend;
};

void teste (struct aluno *a)
{
    *a.rend = *a.rend*10;
    //a->rend = a->rend*10 pode ser dessa maneira tb para algumas IDE's 
}

int main ()
{
    struct aluno a; //a é a variável do tipo struct aluno ja definido
    printf ("Digite os dados do aluno: \n");
    scanf (" %[^\n] %d %d %f", a.nome, &a.mat, &a.cod_turma, &a.rend);
    
    printf ("*****************************************");
    teste(&a); 
    
    printf ("\n\n%s \n%d \n%d \n%.2f\n",a.nome, a.mat, a.cod_turma, a.rend);
    return 0;
}
