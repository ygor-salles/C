#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*3. Elabore uma função que receba n nomes do usuário (n<=50) e armazene esses nomes em uma matriz passada como parâmetro.
Na matriz de nomes, cada linha deve corresponder a um nome digitado. O tamanho máximo de um nome é 100 (caracteres). */

void funcao (int n, char matriz[][101]);

int main ()
{
    char m[50][101];
    int i, n;

    printf ("Digite o valor de N<=50: ");
    scanf ("%d",&n);
    if (n<=0 || n>50)
        return 0;

    for (i=0; i<n; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",m[i]);
    }

    funcao (n, m);
    return 0;
}

void funcao (int n, char matriz[][101])
{
    int i;
    printf ("\n");
    for (i=0; i<n; i++)
        printf (" %s",matriz[i]);
    printf ("\n");
    return ;
}
