#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*3. Elabore uma fun��o que receba n nomes do usu�rio (n<=50) e armazene esses nomes em uma matriz passada como par�metro.
Na matriz de nomes, cada linha deve corresponder a um nome digitado. O tamanho m�ximo de um nome � 100 (caracteres). */

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
