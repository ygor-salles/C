#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    //setlocale(LC_ALL, "portuguese");
    
    //declaração das variaveis
    int n;
    prod *cadastro;
    int mpreco,mestoque;
    float x;
    
    //numero de produtos
    printf("Digite o número de produtos para cadastrar: ");
    scanf("%d", &n);
    cadastro = cria(n);
    preenche(n,cadastro);
    mpreco = maiorpreco(n,cadastro);
    
    printf("\nProduto com maior preço: %d\n\n", mpreco);
    
    printf("Digite qual a porcentagem de ser o aumento: ");
    scanf("%f", &x);
    
    aumento(n,x,cadastro);
    
    mestoque = estoque(n,cadastro);
    printf("\nProduto com maior estoque: %d\n\n", mestoque);
    
    
    return 0;
}


