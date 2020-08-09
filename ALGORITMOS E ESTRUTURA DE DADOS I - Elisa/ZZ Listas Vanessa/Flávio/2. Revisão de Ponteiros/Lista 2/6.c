#include <stdio.h>


int main(){
int i = 5, j = 3, *p, *q;
p = &i;
q = &j;
printf("%d %d \n", *p, (*p)++ + *q);
}

