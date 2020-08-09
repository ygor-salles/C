#include<stdio.h>
#include<math.h>

/* Ler dois números, armazenando-os nas variáveis num1 e num2. Verificar se o valor de
num1 é maior que o valor de num2 e, em caso positivo, trocar os conteúdos das variáveis. */

int main ()
{
    float num1, num2, aux;

    printf ("Digite o valor de num1: ");
    scanf ("%f",&num1);
    printf ("Digite o valor de num2: ");
    scanf ("%f",&num2);

    if (num1>num2) {
        aux=num2;
        num2=num1;
        num1=aux;
    }
    printf ("\n O valor de num2 eh: %.2f e num1 eh: %.2f\n\n", num2, num1);
    return 0;
}
