#include<stdio.h>
//#include<string.h>

/* Faça o programa ler uma pavra e imprimi-la de tras para frente */

int main()
{
    char palavra[10];
    int cont=0, i;

    printf("Digite uma palavra: "); scanf(" %[^\n]",palavra);

    while (palavra[cont] != '\0')
        cont++;

    for(i=cont-1; i>=0; i--)
        printf("%c",palavra[i]);
        
    //for(i=strlen(palavra)-1; i>=0; i--)
        //printf("%c",palavra[i]);

    return 0;
}
