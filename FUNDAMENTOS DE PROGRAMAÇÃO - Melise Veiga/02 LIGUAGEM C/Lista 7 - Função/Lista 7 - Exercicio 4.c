#include<stdio.h>

/* Faça uma função que recebe a média final de um aluno e retorne o seu
conceito, conforme a tabela abaixo. Não é necessário implementar a função
principal.
NOTA                conceito
de 0,0 a 4,9            D
de 5,0 a 6,9            C
de 7,0 a 8,9            B
de 9,0 a 10,0           A  */

float retorna (float nota)
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
    printf ("Digite a nota de sua media: ");
    scanf ("%f",&nota);
    if ((nota<0) || (nota>10)){
        printf ("\nDigite uma nota valida!\n");
        return 0;
    }
    else{
    funcao = retorna (nota);
    printf ("\nO conceito eh: %c\n",funcao);
    }
}
