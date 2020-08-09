#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    pilha *p;
    int elemento[4] = {1,2,3,4};
    int aux;
    
    p = criapilha();
    push(p,elemento[0]);
    push(p,elemento[1]);
    push(p,elemento[2]);
    
    listadados(p);


    return 0;
}

