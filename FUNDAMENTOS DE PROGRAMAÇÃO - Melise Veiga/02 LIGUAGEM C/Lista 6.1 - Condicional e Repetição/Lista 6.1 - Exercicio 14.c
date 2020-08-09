#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Elabore um algoritmo para calcular e imprimir o valor de S, sendo S = -1/2 + 2/4 - 3/6 + 4/8
-5/10 +, ..., +10/20 */

int main ()
{
    float s=0;
    int i, den=2;

    for (i=1; i<=10; i++){
        if (i%2 == 0){
            s=s+(i/(float)den);
        }
        else{
            s=s+((-i)/(float)den);
        }
        den=den+2;
    }
    printf ("\n A soma eh de: %f\n\n",s);
    return 0;
}
