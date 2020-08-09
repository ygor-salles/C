#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int busca_linear(int v[], int elem);
void ordena_vetor(int v[]);
int busca_ordenada(int v[], int elem);
int busca_binaria(int v[], int elem);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int v[10], i, elem, posicao, op;

    do{
        printf("\nVETOR CRIADO: \n");
        for (i=0; i<10; i++){
            v[i] = rand() % 100;
            printf (" %d",v[i]);
        }

        printf ("\n\nMENU: DIGITE A OPÇÃO DESEJADA: ");
        printf ("\n1 - Realizar uma busca linear");
        printf ("\n2 - Realizar uma busca ordenada");
        printf ("\n3 - Realizar uma busca binária(ordenada)");
        printf ("\n4 - Sair");
        printf ("\nOpção: "); scanf("%d",&op);

        if (op<=0 || op>=4)
            return 0;

        printf("\n\nDigite o elemento a ser buscado: "); scanf("%d",&elem);
        printf("\n");

        switch (op){
            case 1:
                posicao = busca_linear (v, elem);
                if (posicao == -1)
                    printf("\nPosição não encontrada!\n\n");
                else
                    printf ("\nA posição retornada é: %d\n\n",posicao);
                break;

            case 2:
                ordena_vetor(v);
                posicao = busca_ordenada(v, elem);
                if (posicao == -1)
                    printf("\nPosição não encontrada!\n\n");
                else
                    printf ("\nA posição retornada é: %d\n\n",posicao);
                break;

            case 3:
                ordena_vetor(v);
                posicao = busca_binaria(v, elem);
                if (posicao == -1)
                    printf("\nPosição não encontrada!\n\n");
                else
                    printf ("\nA posição retornada é: %d\n\n",posicao);
                break;
        }

        system("pause"); system("CLS");
    } while (op>0 && op<4);

    return 0;
}

int busca_linear(int v[], int elem)
{
    int posicao, i;
    for(i=0; i<10; i++)
        if (elem == v[i])
            return i;
    return -1;
}

int busca_ordenada(int v[], int elem)
{
    int i;
    for(i=0; i<10; i++){
        if (elem == v[i])
            return i;
        else if (elem < v[i])
            return -1;
    }
    return -1;
}

int busca_binaria(int v[], int elem)
{
    int inicio, meio, fim;
    inicio = 0;
    fim = 10-1;

    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if (elem < v[meio])
            fim = meio-1;
        else
            if (elem > v[meio])
                inicio = meio+1;
            else
                return meio;
    }
    return -1;
}

void ordena_vetor(int v[])
{
    //implemete um algoritmo de ordenação aqui
    int i, j, menor, troca;
    for(i=0; i<10-1; i++){
        menor = i;
        for (j=i+1; j<10; j++)
            if (v[j] < v[menor])
                menor = j;
        if (i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
    //**************
    
    printf("\nVETOR ORDENADO: \n");
    for (i=0; i<10; i++)
        printf (" %d",v[i]);

    printf("\n\n");
    return ;
}
