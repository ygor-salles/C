#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*5. Uma grande empresa tem seus pre�os armazenados na forma de uma matriz contendo 3 colunas. Na primeira, est�o os c�digos dos produtos - inteiro. Na outra est�o os pre�os de cada produto (considere os pre�os valores inteiros), na mesma ordem de aparecimento de COD. Na �ltima, est� a quantidade em estoque do produto, tamb�m na mesma ordem da primeira. A quantidade de produtos deve ser fornecida pelo usu�rio. Escreva fun��es para:
a) Preencher as informa��es da matriz lendo os dados de um arquivo (produtos.dat). Cada linha do arquivo representa um produto. As informa��es de cada produto est�o separadas por um espa�o em branco. Abaixo, um exemplo do arquivo:
1111 45 20
2222 71 15
(O produto 1111 custa 45 moedas e h� 20 produtos no estoque. J� o produto 2222 custa 71 moedas e ainda h� 15 produtos no estoque).
b) Alterar o valor de todos os produtos com mais de 50 unidades em estoque. O valor do desconto a ser considerado deve ser fornecido pelo usu�rio. Atualizar o arquivo. */

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int n, i, j;
    printf ("Digite a quantidade de produtos: ");
    scanf ("%d",&n);
    int cod[n], preco[n], qtd[n];

    FILE *arq;
    arq = fopen("produtos.txt","w+");
    if (arq == NULL){
        printf ("\nArquivo n�o encontrado!\n");
        exit(1);
    }
    else{
        fprintf (arq, "\n Matriz\n");
        for (i=0; i<n; i++){
            printf ("\nDigite c�digo: ");
            scanf ("%d",&cod[i]);
            printf ("Digite pre�o: ");
            scanf ("%d",&preco[i]);
            printf ("Digite quantidade: ");
            scanf ("%d",&qtd[i]);
            fprintf (arq, "|_%d_|_%d_|_%d_|",cod[i], preco[i], qtd[i]);
            fprintf (arq, "\n");
        }
        int desconto;
        printf ("\nDigite o valor de desconto: ");
        scanf ("%d",&desconto);

        fprintf (arq, "\nO novo pre�o ap�s o desconto �: \n");
        for (i=0; i<n; i++){
            if (qtd[i]>50){
                preco[i] = preco[i] - desconto;
            }
            fprintf (arq, "|_%d_|_%d_|_%d_|",cod[i], preco[i], qtd[i]);
            fprintf (arq, "\n");
        }

        rewind(arq);
        printf ("\n");

        printf ("\nO novo pre�o ap�s o desconto �: \n");
        for (i=0; i<n; i++){
            fscanf (arq, " %d %d %d",&cod[i], &preco[i], &qtd[i]);
            printf ("|_%d_|_%d_|_%d_|",cod[i], preco[i], qtd[i]);
            printf ("\n");
        }

        printf ("\n");
        fclose(arq);
    }
    return 0;
}
