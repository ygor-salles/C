#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* EXERCICIO 2: Utilizar BubbleSort para ordenar o nomes dos produtos em ordema alfabética */

typedef struct produto
{
    int cod;
    char descricao[30];
    float preco;
}prod;

void bubbleSortAlfabetica(prod *p, int n)
{
    int i, j;
    prod aux;
    for(i=1;i<n;i++) {
        for(j=(n-1);j>=i;j--) {
            if(strcmp(p[j].descricao,p[j-1].descricao) < 0){
                aux = p[j];
                p[j]=p[j-1];
                p[j-1]=aux;
            }
        }
    }
}

int procuraProduto(prod *p, int n, char busca[])
{
    int i, ncomp=0;
    for(i=0;i<n;i++) {
            ncomp++;
            if(strcmp(p[i].descricao,busca) == 0)
                return ncomp;
        }
    return ncomp;
}

int main()
{
    int n=5, i, ncomp=0;
    prod *p;
    char busca[30];
    p = (prod*)malloc(n*sizeof(prod));
    for(i=0; i<n; i++) {
        printf("Produto %d: ", i+1);
        scanf(" %[^\n]", p[i].descricao);
    }


    bubbleSortAlfabetica(p,n);

    for(i=0; i<n; i++) {
        printf("Produto: %s\n", p[i].descricao);
    }

    printf("\nDigite o produto a ser procurado: ");
    scanf(" %[^\n]", busca);
    ncomp = procuraProduto(p,n,busca);

    if(ncomp==0)
        printf("\nProduto nao encontrado\n\n");
    else
        printf("Número de comparacoes: %d\n", ncomp);

    return 0;
}
