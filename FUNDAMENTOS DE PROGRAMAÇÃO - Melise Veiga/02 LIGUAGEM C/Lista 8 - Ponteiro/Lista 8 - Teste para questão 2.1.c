#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int i=6, j=3, *p, *q;
    p = &i;
    q = &j;
    printf ("\n%8d %d\n",*p, *q);
    return 0;
}
