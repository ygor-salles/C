#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

/* 3. Elabore uma fun��o que receba uma cadeia de caractere retorne o tamanho da cadeia.
N�o podem ser usadas fun��es da biblioteca string.h */

int tamanho (char string[])
{
    int i=0;
    while (string[i]!='\0'){
        i++;
    }
    return i;
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    char string[100];
    int retorna;

    printf ("Digite uma cadeia de caracter: ");
    scanf (" %[^\n]", string);

    retorna = tamanho (string);
    printf ("\nO tamanho da string �: %d\n",retorna);

    return 0;
}
