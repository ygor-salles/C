#include<stdio.h>

int main() {
int *q, *p, temp;
int i=2,j=3;
printf ("\nValor de I e J respectivamente: %d %d\n",i, j);
p = &i;
q = &j;
temp = *p;
*p= *q;
*q = temp;
printf ("\nNovo valor de I e J respectivamente: %d %d\n",i, j);
return 0;
}
