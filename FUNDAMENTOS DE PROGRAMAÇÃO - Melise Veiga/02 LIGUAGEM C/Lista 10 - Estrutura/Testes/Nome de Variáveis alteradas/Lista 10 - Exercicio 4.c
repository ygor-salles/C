#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 4. Crie uma estrutura para armazenar dados de um produto (c�digo � inteiro/pre�o-float). Crie um programa para receber dados de 100 produtos. Armazene estas informa��es em um vetor. Depois de preenchido o vetor, crie fun��es para os seguintes casos:
a. Verificar se o produto de c�digo X (X>0 e deve ser fornecido pelo usu�rio) foi armazenado. Caso seja encontrado, retorne o pre�o do produto.
b. Ajustar o pre�o de todos os produtos. O valor do ajuste em porcentagem dever� ser fornecido pelo usu�rio.
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
        printf ("Digite pre�o: R$");
        scanf ("%f",&produtos[i].preco);
        printf ("\n");
    }

    //Fun��o A
    printf ("Digite o c�digo de X: "); scanf ("%d",&x);
    if (x>0) {
        funcao = funcaoA (produtos, x, ret, n);
        printf ("O pre�o � R$%.2f\n",funcao);
    }

    //Fun��o B
    printf ("\nDigite a porcentagem de ajuste: "); scanf ("%d",&porcentagem);
    funcaoB (produtos, porcentagem, n);

    //Fun��o C
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
    printf ("\n  C�digo      Pre�o");
    for (i=0; i<n; i++){
        printf ("\n     %d      R$%.2f",prod[i].cod, prod[i].preco);
    }
    printf ("\n");
    return ;
}
