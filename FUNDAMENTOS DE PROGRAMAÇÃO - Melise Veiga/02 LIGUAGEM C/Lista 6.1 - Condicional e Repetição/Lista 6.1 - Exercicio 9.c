#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Suponha que no ano N a população dos EUA seja maior que a brasileira. Sabendo-se que os
Estados Unidos possuem um crescimento anual de 2% na sua população e que o Brasil tem
crescimento anual de 4%, determine o ano em que as duas populações serão iguais (em
quantidade).*/

int main ()
{
    float bra=207700000, eua=325700000;
    int ano=2016;

    printf ("\n A populacao brasileira em 2016 eh de 207.7 milhoes");
    printf ("\n\n A populacao americana em 2016 eh de 325.7 milhoes");

    while (eua>bra) {
        bra=bra+(bra*0.04);
        eua=eua+(eua*0.02);
        ano++;
    }
    printf ("\n\n O ano que o Brasil tera a populacao igual a do EUA sera em: %d\n\n",ano);
    return 0;
}
