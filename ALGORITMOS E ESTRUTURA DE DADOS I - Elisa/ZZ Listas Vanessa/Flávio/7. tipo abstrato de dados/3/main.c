#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    
    //declaração de variáveis
    int n;
    mat1 **m1;
    mat2 **m2;
    
    //alocando as matrizes
    printf("Digite o tamanho das matrizes: ");
    scanf("%d", &n);
    m1 = cria1(n);
    m2 = cria2(n);
    
    //preenchendo as matrizes
    preenche1(n,m1);
    preenche2(n,m2);
    
    //imprimindo as matrizes
    imprime1(n,m1);
    imprime2(n,m2);
    
    //somando as matrizes
    soma(n,m1,m2);

    return 0;
}

