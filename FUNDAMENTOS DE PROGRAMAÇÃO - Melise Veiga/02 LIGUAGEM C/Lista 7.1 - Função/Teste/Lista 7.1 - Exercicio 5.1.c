#include<stdio.h>
#include<stdlib.h>

/* Faça uma função que receba as 3 notas de um aluno por parâmetro e uma letra. Se a
letra for A, calcula a média aritmética das notas do aluno, se for P, a sua média
ponderada (pesos: 5, 3 e 2). Utilize esta função no programa principal para retornar
a media ponderada de um aluno. */

float ponderada (float p1, float p2, float p3)
{
    return ((p1*5+p2*3+p3*2)/(10));
}

float aritmetica (float p1, float p2, float p3)
{
    return ((p1+p2+p3)/3);
}

int main ()
{
    float n1, n2, n3, funcao;
    char media;
    printf ("Digite as suas 3 notas respectivamente: \n");
    scanf ("%f %f %f",&n1, &n2, &n3);
    printf ("\nDigite a letra correpondente a media desejada (Pondereada(P) ou Aritmetica(A)): ");
    scanf (" %c",&media);

    if ((media == 'P') || (media == 'p')){
        funcao = ponderada (n1, n2, n3);
        printf ("\nA media ponderada eh de: %.2f\n",funcao);
    }
    else if ((media == 'A') || (media == 'a')){
        funcao = aritmetica (n1, n2, n3);
        printf ("\nA media aritmetica eh de: %.2f\n",funcao);
    }
    return 0;
}
