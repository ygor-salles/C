#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 4. Crie uma estrutura para armazenar dados de um produto (código – inteiro/preço-float). Crie um programa para receber dados de 100 produtos. Armazene estas informações em um vetor. Depois de preenchido o vetor, crie funções para os seguintes casos:
a. Verificar se o produto de código X (X>0 e deve ser fornecido pelo usuário) foi armazenado. Caso seja encontrado, retorne o preço do produto.
b. Ajustar o preço de todos os produtos. O valor do ajuste em porcentagem deverá ser fornecido pelo usuário.
c. Imprimir os dados dos produtos; */

typedef struct produto
{
    int cod;
    float preco;
} tproduto;

float funcaoA (tproduto prod[], int xx, float retorna, int nn);
void funcaoB (tproduto prod[], int porcentagem, int n);
void funcaoC (tproduto prod[], int n);

int  main ()
{
    setlocale(LC_ALL, "Portuguese");
    tproduto produtos[100];
    int n, x, porcentagem, i;
    float ret, funcao;

    printf ("Digite a quantidade de produtos: ");
    scanf ("%d",&n);

    for (i=0; i<n; i++){
        printf ("Digite cod: ");
        scanf ("%d",&produtos[i].cod);
        printf ("Digite preço: R$");
        scanf ("%f",&produtos[i].preco);
        printf ("\n");
    }

    //Função A
    printf ("Digite o código de X: "); scanf ("%d",&x);
    if (x>0) {
        funcao = funcaoA (produtos, x, ret, n);
        printf ("O preço é R$%.2f\n",funcao);
    }

    //Função B
    printf ("\nDigite a porcentagem de ajuste: "); scanf ("%d",&porcentagem);
    funcaoB (produtos, porcentagem, n);

    //Função C
    funcaoC (produtos, n);

    return 0;
}

float funcaoA (tproduto prod[], int xx, float retorna, int nn)
{
    int i, semafaro=0;
    for (i=0; i<nn; i++){
        if (xx == prod[i].cod){
            retorna = prod[i].preco;
            semafaro = 1;
            break;
        }
    }
    if (semafaro == 1)
        return retorna;
    else
        return 0;
}

void funcaoB (tproduto prod[], int porcentagem, int n)
{
    int i;
    for (i=0; i<n; i++){
        prod[i].preco = prod[i].preco+(porcentagem*(prod[i].preco/100));
    }
}

void funcaoC (tproduto prod[], int n)
{
    int i;
    printf ("\n  Código      Preço");
    for (i=0; i<n; i++){
        printf ("\n     %d      R$%.2f",prod[i].cod, prod[i].preco);
    }
    printf ("\n");
    return ;
}
