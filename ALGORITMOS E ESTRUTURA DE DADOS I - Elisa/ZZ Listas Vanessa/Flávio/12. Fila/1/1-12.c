#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "1-12.h"

struct pilhaa {
    int arranjo[tamMax];
    int topo;
};

struct n{
    int dado;
    no *prox;
};

struct fil {
    no *inicio;
    no *fim;
    int qtd;
};
