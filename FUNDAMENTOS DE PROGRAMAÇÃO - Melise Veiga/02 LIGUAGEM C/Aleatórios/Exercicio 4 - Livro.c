#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

/* Faça um programa que receba:
º as notas de 4 alunos em cinco provas diferentes e armazene-as em uma matriz 4 x 5;
º os nomes dos 4 alunos e artmazene-os em um vetor de 4 posições.

Calcule e mostre:
º para cada aluno, o nome, a média aritmética das cinco provas e a situação (Aprovado, reprovado ou exame);
º a média da classe. */

int main ()
{
    float nota[4][5], soma[4], classe=0;
    char nome[4][20];
    int i, j;
    setlocale(LC_ALL, "Portuguese");

    for (i=0; i<4; i++){
        printf ("Digite seu nome: ");
        scanf (" %[^\n]",nome[i]);
        printf ("Digite as 5 notas: \n");
        for (j=0; j<5; j++){
            scanf (" %f",&nota[i][j]);
        }
        printf ("\n");
    }

    printf ("\n       Nome        |   Média   |   Situação    \n");
    for (i=0; i<4; i++){
        soma[i] = 0;
        for (j=0; j<5; j++){
            soma[i] = soma[i] + nota[i][j];
        }
        if ((soma[i]/5)>=6){
            printf ("\n%s                   %.1f        Aprovado",nome[i], soma[i]/5);
        }
        else if ((soma[i]/5)>=3 && (soma[i]/5)<6){
            printf ("\n%s                   %.1f        Exame",nome[i], soma[i]/5);
        }
        else if ((soma[i]/5)>=0 && (soma[i]/5)<3){
            printf ("\n%s                   %.1f        Reprovado",nome[i], soma[i]/5);
        }
        classe = classe + (soma[i]/5);
    }

    printf ("\n\nA média da classe foi de: %.1f\n",classe/4);
    return 0;
}
