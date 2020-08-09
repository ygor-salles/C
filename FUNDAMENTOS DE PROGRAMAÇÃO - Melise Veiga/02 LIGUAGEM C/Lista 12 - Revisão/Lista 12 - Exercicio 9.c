#include<stdio.h>
#include<stdlib.h>

/* 9. Modifique a fun��o principal acima de forma que o usu�rio possa digitar a quantidade
de caminhos que quiser. Neste caso, voce dever� perguntar ao usu�rio se deseja ou n�o
continuar. Al�m disso, na nova vers�o do programa, o usu�rio n�o deve fornecer o
tamanho do caminho. O fim do caminho deve ser indicado pelo valor -1. Vale lembrar
que o tamanho m�ximo de um caminho � 15 (cidades). */

float retorna_custo_itinerario(int a[][4], int n, int itinerario[]);

int main ()
{
    int a[4][4], itinerario[15], n, i, j, soma;
    char opcao;

    printf ("\nMATRIZ AUTOMATICA: \n\n");
    for (i=0; i<4; i++){
        for (j=0;j<4; j++){
            a[i][j] = rand() % 100;
            printf (" %d",a[i][j]);
        }
        printf ("\n");
    }

    n=0;
    printf ("\nDigite as cidades do caminho: \n");
    do{
        n++;
        scanf("%d",&itinerario[n]);
        printf ("Deseja continuar?(S/N): "); scanf(" %c",&opcao);
    } while((opcao == 's' || opcao == 'S') && n<15);

    soma = retorna_custo_itinerario(a, n, itinerario);

    printf ("\nO custo total da viajem eh: $%d\n",soma);

    return 0;
}

float retorna_custo_itinerario(int a[][4], int n, int itinerario[])
{
    int i, j, k, soma=0;

    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            for (k=0; k<n; k++)
                if (i==itinerario[k] && j==itinerario[k+1])
                    soma = soma + a[i][j];

    return soma;
}
