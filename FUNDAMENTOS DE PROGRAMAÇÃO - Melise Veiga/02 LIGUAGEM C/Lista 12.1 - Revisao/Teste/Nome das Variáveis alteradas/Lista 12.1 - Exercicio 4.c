#include<stdio.h>

/*4. Fazer uma função para retornar a seguinte soma:
    37 * 38        36 * 37     35 * 36             1 * 2
S = ---------- + --------- + ---------- + ..... + ------
        1            2            3                 37       */

void somatorio (float *psoma)
{
    int i, a=37, b=38;
    *psoma = 0;
    for (i=1; i<37; i++){
        *psoma = *psoma + ((a*b)/(float)i);
        a--;
        b--;
    }
    return ;
}

int main ()
{
    float soma;
    somatorio(&soma);
    printf ("\n O valor do somatorio eh: %.2f\n",soma);

    return 0;
}
