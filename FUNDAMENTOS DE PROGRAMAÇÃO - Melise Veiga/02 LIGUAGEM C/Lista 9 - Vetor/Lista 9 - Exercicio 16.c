#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que receba o nome de cinco produtos e seus respectivos preços. Calcule e mostre:
º a quantidade de produtos com preço inferior a R$ 50,00;
º o nome dos produtos com preço entre R$ 50,00 e R$ 100,00;
º a média dos preços dos produtos com preço superior a R$ 100,00. */

int main ()
{
    char prod[5], prod_res[5];
    float preco[5], soma=0;
    int i, c1=0, k=0, m=0;

    for (i=0; i<5; i++){
        printf ("Digite o nome do produto: ");
        scanf (" %c",&prod[i]);
        printf ("Digite o preco do produto: ");
        scanf ("%f",&preco[i]);
        if (preco[i]<50){
            c1++;
        }
        else if (preco[i]>=50 && preco[i]<=100){
            prod_res[k] = prod[i];
            k++;
        }
        else if (preco[i]>100){
            soma=soma+preco[i];
            m++;
        }
        printf ("\n");
    }

    printf ("\nHa %d produto(s) com preco inferior a R$50,00\n",c1);

    printf ("\nNome dos produtos com preco entre R$50,00 e R$100,00: ");
    for (i=0; i<k; i++){
        printf (" %c",prod_res[i]);
    }

    printf ("\n\nA media dos precos dos produtos com preco superior a R$100,00 eh: R$%.2f\n",soma/m);

    return 0;
}
