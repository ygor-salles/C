#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/* 1. Seja uma estrutura para descrever os carros de uma determinada revendedora, contendo
os seguintes campos:

marca: string de tamanho 15
ano: inteiro
cor: string de tamanho 10
preço: real

a) Escrever a definição da estrutura carro.
b) Criar um novo tipo a partir da estrutura elaborada com o comando typedef.
c) Declarar o vetor vetcarros do tipo criado na letra b, de tamanho 20;
d) Crie uma função para preencher a lista de carros com informações fornecidas pelo
usuário;
e) Crie uma função que receba a lista de carros, um preço e imprima os carros (marca,
cor e ano) que tenham preço igual ou menor ao preço recebido.
f) Crie uma função que receba a lista de carros, uma marca, ano e cor e informe se
existe ou não um carro com essas características. Se existir, retornar o preço do
primeiro carro encontrado. Caso contrário, retorne 0. */

//Questão A e B
typedef struct
{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
} carro;

void preencher_lista(carro vetcarros[]);
void imprime_preco_menor(carro vetcarros[], float preco);
float retorna_carro_caracteristicas(carro vetcarros[], char marca[], int ano, char cor[]);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    //Questão C
    carro vetcarros[5];
    float preco, retorna;
    char marca[15];
    int ano;
    char cor[10];

    //Questão D
    preencher_lista(vetcarros);

    //Questão E
    printf ("\nDigite o preço para comparação: "); scanf("%f",&preco);
    imprime_preco_menor(vetcarros, preco);

    //Questão F
    printf ("\nDigite a marca para comparação: "); scanf(" %[^\n]",marca);
    printf ("Digite o ano para comparação: "); scanf("%d",&ano);
    printf ("Digite a cor para comparação: "); scanf(" %[^\n]",cor);
    retorna = retorna_carro_caracteristicas(vetcarros, marca, ano, cor);
    printf ("\nTeste para verificação se existe ou não o carro na lista: ...");
    if (retorna == 0)
        printf ("\nNão Existe!\n\n");
    else
        printf ("\nO preço do primeiro carro encontrado é %.2f\n\n",retorna);

    system("pause");
    return 0;
}

void preencher_lista(carro vetcarros[])
{
    int i;

    printf ("\n Preencha as informações dos carros: ");
    for (i=0; i<5; i++){
        printf ("\nCarro %d\n",i+1);
        printf ("Digite a marca: "); scanf(" %[^\n]",vetcarros[i].marca);
        printf ("Digite o ano: "); scanf("%d",&vetcarros[i].ano);
        printf ("Digite a cor: "); scanf(" %[^\n]",vetcarros[i].cor);
        printf ("Digite o preço: "); scanf("%f",&vetcarros[i].preco);
        system("CLS");
    }
    return ;
}

void imprime_preco_menor(carro vetcarros[], float preco)
{
    int i;

    printf ("\n Imprime os carros (marca,cor e ano) que tenham preço igual ou menor ao preço recebido (%.2f).",preco);
    for(i=0; i<5; i++){
        if (vetcarros[i].preco<=preco){
            printf ("\nCarro %d",i+1);
            printf ("\nMarca %s",vetcarros[i].marca);
            printf ("\nAno %d",vetcarros[i].ano);
            printf ("\nCor %s",vetcarros[i].cor);
            printf ("\nPreço $%.2f\n",vetcarros[i].preco);
        }
    }
    return ;
}

float retorna_carro_caracteristicas(carro vetcarros[], char marca[], int ano, char cor[])
{
    int i;

    for (i=0; i<5; i++)
        if ( strcmp(vetcarros[i].marca,marca)==0 && vetcarros[i].ano==ano && strcmp(vetcarros[i].cor,cor)==0 )
            return vetcarros[i].preco;

    return 0;
}
