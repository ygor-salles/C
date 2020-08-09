#include<stdio.h>

/* Elabore uma função que receba um valor numérico (podendo ter casas
decimais) e um valor inteiro. O segundo valor (inteiro) corresponde à porcentagem
de aumento do primeiro valor (real). A função deve somar o valor correspondente à
taxa (segundo valor) no primeiro valor. Por exemplo, caso a função receba 100 e 20,
o primeiro valor deve ser alterado para 120 (100 + 20%). Utilize a função no
programa principal para calcular o aumento de uma lista de produtos (um de cada
vez). O valor original do produto e a taxa de aumento deve ser fornecido pelo usuário
(um de cada vez). */

float retorna (float x, int y)
{
    float porcentagem, resultado;
    porcentagem = (float)y/100;
    resultado = x+(x*porcentagem);
    return (resultado);
}

int main ()
{
    float x, funcao;
    int y;
    char op;

    do{
        printf ("\nDigite o valor original do produto: ");
        scanf ("%f",&x);
        printf ("Digite o percentual de aumento: ");
        scanf ("%d",&y);

        funcao = retorna (x, y);
        printf ("O novo valor apos o percentual eh: R$ %.2f",funcao);
        printf ("\nDeseja continuar?(S ou N): ");
        scanf (" %c",&op);

    }while ((op == 's') || (op == 'S'));

    printf ("\nPrograma encerrado!\n");
    return 0;
}
