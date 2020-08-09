#include<stdio.h>

/* Faça um programa que utilize as funções dos exercícios 3 e 4 para:
imprimir o cabeçalho definido na função 3 e imprimir a matrícula e o conceito de um
aluno cuja media e a matrícula serão digitadas pelo usuário. */

void imprima ()
{
    printf ("Curso: Sisitemas de Informacao\n");
    printf ("Disciplina: Fundamentos de Progaramacao\n");
    printf ("Universidade federal de Itajuba - Unifei\n\n");
}

char conceito (int nota)
{
    if ((nota>=0) && (nota<=4.9)){
        return ('D');
    }
    else if ((nota>=5) && (nota<=6.9)){
        return ('C');
    }
    else if ((nota>=7) && (nota<=8.9)){
        return ('B');
    }
    else if ((nota>=9) && (nota<=10)){
        return ('A');
    }
}

int main ()
{
    float nota;
    char funcao;
    imprima ();
    printf ("Digite a nota de sua media: ");
    scanf ("%f",&nota);
    if ((nota<0) || (nota>10)){
        printf ("\nDigite uma nota valida!\n");
        return 0;
    }
    else{
    funcao = conceito (nota);
    printf ("\nO conceito eh: %c\n",funcao);
    }
}