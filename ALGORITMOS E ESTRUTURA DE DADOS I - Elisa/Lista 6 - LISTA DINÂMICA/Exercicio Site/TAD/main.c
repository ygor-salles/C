#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "tad.h"

/* 1) Fa�a um programa que cadastre 5 produtos. Para cada produto devem ser cadastrados
c�digo do produto, pre�o e quantidade estocada. Os dados devem ser armazenados em
uma lista simplesmente encadeada e n�o ordenada. Posteriormente, receber do usu�rio
a taxa de desconto (ex.: digitar 10 para taxa de desconto de 10%). Aplicar a taxa digitada
ao pre�o de todos os produtos cadastrados e finalmente mostrar um relat�rio com o
c�digo e o novo pre�o. O final desse relat�rio deve apresentar tamb�m a quantidade de
produtos com quantidade estocada superior a 500. */

int main ()
{
    int i;
    float taxa;

    setlocale(LC_ALL, "Portuguese");
    Lista *li = cria_lista();

    for (i=1; i<=5; i++){
        system("CLS");
        printf ("Insira o produto de n�mero [%d]:\n",i);
        insere_produto(li);
    }

    system("CLS");
    printf ("Insira a taxa de deconto: ");
    scanf ("%f",&taxa);
    aplica_taxa(li, taxa);
    system("CLS");

    imprime_relatorio(li);

    esvaziar_lixeira(li);

    return 0;
}
