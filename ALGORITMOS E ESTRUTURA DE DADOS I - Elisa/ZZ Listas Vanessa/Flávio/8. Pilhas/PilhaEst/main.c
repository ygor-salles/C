#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilhaest.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    pilha *p;
    int elemento = 4;
    int i, aux[3];
    
    p = criapilha();
    push (p,elemento);
    push (p,elemento);
    push (p,elemento);
    aux[0] = pop(p);
    aux[1] = pop(p);
    aux[2] = pop(p);

    for (i=0; i<tamMax; i++) {
        printf("%d\n", aux[i]);
    }
    return 0;
}

