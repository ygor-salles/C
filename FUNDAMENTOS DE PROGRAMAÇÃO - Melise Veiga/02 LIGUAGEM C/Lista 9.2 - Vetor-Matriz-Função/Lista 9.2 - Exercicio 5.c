#include<stdio.h>
#include<stdlib.h>

/* 5. Elabore uma função que receba dois vetores de caracter de tamanho máximo = 10 e retorne um terceiro vetor que deverá conter somente os caracteres que estão nos dois vetores */

void caracter (char a[], char b[], char c[], int i, int n)
{
    int k=0;
    for (i=0; i<n; i++){
        if (a[i] == b[i]){
            c[k] = a[i];
            k++;
        }
    }
    printf ("\n As letras iguais da mesma posicao sao: \n");
    for (i=0; i<k; i++){
        printf (" %c",c[i]);
    }
    return ;
}

int main ()
{
    char a[10], b[10], c[10];
    int i, n;

    printf ("Digite o tamanho da sting <=10: ");
    scanf ("%d",&n);

    if (n>0 && n<=10){
        for (i=0; i<n; i++){
            printf ("Digite uma letra: ");
            scanf (" %c",&a[i]);
        }
        printf ("\n");
        for (i=0; i<n; i++){
            printf ("Digite uma letra: ");
            scanf (" %c",&b[i]);
        }
        caracter (a, b, c, i, n);
    }
    else {
        printf ("\nEntrada de dados invalida!");
    }
    printf ("\n");
    return 0;
}
