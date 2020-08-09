#include<stdio.h>
#include<string.h>

/* 7. Escreva um programa que leia uma linha do teclado e imprima todas as vogais encontradas no texto e o total de vezes que elas aparecem.
O tamanho máximo da linha é 40 caracteres. */

int main ()
{
    char str[41], vetor[41];
    int c=0, i;

    printf ("Digite uma frase pequena, toda em letras minusculas: \n\n");
    scanf (" %[^\n]",str);

    for (i=0; i<41; i++){
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            vetor[c] = str[i];
            c++;
        }
    }

    printf ("\nAs vogais aparecem %d vezes.\n",c);
    for (i=0; i<c; i++){
        printf (" %c",vetor[i]);
    }

    printf ("\n");
    return 0;
}
