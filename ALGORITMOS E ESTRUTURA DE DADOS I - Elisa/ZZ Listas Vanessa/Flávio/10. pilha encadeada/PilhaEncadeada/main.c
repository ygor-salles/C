#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilhaenc.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    pilha *p;
    
    p = criaPilha();
    push(p,1);
    push(p,2);
    printf("%d\n", pop(p));
    printf("%d\n", pop(p));

    return 0;
}

