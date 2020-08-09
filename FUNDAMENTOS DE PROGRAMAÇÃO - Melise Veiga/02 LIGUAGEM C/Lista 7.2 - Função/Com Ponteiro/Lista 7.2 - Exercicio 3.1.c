#include<stdio.h>
#include<stdlib.h>

/* Elabore uma fun��o que receba um valor num�rico (podendo ter casas
decimais) e um valor inteiro. O segundo valor (inteiro) corresponde � porcentagem
de aumento do primeiro valor (real). A fun��o deve somar o valor correspondente �
taxa (segundo valor) no primeiro valor. Por exemplo, caso a fun��o receba 100 e 20,
o primeiro valor deve ser alterado para 120 (100 + 20%). Utilize a fun��o no
programa principal para calcular o aumento de uma lista de produtos (um de cada
vez). O valor original do produto e a taxa de aumento deve ser fornecido pelo usu�rio
(um de cada vez). */

float retorna (float a, int b, float result, float *soma)
{
    float porcentagem;
    porcentagem = (float)b/100;
    result = a+(a*porcentagem);
    *soma = *soma+result;

    return (result);
}

int main ()
{
    float x, resultado, funcao, soma=0;
    int y;
    char op;

    do{
        printf ("\nDigite o valor original do produto: ");
        scanf ("%f",&x);
        printf ("Digite o percentual de aumento: ");
        scanf ("%d",&y);

        funcao = retorna (x, y, resultado, &soma);
        printf ("O novo valor apos o percentual eh: R$ %.2f",funcao);
        printf ("\nDeseja continuar?(S ou N): ");
        scanf (" %c",&op);

    }while ((op == 's') || (op == 'S'));

    printf ("\n\nA soma total eh: %.2f\n",soma);
    printf ("\nPrograma encerrado!\n\n");
    return 0;
}
