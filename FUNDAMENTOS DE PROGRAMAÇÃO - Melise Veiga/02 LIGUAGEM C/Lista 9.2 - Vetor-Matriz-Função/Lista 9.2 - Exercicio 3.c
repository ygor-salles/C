#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 3. Escreva uma fun��o que receba um vetor de n�meros reais de tamanho m�ximo = 20, a
quantidade de elementos preenchidos no vetor e um valor de acr�scimo (tamb�m real) e
modifique os elementos do vetor acrescentando o valor passado. Utilize a fun��o no programa
principal para atualizar a lista de sal�rios de n funcion�rios que dever�o ser digitados pelo
usu�rio (n<=20). */

void funcao (float vet[], float acre, int i, int n)
{
    for (i=0; i<n; i++){
        vet[i] = vet[i] + acre;
    }
    return ;
}

int main ()
{
    int i, n;
    float vet[20], acre;
    setlocale (LC_ALL, "Portuguese");

    printf ("Digite a quantidade N <=20 de sal�rios: ");
    scanf ("%d",&n);
    printf ("Digite o valor de acr�scimo: ");
    scanf ("%f",&acre);

    if (n>20 || n<=0){
        printf ("\nEntrada de dados inv�lida!\n");
    }
    else{
        for (i=0; i<n; i++){
            printf ("Digite sal.: R$");
            scanf ("%f",&vet[i]);
        }

        funcao(vet, acre, i, n);

        printf ("\nOs novos sal�rios ap�s acrescimo s�o: \n");
        for (i=0; i<n; i++){
            printf ("\nR$%.2f",vet[i]);
        }
        printf ("\n");
    }

    return 0;
}
