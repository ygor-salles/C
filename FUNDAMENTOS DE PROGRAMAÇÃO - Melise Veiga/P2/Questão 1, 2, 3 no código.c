#include<stdio.h>
#include<stdlib.h>

/* Código da questão 1, 2 e 3 tudo junto da P2 */

int fatorial (int n)
{
    int fat=1, i;
    for (i=n; i>=1; i--){
        fat = fat*i;
    }
    return fat;
}

void somatorio (int n, float *s)
{
    int i, funcao;
    *s=1;
    for (i=1; i<=n; i++){
        funcao = fatorial(i);
        *s = *s+(1/(float)funcao);
    }
    return ;
}

int main ()
{
    int n;
    float soma;
    printf ("Digite o valor de N fatorial: ");
    scanf ("%d",&n);
    somatorio (n, &soma);
    printf ("\nO somatorio eh: %.2f\n",soma);

    return 0;
}
