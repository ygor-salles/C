#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/* 15. Considere uma estrutura para armazenar os produtos do estoque de um supermercado.
Para cada produto, tem-se os seguintes campos:
nome: string de tamanho 15
setor: caracter
quantidade: inteiro
preço: real //preço por unidade do produto
Crie funções para:
a) Preencher a lista de estoque considerando que há, no máximo, 100 produtos em
estoque.
b) Imprimir os nomes dos produtos de um determinado setor.
c) Retornar a quantidade de capital investido no estoque
d) Imprimir a lista de estoque.
e) Alterar a quantidade de um produto em estoque (dado o nome do produto e um novo
valor de quantidade). */

typedef struct
{
    char nome[15], setor;
    int qtd;
    float preco;
} Produto;

void menu()
{
    printf ("\n Digite A para: Preencher a lista de estoque \n");
    printf (" Digite B para: Imprimir os nomes dos produtos de um determinado setor. \n");
    printf (" Digite C para: Retornar a quantidade de capital investido no estoque \n");
    printf (" Digite D para: Imprimir lista de estoque \n");
    printf (" Digite E para: Alterar a quantidade de um produto em estoque (dado o nome do produto e um novo valor de quantidade). \n");
    printf( " Digite S para sair \n");
    printf(" --->: ");

    return ;
}

void preenche_lista(int n, Produto lista[]);
void imprime_produto_setor(int n, Produto lista[], char setor);
float capital_do_estoque(int n, Produto lista[]);
void imprime_estoque(int n, Produto lista[]);
void altera_qtd_produto(int n, Produto lista[], char nome[], int qtd);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Produto lista[100];
    int n, qtd;
    float capital;
    char opcao, setor, nome[15];

    printf ("Digite a quantidade de produtos em estoque <= 100: "); scanf("%d",&n);
    if (n<1 || n>100){
        printf ("\nDigite valores válidos para quantidade de produtos!\n"); return 0;
    }

    printf ("\n**** HABILITE O CAPS LOOK OU FIXA DO TECLADO, PARA QUE O PROGRAMA FUNCIONE CORRETAMENTE ****\n");
    printf ("\n**** UTILIZE A VÍRGULA PARA PREÇOS COM DECIMAIS ****\n");
    menu( );
    scanf(" %c",&opcao);

    while (opcao != 'S') {
        switch(opcao) {
            case 'A':
                preenche_lista(n, lista); break;
            case 'B':
                printf("\nDigite setor a ser buscado: "); scanf(" %c",&setor);
                imprime_produto_setor(n, lista, setor); break;
            case 'C':
                capital = capital_do_estoque(n, lista);
                printf("\nO capital investido no estoque é de $%.2f\n",capital); break;
            case 'D':
                imprime_estoque(n, lista); break;
            case 'E':
                printf("\nDigite o nome do produto: "); scanf(" %[^\n]",nome);
                printf("\nDigite o valor de quantidade: "); scanf("%d",&qtd);
                altera_qtd_produto(n, lista, nome, qtd); break;
        }
        printf("\n\n"); system("pause");
        system("CLS");
        menu( );
        scanf(" %c", &opcao);
    }
    
    printf ("\nFinalizando...\n\n");
    return 0;
}

void preenche_lista(int n, Produto lista[])
{
    int i;
    for(i=0; i<n; i++){
        printf("\nDigite nome: "); scanf(" %[^\n]",lista[i].nome);
        printf("Digite setor: "); scanf(" %c",&lista[i].setor);
        printf("Digite a quantidade: "); scanf("%d",&lista[i].qtd);
        printf("Digite preço: $"); scanf("%f",&lista[i].preco);
    }
    return ;
}

void imprime_produto_setor(int n, Produto lista[], char setor)
{
    int i;
    printf ("\n Nome dos produtos do setor %c: \n",setor);
    for (i=0; i<n; i++)
        if (lista[i].setor == setor)
            printf("\n * %s",lista[i].nome);

    return ;
}

float capital_do_estoque(int n, Produto lista[])
{
    int i;
    float soma=0;
    for(i=0; i<n; i++)
        soma = soma + (lista[i].qtd * lista[i].preco);

    return soma;
}

void imprime_estoque(int n, Produto lista[])
{
    int i;
    for(i=0; i<n; i++){
        printf("\nNome: %s",lista[i].nome);
        printf("\nSetor: %c",lista[i].setor);
        printf("\nQuantidade: %d",lista[i].qtd);
        printf("\nPreço: $%.2f",lista[i].preco);
        printf("\n");
    }
    return ;
}

void altera_qtd_produto(int n, Produto lista[], char nome[], int qtd)
{
    int i;
    for(i=0; i<n; i++)
        if (strcmp(lista[i].nome,nome)==0)
            lista[i].qtd = qtd;

    return ;
}
