#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*1. Escreva um programa que leia uma cadeia de caractere com espaço e uma letra e imprima a quantidade de vezes que a letra ocorre na cadeia de caractere. */

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    char palavra[21], letra;
    int i=0, cont=0;

    printf ("Digite uma letra: ");
    scanf (" %c",&letra);
    printf ("Digite uma palavra: ");
    scanf (" %s",palavra);

    while (palavra[i]!='\0'){
        if (palavra[i]==letra)
            cont++;
        i++;
    }

    printf ("\nA quantidade de vezes que a letra (%c) aparece na palavra (%s) é, %d vezes\n",letra, palavra, cont);
    return 0;
}
