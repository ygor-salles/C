#include<stdio.h>
#include<string.h>
#include<locale.h>

/* 6. Escreva um programa em C que leia 3 cadeias de caracteres de tamanho máximo 50,
e as imprime na tela em ordem alfabética. Voce pode usar a função strcmp da biblioteca string.h */

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    char str1[51], str2[51], str3[51];

    printf ("Digite uma cadeia de caracter: ");
    scanf (" %[^\n]",str1);
    printf ("Digite uma cadeia de caracter: ");
    scanf (" %[^\n]",str2);
    printf ("Digite uma cadeia de caracter: ");
    scanf (" %[^\n]",str3);

    printf ("\nEm ordem alfabética: \n");
    if (strcmp(str1, str2)>0 && strcmp(str1, str3)>0){
        if (strcmp(str2, str3)>0){
            printf ("\n%s \n%s \n%s",str3, str2, str1);
        }
        else if (strcmp(str3, str2)>0){
            printf ("\n%s \n%s \n%s",str2, str3, str1);
        }
    }
    else if (strcmp(str2, str1)>0 && strcmp(str2, str3)>0){
        if (strcmp(str1, str3)>0){
            printf ("\n%s \n%s \n%s",str3, str1, str2);
        }
        else if (strcmp(str3, str1)>0){
            printf ("\n%s \n%s \n%s",str1, str3, str2);
        }
    }
    else if (strcmp(str3, str2)>0 && strcmp(str3, str1)>0){
        if (strcmp(str2, str1)>0){
            printf ("\n%s \n%s \n%s",str1, str2, str3);
        }
        else if (strcmp(str1, str2)>0){
            printf ("\n%s \n%s \n%s",str2, str1, str3);
        }
    }

    printf ("\n");
    return 0;
}
