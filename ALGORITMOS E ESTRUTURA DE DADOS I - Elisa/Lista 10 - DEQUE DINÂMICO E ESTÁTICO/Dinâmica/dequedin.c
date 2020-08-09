#include <stdio.h>
#include <stdlib.h>
#include "dequedin.h"

struct Item {
    int num;
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

void insere_inicio(deque *d, int i) {           //função que irá inserir um elemento pelo início do deque
    if (!d)                                     //verifica se o deque está criado corretamente
        return ;
    no *novono = (no*)malloc(sizeof(no));       //aloca o nó a ser inserido 
    if (!novono) {                              //verifica se o nó foi criado corretamente
        printf("Erro ao alocar\n");
        exit (1);
    }
    novono->dados.num = i;                      //insere o elemento no novo nó criado
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

void insere_final(deque *d, int i) {            //função que irá inserir um elemento pelo final do deque
    if (!d)                                     //verifica se o deque está criado corretamente
        return ;
    no *novono = (no*)malloc(sizeof(no));       //aloca o nó a ser inserido 
     if (!novono) {                             //verifica se o nó foi criado corretamente
        printf("Erro ao alocar\n");
        exit (1);
    }
    novono->dados.num = i;                      //insere o elemento no novo nó criado
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
        printf("%d\n", aux->dados.num);         //imprime o elemento daquele nó
        aux = aux->prox;                        //após imprimir, o aux assume o valor do próximo nó   
        remove_inicio(d);                       //remove o elemento após sua impressão
    }
    printf("%d\n", aux->dados.num);
    remove_inicio(d);
    return ;
}

int consulta_inicio(deque *d) {                 //função que retorna o 1º elemento do deque
    if(!d || !d->inicio)                        //verifica se o deque está vazio
        return 0;
    return d->inicio->dados.num;                //caso não esteja, retorna o primeiro elemento
}

int consulta_final(deque *d) {                  //função que retorna o último elemento do deque
    if (!d || !d->final)                        //verifica se o deque está vazio
        return 0;
    return  d->final->dados.num;                //caso não esteja, retorna o último elemento
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

void menu(deque *d) {                           //função que mostrará o indíce das outras funções
    int x,y;
    
    printf("                TAD DEQUE  DINÂMICO         \n\n");
    printf("1 - Inserir pelo início:\n");
    printf("2 - Inserir pelo final:\n");
    printf("3 - Remover pelo início:\n");
    printf("4 - Remover pelo final:\n");
    printf("5 - Imprimir todos os elementos:\n");
    printf("6 - Consultar o primeiro elemento:\n");
    printf("7 - Consultar o último elemento:\n");
    printf("8 - Verificar se o deque está vazio:\n");
    printf("9 - Verificar o tamanho do deque:\n");
    printf("10 - Esvaziar o deque:\n");
    printf("Para sair pressione qualquer tecla:\n");
    printf("\n\nEscolha um número: ");
    scanf("%d", &x);                            //irá ler qual a opção que o usuário deseja
    switch (x) {                                //escolherá uma opção de acordo com a resposta do usuário
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d",&y);
                insere_inicio(d,y);
                system("clear");                //limpará a tela
                menu(d);                        //voltará para a função menu
                break ;
            case 2:
                printf("\nDigite um valor: ");
                scanf("%d",&y);
                insere_final(d,y);
                system("clear");
                menu(d);
                break ;
            case 3:
                remove_inicio(d);
                system("clear");
                menu(d);
                break ;
            case 4:
                remove_final(d);
                system("clear");
                menu(d);
                break ;
            case 5:        
                imprime_deque(d);
                setbuf(stdin, NULL);                //apaga o buffer do teclado
                getchar();                          //pausa a tela para o usuário ler as informações
                system("clear");                    //ao pressionar uma tecla, limpará a tela e retornará ao menu
                menu(d);
                break ;
            case 6:
                y = consulta_inicio(d);
                if (y == 0) 
                    printf("\nO deque não possui elementos\n");
                else 
                    printf("\nPrimeiro elemento: %d\n", consulta_inicio(d));   
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                menu(d);
                break ;
            case 7:
                y = consulta_final(d);
                if (y == 0) 
                    printf("\nO deque não possui elementos\n");
                else
                printf("\nÚltimo elemento: %d\n", consulta_final(d));
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                menu(d);
                break ;
            case 8:        
                y = vazio(d);
                if (y==1)
                    printf("\nO deque está vazio\n");
                else 
                    printf("\nO deque não está vazio\n");
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                menu(d);
                break ;
            case 9:
                y = tamanho(d);
                printf("\nO tamanho do deque é: %d\n", y);
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                menu(d);
                break ;
            case 10:
                libera_deque(d);
                printf("\nDeque liberado\n");
                printf("\nO programa irá ser encerrado\n\n");
                return ;                            //ao liberar a memória, encerrará o programa
    }
}