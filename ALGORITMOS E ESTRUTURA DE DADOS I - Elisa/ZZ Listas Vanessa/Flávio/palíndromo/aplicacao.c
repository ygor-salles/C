#include <stdio.h>
#include <stdlib.h>
#include "aplicacao.h"

struct Item {
    char letra;
};

struct No {
    struct No *ant;
    struct No *prox;
    struct Item dados;
};

struct Deque {
    struct No *inicio;
    struct No *final;
    int qtd;
};

deque* cria_deque() {                           //função que irá alocar o deque
    deque *d = (deque*)malloc(sizeof(deque));
    if (!d) {                                   //verifica se o deque alocou corretamente
        printf("Erro ao alocar\n");
        exit(1);
    }
    d->final = NULL;                            //inicializar o início e o final para NULL
    d->inicio = NULL;
    d->qtd = 0;                                 //inicializar a quantidade para 0
    return d;
}

void insere_inicio(deque *d, char i) {           //função que irá inserir um elemento pelo início do deque
    if (!d)                                     //verifica se o deque está criado corretamente
        return ;
    no *novono = (no*)malloc(sizeof(no));       //aloca o nó a ser inserido 
    if (!novono) {                              //verifica se o nó foi criado corretamente
        printf("Erro ao alocar\n");
        exit (1);
    }
    novono->dados.letra = i;                      //insere o elemento no novo nó criado
    novono->prox = d->inicio;                   //aponta o prox para o d-inicio anterior, para manter o encadeamento
    novono->ant = NULL;                         //por inserir no início, seu anterior apontará para NULL
    if (!d->inicio)
        d->final = novono;                      //caso seja o único elemento da lista, o final também será o novo nó
    else 
        d->inicio->ant = novono;                //senão, o anterior do inicio antigo, apontará para o novo nó, a se tornar duplamente encadeado
    d->inicio = novono;                         //ao final, coloca o inicio como o novono
    d->qtd++;                                   //incrementa 1 para a quantidade de nós
    return ;
}

void insere_final(deque *d, char i) {            //função que irá inserir um elemento pelo final do deque
    if (!d)                                     //verifica se o deque está criado corretamente
        return ;
    no *novono = (no*)malloc(sizeof(no));       //aloca o nó a ser inserido 
     if (!novono) {                             //verifica se o nó foi criado corretamente
        printf("Erro ao alocar\n");
        exit (1);
    }
    novono->dados.letra = i;                      //insere o elemento no novo nó criado
    novono->prox = NULL;                        //por ser o elemento final, o seu próximo deve apontar para NULL
    if (!d->final) {
        novono->ant = NULL;                     //por não possuir nenhum elemento, seu anterior também deve apontar para NULL
        d->inicio = novono;                     //caso seja o único elemento da lista, o final também será o novo nó
    }
    else {
        novono->ant = d->final;                 //caso tenha outro elemento, o anterior aponta para o final antigo, para manter o duplo encadeamento
        d->final->prox = novono;                //o final antigo aponta para o novo nó, para manter o encadeamento
    }
    d->final = novono;                          //feito tudo certo, o novo nó se torna o final do deque
    d->qtd++;                                   //incrementa 1 para a quantidade de nós
    return ;
}

void remove_inicio(deque *d) {                  //função que irá remover o 1º elemento
    if (!d || !d->inicio) {                      //verifica se a lista não está vazia
        printf("\nNão foi possível remover\n");
        setbuf(stdin, NULL);
        getchar();
        return;
    }                      
    no *novono = d->inicio;                     //caso não esteja, cria-se um ponteiro auxiliar para guardar o início
    d->inicio = d->inicio->prox;                //o d-inicio irá ser agora o elemento depois dele
    if (!d->inicio)                             //se o d-inicio se tornar nulo, quer dizer que ele era o último elemento
        d->final = NULL;                        //a lista ficou vazia, então o final também apontará para o NULL
    else
        d->inicio->ant = NULL;                  //o anterior do inicio aponta para NULL
    free(novono);                               //libera a memória do antigo inicio com a ajuda do ponteiro auxiliar
    d->qtd--;                                   //decrementa a quantidade
    return ;
}

void remove_final(deque *d) {                   //função que irá remover o último elemento
    if (!d || !d->inicio)   {                   //verifica se a lista não está vazia
        printf("\nNão foi possível remover\n");
        setbuf(stdin, NULL);
        getchar();
        return;
    }                    
    no *novono = d->final;                      //caso não esteja, cria-se um ponteiro auxiliar para guardar o final
    if (novono == d->inicio) {                  //verifica se o deque possui apenas 1 elemento
        d->inicio = NULL;                       //caso tenha, o início e o final vão para NULL
        d->final = NULL;
    }
    else {
        novono->ant->prox = NULL;               //se possuir mais elementos, o final antigo irá para NULL
        d->final = novono->ant;                 //e o final assumirá o valor anterior a ele
    }
    free(novono);                               //libera a memória do antigo inicio com a ajuda do ponteiro auxiliar
    d->qtd--;                                   //decrementa a quantidade
    return ;
}

void imprime_deque (deque *d) {                 //função que imprimirá os elementos do deque
    if (!d->inicio) {                           //verifica se o deque está vazio
        printf("\nO deque está vazio\n\n");
        return ;
    }
    no *aux = d->inicio;                        //cria-se um ponteiro auxiliar para percorrer o deque
    printf("\n\nElementos do deque: \n");
    while (aux->prox != NULL) {                 //enquanto não se chegar ao elemento final, não sairá do loop
        printf("%c\n", aux->dados.letra);         //imprime o elemento daquele nó
        aux = aux->prox;                        //após imprimir, o aux assume o valor do próximo nó                        //remove o elemento após sua impressão
    }
    printf("%c\n", aux->dados.letra);
    return ;
}

char consulta_inicio(deque *d) {                 //função que retorna o 1º elemento do deque
    if(!d || !d->inicio)                        //verifica se o deque está vazio
        return 0;
    return d->inicio->dados.letra;                //caso não esteja, retorna o primeiro elemento
}

char consulta_final(deque *d) {                  //função que retorna o último elemento do deque
    if (!d || !d->final)                        //verifica se o deque está vazio
        return 0;
    return  d->final->dados.letra;                //caso não esteja, retorna o último elemento
}

int vazio(deque *d) {                           //função que verifica se o deque está vazio
    if (!d || !d->inicio)                       //caso esteja, retorna positivo
        return 1;
    return 0;                                   //senão, retorna negativo
}

int tamanho(deque *d) {                         //função que retorna o tamanho do deque
    if (!d)                                     //verifica se o deque existe
        return 0;
    return d->qtd;                              //caso exista, retorna sua quantidade
}

void libera_deque(deque *d) {                   //função que liberará a memória do deque
    if (d != NULL) {                            //se o deque existir
        no *no;                                 //cria o ponteiro auxiliar
        while (d->inicio != NULL) {             //enquanto não chega no último elemento
            no = d->inicio;                     //ponteiro auxiliar recebe o elemento inicial
            d->inicio = d->inicio->prox;        //o inicio recebe o elemento da frente
            free(no);                           //e libera a memória com o ponteiro auxiliar
        }
        d->qtd = 0;                             //zera a quantidade de elementos do deque
        free(d);                                //libera a memória do deque
    }
    return ;
}

void menu(deque *d, deque *e) {                           //função que mostrará o indíce das outras funções
    FILE *arq;
    
    int j,compara=0, x=0; // variaveis
    char pal[20];
    printf("            Checar palíndromo usando TAD DEQUE\n\n");
    
    
    arq = fopen("numeros.txt", "r");
        if(!arq){
        printf("Falha ao abrir arquivo.\n");
        exit(1);
    }
    printf("\nChecando o número encontrado no arquivo.\n\n");
    printf("O número ");
    //ler os números do arquivo 
    while((fscanf(arq,"%c",&pal[j])) != EOF) {
        //insere_inicio(d,pal[j]);
        x++;
        j++;
    } 
    //imprime_deque(d);
    /*for(j=0;j<x+1;j++){
        if (consulta_inicio == consulta_final)
            compara++;
        if(compara == x)
            printf(" é um palíndromo.\n\n\n");
        else 
            printf(" nao é um palíndromo.\n\n\n");   
        //liberar decks e fechar arquivo
        libera_deque(d);
        fclose(arq);
    }*/
    return;
}