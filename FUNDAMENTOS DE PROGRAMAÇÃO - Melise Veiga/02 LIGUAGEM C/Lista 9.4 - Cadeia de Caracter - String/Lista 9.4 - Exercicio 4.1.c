#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*4. Escreva um programa em C que leia uma lista de N cadeias de caractere de tamanho
máximo igual a 50 e armazene a quantidade de caractere de cada cadeia em um vetor de
inteiros. A posição i do vetor de inteiros deve armazenar o tamanho da i-ésima cadeia
digitada. N deve ser fornecido pelo usuário (valor máximo = 10). Imprima o vetor de
tamanhos.*/

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    char string[51];
    int i, n, tamanho[50];

    printf ("Digite o valor de N(<=10): ");
    scanf ("%d",&n);
    if (n>10 || n<=0){
        printf ("\nDigite um valor >0 e <=10 !\n");
        return 0;
    }

    printf ("\n");
    for (i=0; i<n; i++){
        printf ("Digite uma cadeia de caracter: ");
        scanf (" %[^\n]",string);
        tamanho[i] = strlen(string);
    }
    for (i=0; i<n; i++){
        printf ("\nA quantidade de caracter da string [%d] é: %d\n",i+1, tamanho[i]);
    }

    printf ("\n");
    return 0;
}
