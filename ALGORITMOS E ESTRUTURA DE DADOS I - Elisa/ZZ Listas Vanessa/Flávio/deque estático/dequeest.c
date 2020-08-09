#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dequeest.h"
#include <string.h>

struct Item {
    int num;
};

struct Deque {
    int inicio, final, qtd;
    struct Item dados[MAX];
};

deque* cria_deque () {                                  //função que irá alocar o deque
    deque *d = (deque*)malloc(sizeof(deque));
    if(!d) {                                            //verifica se o deque alocou corretamente
        printf("Erro ao alocar\n");
        exit(1);
    }
    d->inicio = 0;                                      //inicializar o início e o final para 0
    d->final = 0;
    d->qtd = 0;                                         //inicializar a quantidade para 0
    return d;
}

void insere_inicio(deque *d, int i) {                   //função que irá inserir um elemento pelo início do deque
    if (!d)                                             //verifica se o deque está criado corretamente
        return ;
    if (d->qtd == MAX) {                                //verifica se o deque está cheio
        printf("\nO Deque está cheio, não foi possível inserir\n");
        setbuf(stdin, NULL);                            //caso esteja, informa ao usuário e não insere elemento
        getchar();                                      //limpa o buffer do teclado e pausa para o usuário ler a mensagem
        return ;
    }
    d->inicio--;            
    if (d->inicio < 0)                                  //verifica se o início se tornou negativo
        d->inicio = MAX-1;                              //caso fique, para manter o padrão circular ele é inserido na última pisção
    d->dados[d->inicio].num = i;                        //os dados na posição início recebem o valor
    d->qtd++;                                           //incrementa a quantidade
    return ;
}

void insere_final(deque *d, int i) {                   //função que irá inserir um elemento pelo final do deque
    if (!d)                                            //verifica se o deque está criado corretamente
        return ;
    if (d->qtd == MAX) {                               //verifica se o deque está cheio
        printf("\nO Deque está cheio, não foi possível inserir\n");
        setbuf(stdin, NULL);                           //caso esteja, informa ao usuário e não insere elemento
        getchar();                                     //limpa o buffer do teclado e pausa para o usuário ler a mensagem
        return ;
    }
    d->dados[d->final].num = i;                        //insere o valor na posição final
    d->final = (d->final+1)%MAX;                       //avança uma posição e garante que ele não saia do caráter circular
    d->qtd++;                                          //incrementa a quantidade 
    return ;
}

void remove_inicio(deque *d) {                         //função que irá remover o elemento inicial
    if (!d || d->qtd == 0){                            //verifica se o deque está vazio
        printf("\nNão foi possível remover\n");
        setbuf(stdin, NULL);
        getchar();
        return;
    }                    
    d->inicio = (d->inicio=1)%MAX;                    //avança o início uma posição e remove ele do ciclo
    d->qtd--;                                         //decrementa a quantidade
    return ;
}

void remove_final(deque *d) {                         //função que irá remover o elemento final
    if (!d || d->qtd == 0) {                          //verifica se o deque está vazio
        printf("\nNão foi possível remover\n");
        setbuf(stdin, NULL);
        getchar();
        return;
    }       
    d->final--;                                       //traz o final para a posição anterior e o tira do ciclo
    if (d->final <0)                                  //verifica se o final ficou negativo
        d->final = MAX-1;                             //joga ele para a posição TAM-1 para garantir o caráter circular
    d->qtd--;                                         //decrementa a quantidade
    return ;
}

void imprime_deque(deque *d) {                        //função que irá imprimir os elementos do deque
    if (!d || d->qtd == 0) {                          //verifica se o deque está vazio
        printf("\nO deque está vazio\n");
        return;
    }
    while (d->dados[d->inicio].num != NULL) {         //enquanto o dado não seja NULL, ele irá continuar o loop
        printf (" %d\n",d->dados[d->inicio].num);     //imprime os dados
        d->inicio = (d->inicio + 1) % MAX;            //e avança uma posição, garantindo a propriedade de remoção da fila
        d->qtd--;                                     //decrementa a quantidade
        if (d->qtd == 0)                              //quando a quantidade for 0, ele chegou em NULL
            d->dados[d->inicio].num = NULL;
    }
    return;
}

int consulta_inicio(deque *d) {                       //função que irá retornar o primeiro elemento do deque
    if (!d || d->qtd == 0)                            //verifica se o deque está vazio
        return 0;
    return d->dados[d->inicio].num;                   //retorna o primeiro elemento
}

int consulta_final(deque *d) {                        //função que irá retornar o último elemento do deque
    if (!d || d->qtd == 0)                            //verifica se o deque está vazio
        return 0;
    int pos = d->final-1;                             //o último elemento sempre é NULL, por isso, decrementa uma posição para mostrar o elemento
    if(pos < 0)                                       //se a posição ficar negativa, ele volta pelo caráter circular para o TAM-1
        pos = MAX-1; 
    return d->dados[pos].num;                         //retorna a última posição
}

int vazio(deque *d) {                                 //função que irá verificar se o deque está vazio
    if(!d)                                            //verifica se o deque existe
        return -1;
    if (d->qtd == 0)                                  //verifica se o deque está vazio
        return 1;   
    else                                              //se estiver cheio, retorna falso (0)
        return 0;
}

int cheio(deque *d) {                                 //função que verifica se o deque está cheio
    if(!d)                                            //verifica se o deque existe
        return -1;  
    if(d->qtd == MAX)                                 //verifica se o deque está cheio
        return 1;
    else                                              //se estiver vazio, retorna falso (0)
        return 0;
}

int tamanho (deque *d) {                             //função que retorna o tamanho do deque
    if(!d)                                           //verifica se o deque existe
        return -1;
    return d->qtd;                                   //se existir, retorna sua quantidade
}

void libera_deque(deque *d) {                        //função que irá liberar a memória do deque
    d->qtd = 0;                                      //reseta a quantidade
    free(d);                                         //libera a memória
}

void menu(deque *d) {                                //função que irá mostrar o menu, com todas as funções
    int x,y;
    
    printf("                TAD DEQUE ESTÁTICO        \n\n");
    printf("1 - Inserir pelo início:\n");
    printf("2 - Inserir pelo final:\n");
    printf("3 - Remover pelo início:\n");
    printf("4 - Remover pelo final:\n");
    printf("5 - Imprimir todos os elementos:\n");
    printf("6 - Consultar o primeiro elemento:\n");
    printf("7 - Consultar o último elemento:\n");
    printf("8 - Verificar se o deque está vazio:\n");
    printf("9 - Verificar se o deque está cheio:\n");
    printf("10 - Verificar o tamanho do deque:\n");
    printf("11 - Esvaziar o deque:\n");
    printf("Para sair pressione qualquer tecla:\n");
    printf("\n\nEscolha um número: ");
    scanf("%d", &x);                                //irá ler qual a opção que o usuário deseja
    switch (x) {                                    //escolherá uma opção de acordo com a resposta do usuário
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d",&y);
                insere_inicio(d,y);
                system("clear");                    //limpará a tela
                menu(d);                            //voltará para a função
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
                setbuf(stdin, NULL);                    //apaga o buffer do teclado
                getchar();                              //pausa a tela para o usuário ler as informações
                system("clear");                         //ao pressionar uma tecla, limpará a tela e retornará ao menu
                menu(d);
                break ;
            case 6:
                printf("\nPrimeiro elemento: %d\n", consulta_inicio(d));   
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                menu(d);
                break ;
            case 7:
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
                y = cheio(d);
                if (y==1)
                    printf("\nO deque está cheio\n");
                else 
                    printf("\nO deque não está cheio\n");
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                menu(d);
                break ;
            case 10:
                y = tamanho(d);
                printf("\nO tamanho do deque é: %d\n", y);
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                menu(d);
                break ;
              
            case 11:
                libera_deque(d);
                printf("\nDeque liberado\n");
                printf("\nO programa irá ser encerrado\n\n");
                return ;                                //ao liberar a memória, encerrará o programa
    }
}
