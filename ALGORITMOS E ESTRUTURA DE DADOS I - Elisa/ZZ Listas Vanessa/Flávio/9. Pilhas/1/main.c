#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    pilha *p, *n, *q;    
    
    p = criapilha();
    n = criapilha();
    
    preenchepilha(p);
    preenchepilha(n);
    
    q = criapilha();
    juntapilha(p,n,q);
    imprimepilha(q);

    return 0;
}

