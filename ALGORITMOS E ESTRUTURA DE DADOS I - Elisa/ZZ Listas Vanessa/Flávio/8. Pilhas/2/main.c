#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    //declaração das variáveis
    pilha *p;
    int elemento;
    
    //chamando a pilha
    p = criapilha();
        
    //perguntando o número
    printf("\nDigite um número decimal: ");
    scanf("%d", &elemento);
    
    //convertendo o número
    divisao(p,elemento);
    
    //imprimindo o número binário
    imprime(p);

    return 0;
}

