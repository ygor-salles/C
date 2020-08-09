#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*4. Elabore uma função que receba dois nomes (origem e destino), uma matriz de nomes (máximo 50 nomes) ,
a quantidade de nomes preenchidos na matriz e substitua toda ocorrência do nome origem pelo nome destino.
O tamanho máximo de cada nome é 100. */

void trocanome (char origem[], char destino[], char nome[][101], int n)
{
    int i;
    for (i=0; i<n; i++){
        if (strcmp(nome[i],origem)==0){
            strcpy(nome[i],destino);
        }
    }
    return ;
}

int main ()
{
    char origem[101], destino[101], nome[50][101];
    int n, i;

    printf ("Digite o valor de N: ");
    scanf ("%d",&n);

    for (i=0; i<n; i++){
        printf ("Digite o nome: ");
        scanf (" %[^\n]",nome[i]);
    }
        printf ("Digite o nome origem: ");
        scanf (" %[^\n]",origem);
        printf ("Digite o nome destino: ");
        scanf (" %[^\n]",destino);

    trocanome (origem, destino, nome, n);

    printf ("\n");
    for (i=0; i<n; i++)
        printf (" %s", nome[i]);

    printf ("\n");
    return 0;
}
