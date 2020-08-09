#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    pilha *p, *n;
    
    p = criapilha();
    n = criapilha();
    
    preenche(p,n);
    imprime(p,n);
    


    return 0;
}

