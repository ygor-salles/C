#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que receba o nome de cinco produtos e seus respectivos pre�os. Calcule e mostre:
� a quantidade de produtos com pre�o inferior a R$ 50,00;
� o nome dos produtos com pre�o entre R$ 50,00 e R$ 100,00;
� a m�dia dos pre�os dos produtos com pre�o superior a R$ 100,00. */

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
