#include<stdio.h>

/* Faça uma função que receba 3 valores inteiros por parâmetro e imprima-os de forma ordenada */

void ordena (int a, int b, int c)
{
    int menor, medio, maior;
    if ((a>b) && (a>c)){
        maior = a;
            if (b>c){
                medio = b; menor = c;
                printf ("\nOs valores digitados de modo ordenado sao: %d %d %d\n",menor, medio, maior);
            }
            else{
                medio = c; menor = b;
                printf ("\nOs valores digitados de modo ordenado sao: %d %d %d\n",menor, medio, maior);
            }
    }
    else if ((b>a) && (b>c)){
        maior = b;
            if (a>c){
                medio = a; menor = c;
                printf ("\nOs valores digitados de modo ordenado sao: %d %d %d\n",menor, medio, maior);
            }
            else{
                medio = c; menor = a;
                printf ("\nOs valores digitados de modo ordenado sao: %d %d %d\n",menor, medio, maior);
            }
    }
    else if ((c>a) && (c>b)){
        maior = c;
            if (b>a){
                medio = b; menor = a;
                printf ("\nOs valores digitados de modo ordenado sao: %d %d %d\n",menor, medio, maior);
            }
            else{
                medio = a; menor = b;
                printf ("\nOs valores digitados de modo ordenado sao: %d %d %d\n",menor, medio, maior);
            }
    }
    return ;
}

int main ()
{
    int a, b, c;
    printf ("Digite 3 valores: \n");
    scanf ("%d %d %d",&a, &b, &c);

    ordena (a, b, c);
    return 0;
}
