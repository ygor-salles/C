#include<stdio.h>
#include<stdlib.h>

/* Elabore uma função que receba um valor numérico (podendo ter casas
decimais) e um valor inteiro. O segundo valor (inteiro) corresponde à porcentagem
de aumento do primeiro valor (real). A função deve somar o valor correspondente à
taxa (segundo valor) no primeiro valor. Por exemplo, caso a função receba 100 e 20,
o primeiro valor deve ser alterado para 120 (100 + 20%). Utilize a função no
programa principal para calcular o aumento de uma lista de produtos (um de cada
vez). O valor original do produto e a taxa de aumento deve ser fornecido pelo usuário
(um de cada vez). */

void retorna (float a, int b, float *resultado, float *soma)
{
    float porcentagem;
    porcentagem = (float)b/100;
    *resultado = a+(a*porcentagem);
    *soma = *soma+*resultado;
}

int main ()
{
    float a, resultado, soma=0;
    int b;
    char op;

    do{
        printf ("\nDigite o valor original do produto: ");
        scanf ("%f",&a);
        printf ("Digite o percentual de aumento: ");
        scanf ("%d",&b);

        retorna (a, b, &resultado, &soma);
        printf ("O novo valor apos o percentual eh: R$ %.2f",resultado);
        printf ("\nDeseja continuar?(S ou N): ");
        scanf (" %c",&op);

    }while ((op == 's') || (op == 'S'));

    printf ("\n\nA soma total eh: %.2f\n",soma);
    printf ("\nPrograma encerrado!\n\n");
    return 0;
}
