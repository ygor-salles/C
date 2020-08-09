#include<stdio.h>

int main() {
int i=5, *p, j=6, *q;
p = &i;
q = &j;
i = *q + ++(*p);
printf ("\n%8d\n",i);
printf("%d %d %d %d %d \n", *q, *p, **&p, 3**q, **&p+4);
}