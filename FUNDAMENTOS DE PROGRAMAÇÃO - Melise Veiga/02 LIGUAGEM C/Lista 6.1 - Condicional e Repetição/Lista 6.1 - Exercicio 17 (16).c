#include<stdio.h>

/* Uma ag�ncia de casamento possui um cadastro contendo os seguintes dados de
pessoas inscritas: c�digo, sexo, cor de olhos (A(azul), V(verde), C(castanho) e
P(preto)), altura, cor de cabelo (L(louro), R(ruivo), P(preto), C(castanho) e
B(branco)) e ano de nascimento. Um americano contratou a ag�ncia e disse que
gostaria de conhecer uma mo�a de at� 25 anos com 1.60 de altura, loura ou ruiva de
olhos azuis. Uma alem� pretende jantar esta noite com algu�m de mais de 50 anos,
com altura entre 1.75 e 1.80 e olhos pretos. Escreva um programa que leia os dados
de n candidatos e imprima o c�digo daqueles que atendem as condi��es do
americano ou da alem�. A leitura dos dados deve ser encerrada quando for digitado
o ano de nascimento negativo. */

int main ()
{
    int cod=0, nascimento, idade, auxEua, auxGer;
    char sexo, olho, cabelo;
    float altura;

    printf ("Digite o ano de seu nascimento: ");
    scanf ("%d",&nascimento);

    if (nascimento<0) {
    }
    else {
        while (nascimento>=0) {
            printf ("Digite o codigo: ");
            scanf ("%d",&cod);
            printf ("Digite o sexo (m ou f): ");
            scanf (" %c",&sexo);
            printf ("Digite a altura: ");
            scanf ("%f",&altura);
            printf ("Digite a cor do olho (a(azul), v(verde), c(castanho) e p(preto)): ");
            scanf (" %c",&olho);
            printf ("Digite a cor do cabelo (l(louro), r(ruivo), p(preto), c(castanho) e b(branco)): ");
            scanf (" %c",&cabelo);

            idade=2018-nascimento;

            if ((sexo=='f') && (idade<=25) && (altura = 1.6) && (olho=='a') && (cabelo=='l')){
                printf ("\nAtende as condicoes do americano\n");
                auxEua = cod;
            }
            if ((idade>50) && (altura>=1.75) && (altura<=1.80) && (olho=='p')){
                printf ("\nAtende as condicoes da alema\n");
                auxGer = cod;
            }
            printf ("\nDigite o ano de seu nascimento: ");
            scanf ("%d",&nascimento);
            cod = 0;
        }
        printf ("\nOs codigos que atendem a condicao do americano sao: %d\n",auxEua);
        printf ("\nOs codigos que atendem a condicao da alema sao: %d\n",auxGer);
    }
    return 0;
}
