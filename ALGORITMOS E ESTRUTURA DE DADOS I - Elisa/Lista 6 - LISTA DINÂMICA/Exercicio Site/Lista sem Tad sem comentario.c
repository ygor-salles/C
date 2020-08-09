#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int codigo;
    float preco;
    int qtde;
    struct No *prox;
};

typedef struct No No;

struct Lista{

    struct No *inicio;
    struct No *fim;
};

typedef struct Lista Lista;

No *aux;
No *anterior;

Lista* cria_lista(){

    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL){
        li->fim = NULL;
        li->inicio = NULL;
    }

    return li;
}

void insere_produto(Lista *li)
{
    No *novo =(No*) malloc(sizeof(No));

    printf("Digite o codigo do produto: ");
    scanf("%d",&novo->codigo);
    printf("Digite o preco do produto: ");
    scanf("%f",&novo->preco);
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d",&novo->qtde);

    if(li->inicio == NULL){
        li->inicio = novo;
        li->fim = novo;
        li->fim->prox = NULL;
    }else{
        li->fim->prox = novo;
        li->fim = novo;
        li->fim->prox = NULL;
    }

    printf("\nProduto inserido com sucesso!");
    getch();
}

void aplica_taxa(Lista *li, float taxa)
{
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        aux = li->inicio;

        do{
            aux->preco = aux->preco - aux->preco * (taxa/100);
            aux = aux->prox;
        }while(aux != NULL);

        printf("Taxa aplicada com sucesso!");
    }
    getch();
}

void imprime_relatorio(Lista *li)
{
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        int quantidade = 0;
        aux = li->inicio;
        printf(">>Relatorio<<\n");

        do{
            printf("\nCodigo do produto %d ", aux->codigo);
            printf("\nPreco do produto %.2f \n\n", aux->preco);
            if(aux->qtde > 500)
                quantidade++;
            aux = aux->prox;
        }while(aux != NULL);

        printf("\nQuantidade de produtos com quantidade estocada superior a 500: %d", quantidade);
    }
    getch();
}

void esvaziar_lista(Lista *li)
{
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        aux = li->inicio;

        do{
            li->inicio = li->inicio->prox;
            free(aux);
            aux = li->inicio;
        }while(aux != NULL);

        printf("\nLista Esvaziada!!");
    }
    getch();
}

int main(){

    int i;
    float taxa;
    Lista *li = cria_lista();

    for(i = 1; i <= 5; i++){
        system("CLS");
        printf("Insira o produto numero %d\n", i);
        insere_produto(li);
    }

    system("CLS");

    printf("Insira a taxa de desconto: ");
    scanf("%f", &taxa);
    aplica_taxa(li, taxa);

    system("CLS");
    imprime_relatorio(li);

    esvaziar_lista(li);

    return 0;
}
