#include <stdio.h>
#include <stdlib.h>
#include "aplicacao.h"

int main() {
    deque *d = cria_deque(); // Cria deque D
    deque *e = cria_deque(); // Cria deque E
    menu(d,e);  
    return 0;
}

