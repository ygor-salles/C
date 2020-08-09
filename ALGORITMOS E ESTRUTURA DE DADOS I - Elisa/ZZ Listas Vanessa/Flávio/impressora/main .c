#include <stdio.h>
#include <stdlib.h>
#include "impressora.h"

int main() {
    deque *d = cria_deque();
    
    menu(d);
    
    return 0;

}