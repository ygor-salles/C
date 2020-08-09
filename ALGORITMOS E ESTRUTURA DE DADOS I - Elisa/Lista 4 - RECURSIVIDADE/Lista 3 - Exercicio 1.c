#include<stdio.h>
#include<stdlib.h>

/* 1. A seguinte função calcula o maior divisor comum dos inteiros positivos m e n. Escreva uma
função recursiva equivalente.
1. int Euclides(int m, int n){
2. int r;
3. do{
4. r = m % n;
5. m = n;
6. n = r;
7. while(r != 0);
8. return m;} */

int euclides (int m, int n)
{
    int r;
    r = m%n;
    m = n;
    n = r;
    if (r==0)
        return m;

    euclides(m, n);
}

int main ()
{
    int m, n, r;
    printf ("Digite valor de M e N respectivamente: \n");
    scanf (" %d %d",&m, &n);

    r = euclides(m, n);
    printf ("\nO MDC de %d e %d eh: %d\n\n",m, n, r);

    system("pause");
    return 0;
}
