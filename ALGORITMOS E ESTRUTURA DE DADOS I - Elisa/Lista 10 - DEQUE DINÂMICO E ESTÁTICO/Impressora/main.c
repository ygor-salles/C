#include <stdio.h>
#include <stdlib.h>
#include "aplicacao.h"

int main() {
    deque *d = cria_deque();
    
    menu(d);
    
    return 0;

}