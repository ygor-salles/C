#include<stdio.h>

/* Faça uma função que receba as 3 notas de um aluno por parâmetro e uma letra. Se a letra for A,
calcula a média aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2). 
Utilize esta função no programa principal para retornar a media ponderada de um aluno */

float retorna (float p1, float p2, float p3, char opcao)
{
    float media;
    if ((opcao == 'a') || (opcao == 'A')){
        media = (p1+p2+p3)/3;
        return (media);
    }
    else if ((opcao == 'p') || (opcao == 'P')){
        media = ((p1*5)+(p2*3)+(p3*2))/10;
        return (media);
    }
}

int main ()
{
    float p1, p2, p3, funcao;
    char opcao;
    printf ("Digite a sua nota da P1: ");
    scanf ("%f",&p1);
    printf ("Digite a sua nota da P2: ");
    scanf ("%f",&p2);
    printf ("Digite a sua nota da P3: ");
    scanf ("%f",&p3);
    printf ("Digite a opcao desejada: \nMedia aritmetica(A) ou Media ponderada(P): ");
    scanf (" %c",&opcao);
    funcao = retorna (p1, p2, p3, opcao);
    printf ("\n\nSua media foi: %.2f\n",funcao);
    return 0;
}