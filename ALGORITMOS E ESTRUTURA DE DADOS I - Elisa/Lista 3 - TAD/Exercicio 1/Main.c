#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include "tad.h"

/* Declara��o das vari�veis e chama a fun��o */

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    Pessoa *dados;

    dados = aloca();

    preenche(dados);

    imprime(dados);

    return 0;
}
