#include<stdio.h>
#include<stdlib.h>

/* 3. Considere o c�digo abaixo:
a. Supondo que o usu�rio digite os valores especificados nos coment�rios das
linhas 4 e 8, quais valores ser�o impressos nas linhas 6 e 11?
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

     printf("\nDigite o codigo e o pre�o do produto: ");
/*4*/scanf("%d %f", &p.cod, &p.preco); // usu�rio digita cod = 10 e pre�o = 120.50
     printf("\nAntes da chamada da fun��o: ");
/*6*/printf("\nCodigo: %d, Preco: %f\n", p.cod, p.preco);
     printf("\nDigite o novo preco do produto: ");
/*8*/scanf(" %f", &novoP); // usu�rio digita novoP = 150
     alteraPreco(p,novoP);
     printf("\nDepois da chamada da fun��o: ");
/*11*/printf("\nCodigo: %d, Preco: %f\n", p.cod, p.preco);

    system("pause");
    return 0;
}

/* Resposta: Ser�o impressos 10 e 120,5 visto que a fun��o alteraPreco n�o retorna valor
� void, e n�o possui ponteiro para que o valor seja alterado */
