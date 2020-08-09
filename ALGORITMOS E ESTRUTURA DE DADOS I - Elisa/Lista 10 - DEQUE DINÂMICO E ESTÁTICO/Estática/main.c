#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dequeest.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    deque *d = cria_deque();
    menu (d);
    

    return 0;
}

