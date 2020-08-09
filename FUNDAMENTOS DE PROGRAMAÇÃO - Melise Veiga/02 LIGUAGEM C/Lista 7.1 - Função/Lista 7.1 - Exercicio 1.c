#include<stdio.h>
#include<stdlib.h>

void menu (int ano)
{
    printf ("\nPrograma de treinamento em C\n");
    printf ("Universidade Federal de Itajuba\n");
    printf ("Curso Sistemas de Informacao\n");
    printf ("\n%30d\n",ano);
    return ;
}

int main ()
{
    int ano;
    printf ("Digite o ano: ");
    scanf ("%d",&ano);
    menu (ano);
    return 0;
}
