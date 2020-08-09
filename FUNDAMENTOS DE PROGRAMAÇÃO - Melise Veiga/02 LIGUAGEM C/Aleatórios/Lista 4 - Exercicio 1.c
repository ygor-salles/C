#include <stdio.h>

/*Elabore um algoritmo que receba dois valores e retorne o maior deles.*/

int main ()
{
    int a, b, maior, menor;
    printf ("Digite dois valores inteiros: \n");
    scanf ("%d %d",&a,&b);

    if (a>b){
        maior = a;
        menor = b;
    }else{
        maior = b;
        menor = a;
    }

    printf ("\n O valor maior eh: %d\n\n",maior);
    printf (" O valor menor eh: %d\n\n",menor);
    return 0;

}
