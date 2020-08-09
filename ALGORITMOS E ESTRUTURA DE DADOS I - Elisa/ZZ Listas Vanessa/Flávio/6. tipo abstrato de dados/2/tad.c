#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

struct produto {
    int codigo;
    int quantidade;
    float preco;
};

prod *cria(int n) {
    prod *cadastro;
    cadastro = (prod *) malloc(n*sizeof(prod));
    if(!cadastro) {
        printf("Erro ao alocar\n");
        exit (1);
    }
    return cadastro;
}

void preenche(int n, prod *cadastro) {
    int i;
    for(i=0; i<n; i++) {
        printf("Digite o código do produto: ");
        scanf("%d", &cadastro[i].codigo);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &cadastro[i].quantidade);
        printf("Digite o preço do produto: ");
        scanf("%f", &cadastro[i].preco);
        printf("\n");
    }
    for(i=0; i<n; i++) {
        printf("Código: %d\n", cadastro[i].codigo);
        printf("Quantidade: %d\n", cadastro[i].quantidade);
        printf("Preço: R$ %.2f\n", cadastro[i].preco);
        printf("\n");
    }
    return ;
}

int maiorpreco(int n, prod *cadastro) {
    int i,cod; 
    float mpreco=0;
    for (i=0; i<n; i++) {
        if(cadastro[i].preco > mpreco) {
            cod = cadastro[i].codigo;
            mpreco = cadastro[i].preco;
        }
    }
    return cod;
}

void aumento (int n, int x, prod *cadastro) {
    int i;
    for (i=0; i<n; i++) {
        cadastro[i].preco += cadastro[i].preco*x/100;
    }
    printf("\n                NOVO SALÁRIO\n\n");    
    for (i=0; i<n; i++) {
        printf("Produto %d: R$ %.2f\n", i+1, cadastro[i].preco);
    }    
 return ;   
}

int estoque (int n, prod *cadastro) {
    int i, mestoque=0, cod;
    for (i=0; i<n; i++) {
       if (cadastro[i].quantidade> mestoque) {
           cod = cadastro[i].codigo;
           mestoque = cadastro[i].quantidade;
       } 
    }
    return cod;
}

