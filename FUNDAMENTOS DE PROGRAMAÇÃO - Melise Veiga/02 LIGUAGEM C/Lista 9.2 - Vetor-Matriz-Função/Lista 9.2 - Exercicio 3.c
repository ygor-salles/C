#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 3. Escreva uma função que receba um vetor de números reais de tamanho máximo = 20, a
quantidade de elementos preenchidos no vetor e um valor de acréscimo (também real) e
modifique os elementos do vetor acrescentando o valor passado. Utilize a função no programa
principal para atualizar a lista de salários de n funcionários que deverão ser digitados pelo
usuário (n<=20). */

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

    printf ("Digite a quantidade N <=20 de salários: ");
    scanf ("%d",&n);
    printf ("Digite o valor de acréscimo: ");
    scanf ("%f",&acre);

    if (n>20 || n<=0){
        printf ("\nEntrada de dados inválida!\n");
    }
    else{
        for (i=0; i<n; i++){
            printf ("Digite sal.: R$");
            scanf ("%f",&vet[i]);
        }

        funcao(vet, acre, i, n);

        printf ("\nOs novos salários após acrescimo são: \n");
        for (i=0; i<n; i++){
            printf ("\nR$%.2f",vet[i]);
        }
        printf ("\n");
    }

    return 0;
}
