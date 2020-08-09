#include<stdio.h>
#include<string.h>

/* 4) Escreva uma função recursiva inverteString que tome um vetor de caracteres como
argumento e imprima o vetor de caracteres na ordem inversa. A função deve parar o
processamento e retornar quando for encontrado um caractere nulo de término de
string. */

void inverte_string (int x, char str2[], char str[], int i);

int main ()
{
    char str[11], str2[11];
    int x, i=0;

    strcpy(str,"LinguagemC");
    x = strlen(str);
    printf (" %d\n",x);

    inverte_string (x, str2, str, i);

    return 0;
}

void inverte_string (int x, char str2[], char str[], int i)
{
    if (i==x){
        str2[x] = '\0';
        printf ("\n %s \n",str2);
        return ;
    }
    str2[i] = str[x-i-1];
    inverte_string (x, str2, str, i+1);
}
