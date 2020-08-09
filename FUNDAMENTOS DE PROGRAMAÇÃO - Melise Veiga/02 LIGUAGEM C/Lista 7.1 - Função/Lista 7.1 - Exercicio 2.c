#include<stdio.h>

float retorna (int a, int b, char c)
{
    if (c=='+') {
        return (a+b);
    }
    if (c=='-') {
        return (a-b);
    }
    if (c=='*') {
        return (a*b);
    }
    if (c=='/') {
        return (a/(float)b);
    }
    else{
        return 0;
    }
}

int main ()
{
    int a, b;
    char c;
    float funcao;
    printf ("Digite o primeiro numero: ");
    scanf ("%d",&a);
    printf ("Digite o segundo numero: ");
    scanf ("%d",&b);
    printf ("Digite o carcter de operaçao: ");
    scanf (" %c",&c);

    if ((b==0) && (c=='/')){
        printf ("\nError, nao existe divisao por 0!\n");
    }
    else {
        funcao = retorna (a, b, c);
        printf ("\n %d %c %d = %.2f\n",a, c, b, funcao);
    }
    return 0;
}
