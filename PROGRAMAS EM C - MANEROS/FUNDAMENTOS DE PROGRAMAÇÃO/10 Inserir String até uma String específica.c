#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 8. Escreva uma função em C que leia uma lista de cadeias de caractere do teclado até
que a cadeia “Acabou” seja digitada e retorne a quantidade de cadeias digitadas. /*/

int acabou (char str[][101])
{
    int i=0, c=0;
    do{
        scanf (" %[^\n]",str[i]);
        c++;
        if (strcmp(str[i],"acabou")==0)
			break;
    } while (str[i] != "acabou");

    return c;
}

int main ()
{
    char str[100][101];
    int retorna;

    printf ("Digite uma lista de cadeia de caracter, ira finalizar quando digitar 'acabou': \n");
    retorna = acabou (str);
    printf ("\nA quantidade de caracteres digitados foram: %d\n",retorna);

    return 0;
}
