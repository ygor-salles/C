#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "tad.h"

/* 1) Faça um programa que cadastre 5 produtos. Para cada produto devem ser cadastrados
código do produto, preço e quantidade estocada. Os dados devem ser armazenados em
uma lista simplesmente encadeada e não ordenada. Posteriormente, receber do usuário
a taxa de desconto (ex.: digitar 10 para taxa de desconto de 10%). Aplicar a taxa digitada
ao preço de todos os produtos cadastrados e finalmente mostrar um relatório com o
código e o novo preço. O final desse relatório deve apresentar também a quantidade de
produtos com quantidade estocada superior a 500. */

int main ()
{
    int i;
    float taxa;

    setlocale(LC_ALL, "Portuguese");
    Lista *li = cria_lista();

    for (i=1; i<=5; i++){
        system("CLS");
        printf ("Insira o produto de número [%d]:\n",i);
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
