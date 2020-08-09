#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*2. Escreva um programa que leia uma cadeia de caractere com espaço e uma letra e imprima a quantidade de vezes que a letra ocorre na cadeia de caractere. */

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    char frase[21], letra;
    int i=0, cont=0;

    printf ("Digite uma letra: ");
    scanf (" %c",&letra);
    printf ("Digite uma frase <= 20 caracter: ");
    scanf (" %[^\n]",frase);

    while (frase[i]!='\0'){
        if (frase[i]==letra)
            cont++;
        i++;
    }

    printf ("\nA quantidade de vezes que a letra (%c) aparece na frase (%s) é, %d vezes\n",letra, frase, cont);
    return 0;
}
