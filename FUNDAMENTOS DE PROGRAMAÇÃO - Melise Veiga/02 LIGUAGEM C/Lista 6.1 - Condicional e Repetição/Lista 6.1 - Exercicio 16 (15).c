#include<stdio.h>

/* O departamento de marketing de uma editora est� com o problema de calcular o
ponto de equil�brio para qualquer livro que se prop�e publicar. O ponto de equil�brio
representa o valor do pre�o de venda que cobre os custos de produ��o. J� os custos
de produ��o consistem em um custo fixo mais um custo de c�pia que � igual ao
n�mero estimado de c�pias multiplicado pelo n�mero de p�ginas. Logo:
custo de produ��o = custo fixo + (num estimado de c�pias x num de p�ginas)
Leia uma lista contendo, para cada livro, o identificador do livro (valor inteiro), o
custo fixo, o n�mero estimado de c�pias e o n�mero de p�ginas e imprima:
� o custo de produ��o de cada livro,
� o c�digo identificador e o custo do livro com o maior custo de produ��o.
Considere que o custo de produ��o ser� sempre diferente. Al�m disso, o programa
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
            printf ("Digite o n�mero estimado de copias: ");
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
