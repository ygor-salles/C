#include<stdio.h>
#include<stdlib.h>

/* A Stilo Modas esta com uma promocao durante uma semana, onde varias pecas estao em promocao com precos de 25, 50 e 75 reais.
Ela deseja emitir um relatorio do total de vendas efetuado durante o dia, apenas com as peças em promoção.
º Pecas com codigo de (inclusive) 1 a 5 (inclusive) o preço da peça é de 25
º Pecas com codigo de (inclusive) 6 a 10 (inclusive) o preço da peça é de 50
º Pecas com codigo de (inclusive) 11 a 15 (inclusive) o preço da peça é de 75*/

int main ()
{
    int cod[50], qtd[50], i, n;
    float preco[50], total[50];
    char op;

    do{
    printf ("Digite a quantidade a ser cadastrada: ");
    scanf ("%d",&n);

    for (i=0; i<n; i++){
        printf ("Digite o cod da peca: ");
        scanf ("%d",&cod[i]);
        if (cod[i]<0 || cod[i]>15){
            while (cod[i]<0 || cod[i]>15) {
            printf ("Produto nao esta na promocao!\n\n");
            printf ("Digite o cod da peca: ");
            scanf ("%d",&cod[i]);
            }
        }
        printf ("Digite a quantidade da peca: ");
        scanf ("%d",&qtd[i]);
    }
    printf ("\n");

    printf ("           Relatorio                 \n");
    printf ("\n  Cod  |  Quantidade  |  Preco  |  Total  ");
    for (i=0; i<n; i++){
        if (cod[i]>=0 && cod[i]<=5){
            preco[i] = 25;
        }else if (cod[i]>5 && cod[i]<=10){
            preco[i] = 50;
        }
        else if (cod[i]>10 && cod[i]<=15){
            preco[i] = 75;
        }
        total[i] = preco[i]*qtd[i];
    printf ("\n  %d         %d           R$%.2f    R$%.2f   ",cod[i], qtd[i], preco[i], total[i]);
    }

    printf ("\n\nRelatorio Cadastrado!\n");
    printf ("\nDeseja emitir outro relatorio (S ou N): ");
    scanf (" %c",&op);
    printf ("\n");

    }while (op == 's' || op == 'S');

    return 0;
}
