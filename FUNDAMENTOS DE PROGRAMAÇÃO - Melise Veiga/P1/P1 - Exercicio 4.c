#include<stdio.h>

/* P1 - Exercicio 4 */

int main ()
{
    int i, n, den;
    float s;

    printf ("Digite o valor de N: ");
    scanf ("%d",&n);

    if (n<0){
        printf ("\nEntrada de dados invalida!\n");
    }
    else{
        den = n-1;
        s = 1/(float)n;
        for (i=2; i<=n; i++){
            s = s+(i/(float)den);
            den--;
        }
        printf ("\nA soma s eh: %.2f\n\n",s);
    }
    return 0;
}
