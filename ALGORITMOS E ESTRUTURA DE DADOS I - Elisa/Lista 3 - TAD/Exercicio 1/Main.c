#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include "tad.h"

/* Declaração das variáveis e chama a função */

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    Pessoa *dados;

    dados = aloca();

    preenche(dados);

    imprime(dados);

    return 0;
}
