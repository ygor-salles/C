#include<stdio.h>

/*Sequencia de Fibonachi - 1151*/

int main ()
{
    int n;
    printf ("Digite o valor de N: ");
    scanf ("%d",&n);

    int fibo[n], i;
    for (i=0; i<n; i++){
        if (i<2){
            fibo[i]=i;
            printf (" %d",fibo[i]);
        }
        else{
            fibo[i] = fibo[i-1] + fibo[i-2];
            printf (" %d",fibo[i]);
        }
    }
    return 0;
}
