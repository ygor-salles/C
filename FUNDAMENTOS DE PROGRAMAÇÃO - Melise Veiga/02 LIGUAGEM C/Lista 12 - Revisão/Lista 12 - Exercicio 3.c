#include<stdio.h>
#include<stdlib.h>

/* 3. Considere o código abaixo:
a. Supondo que o usuário digite os valores especificados nos comentários das
linhas 4 e 8, quais valores serão impressos nas linhas 6 e 11?
b. Justifique sua resposta */

struct produto
{
    int cod;
    float preco;
};

void alteraPreco(struct produto p,float novoP)
{
    p.preco = novoP;
}

int main()
{
    struct produto p;
    float novoP;

     printf("\nDigite o codigo e o preço do produto: ");
/*4*/scanf("%d %f", &p.cod, &p.preco); // usuário digita cod = 10 e preço = 120.50
     printf("\nAntes da chamada da função: ");
/*6*/printf("\nCodigo: %d, Preco: %f\n", p.cod, p.preco);
     printf("\nDigite o novo preco do produto: ");
/*8*/scanf(" %f", &novoP); // usuário digita novoP = 150
     alteraPreco(p,novoP);
     printf("\nDepois da chamada da função: ");
/*11*/printf("\nCodigo: %d, Preco: %f\n", p.cod, p.preco);

    system("pause");
    return 0;
}

/* Resposta: Serão impressos 10 e 120,5 visto que a função alteraPreco não retorna valor
é void, e não possui ponteiro para que o valor seja alterado */
