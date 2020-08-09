#include<stdio.h>

/* O departamento de marketing de uma editora está com o problema de calcular o
ponto de equilíbrio para qualquer livro que se propõe publicar. O ponto de equilíbrio
representa o valor do preço de venda que cobre os custos de produção. Já os custos
de produção consistem em um custo fixo mais um custo de cópia que é igual ao
número estimado de cópias multiplicado pelo número de páginas. Logo:
custo de produção = custo fixo + (num estimado de cópias x num de páginas)
Leia uma lista contendo, para cada livro, o identificador do livro (valor inteiro), o
custo fixo, o número estimado de cópias e o número de páginas e imprima:
• o custo de produção de cada livro,
• o código identificador e o custo do livro com o maior custo de produção.
Considere que o custo de produção será sempre diferente. Além disso, o programa
deve ser encerrado quando for digitado um identificador negativo. */

int main ()
{
    int cod, copia, pag, maiorCod;
    float custoPro, custoFix, maior;

    printf ("Digite o codigo identificador: ");
    scanf ("%d",&cod);

    if (cod<0){
        return 0;
    }
    else {
        while (cod>0){
            printf ("Digite o custo fixo: ");
            scanf ("%f",&custoFix);
            printf ("Digite o número estimado de copias: ");
            scanf ("%d",&copia);
            printf ("Digite o numero de paginas: ");
            scanf ("%d",&pag);

            custoPro=custoFix+(copia*pag);
            printf ("\nO custo de producao eh de: R$%.2f\n\n",custoPro);
            if (custoPro > maior) {
                maior = custoPro;
                maiorCod = cod;
            }
            printf ("Digite o codigo identificador: ");
            scanf ("%d",&cod);
        }
        printf ("\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf ("\nO maior custo eh: %.2f do codigo %d\n", maior, maiorCod);
        printf ("\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    }
    return 0;
}
