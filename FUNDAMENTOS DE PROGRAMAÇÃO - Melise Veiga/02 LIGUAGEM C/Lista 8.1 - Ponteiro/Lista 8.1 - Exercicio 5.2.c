#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Faça um programa que imprima invertidos os nomes dos algarismos de um número
inteiro de três dígitos. Use a sua função no programa principal. Não é necessário validar
a entrada do número. Ex: 234 saída: quatro três dois. */

void algarismo (int x, int *c, int *d, int *u, char centena[], char dezena[], char unidade[])
{
    *c = x/100;
    *d = (x%100)/10;
    *u = (x%100)%10;

    int aux;
    aux = *c;
    *c = *u;
    *u = aux;

    if (*c==0)
        strcpy(centena,"zero");
    if (*d==0)
        strcpy(dezena,"zero");
    if (*u==0)
        strcpy(unidade,"zero");

    if (*c==1)
        strcpy(centena,"um");
    if (*d==1)
        strcpy(dezena,"um");
    if (*u==1)
        strcpy(unidade,"um");

    if (*c==2)
        strcpy(centena,"dois");
    if (*d==2)
        strcpy(dezena,"dois");
    if (*u==2)
        strcpy(unidade,"dois");

    if (*c==3)
        strcpy(centena,"tres");
    if (*d==3)
        strcpy(dezena,"tres");
    if (*u==3)
        strcpy(unidade,"tres");

    if (*c==4)
        strcpy(centena,"quatro");
    if (*d==4)
        strcpy(dezena,"quatro");
    if (*u==4)
        strcpy(unidade,"quatro");

    if (*c==5)
        strcpy(centena,"cinco");
    if (*d==5)
        strcpy(dezena,"cinco");
    if (*u==5)
        strcpy(unidade,"cinco");

    if (*c==6)
        strcpy(centena,"seis");
    if (*d==6)
        strcpy(dezena,"seis");
    if (*u==6)
        strcpy(unidade,"seis");

    if (*c==7)
        strcpy(centena,"sete");
    if (*d==7)
        strcpy(dezena,"sete");
    if (*u==7)
        strcpy(unidade,"sete");

    if (*c==8)
        strcpy(centena,"oito");
    if (*d==8)
        strcpy(dezena,"oito");
    if (*u==8)
        strcpy(unidade,"oito");

    if (*c==9)
        strcpy(centena,"nove");
    if (*d==9)
        strcpy(dezena,"nove");
    if (*u==9)
        strcpy(unidade,"nove");

    return ;
}

int main ()
{
    int num, c, d, u;
    char centena[11], dezena[11], unidade[11];
    printf ("Digite um valor inteiro: ");
    scanf ("%d",&num);

    algarismo (num, &c, &d, &u, centena, dezena, unidade);
    printf ("\n%s %s %s\n", centena, dezena, unidade);
    return 0;
}
