#include<stdio.h>
#include<stdlib.h>

/*Uma escola deseja saber se existem alunos cursando, simultaneamente, as disciplinas Lógica e Linguagem de
Programação. Coloque os números das mraíctulas dos alunos que cursam Lógicam e um veto,r quinze alunos. */

int main ()
{
    int log[10], prog[5], i;

    printf ("Matricula para Curso de Logica: \n");
    for (i=0; i<10; i++){
        printf ("Digite a matricula: ");
        scanf ("%d",&log[i]);
    }
    printf ("\nMatricula para Curso de Programacao: \n");
    for (i=0; i<5; i++){
        printf ("Digite a matricula: ");
        scanf ("%d",&prog[i]);
    }

    printf ("\n Logica  |  Programacao |\n");
    for (i=0; i<10; i++){
        printf ("%5d    |\n",log[i]);
    }
    for (i=0; i<5; i++){
        printf ("%20d    |\n",prog[i]);
    }
    return 0;
}
