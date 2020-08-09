#include <stdio.h>
#include <stdlib.h>
#include "aplicacao.h"
#include <string.h>

struct Item {
    int num;
    int status;
    char nome[20];
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

deque* cria_deque() {
    deque *d = (deque*) malloc(sizeof (deque));
    if (!d) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    d->final = NULL;
    d->inicio = NULL;
    d->qtd = 0;
    return d;
}

void libera_deque(deque *d) {
    if (d != NULL) {
        no *no;
        while (d->inicio != NULL) {
            no = d->inicio;
            d->inicio = d->inicio->prox;
            free(no);
        }
        free(d);
    }
    return;
}

int tamanho(deque *d) {
    if (!d)
        return 0;
    return d->qtd;
}

int vazio(deque *d) {
    if (!d || !d->inicio)
        return 1;
    return 0;
}

int consulta_inicio(deque *d) {
    if (!d || !d->inicio)
        return 0;
    return d->inicio->dados.num;
}

int consulta_final(deque *d) {
    if (!d || !d->final)
        return 0;
    return d->final->dados.num;
}

void insere_inicio(deque *d, int i, char nome [], int stat) {
    if (!d)
        return;
    no *novono = (no*) malloc(sizeof (no));
    if (!novono) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    novono->dados.num = i;
    strcpy(novono->dados.nome, nome);
    novono->dados.status = stat;
    novono->prox = d->inicio;
    novono->ant = NULL;
    if (!d->inicio)
        d->final = novono;
    else
        d->inicio->ant = novono;
    d->inicio = novono;
    d->qtd++;
    return;
}

void insere_final(deque *d, int i, char nome [], int stat) {
    if (!d)
        return;
    no *novono = (no*) malloc(sizeof (no));
    if (!novono) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    novono->dados.num = i;
    strcpy(novono->dados.nome, nome);
    novono->dados.status = stat;
    novono->prox = NULL;
    if (!d->final) {
        novono->ant = NULL;
        d->inicio = novono;
    } else {
        novono->ant = d->final;
        d->final->prox = novono;
    }
    d->final = novono;
    d->qtd++;
    return;
}

void remove_inicio(deque *d) {
    if (!d || !d->inicio)
        return;
    no *novono = d->inicio;
    d->inicio = d->inicio->prox;
    if (!d->inicio)
        d->final = NULL;
    else
        d->inicio->ant = NULL;
    free(novono);
    d->qtd--;
    return;
}

void remove_final(deque *d) {
    if (!d || !d->inicio)
        return;
    no *novono = d->final;
    if (novono == d->inicio) {
        d->inicio = NULL;
        d->final = NULL;
    } else {
        novono->ant->prox = NULL;
        d->final = novono->ant;
    }
    free(novono);
    d->qtd--;
    return;
}

void remove_prioridade(deque *d) {
    /*a funcao recebe o deque por completo e então compara o status do dado
      apontado pelo ponteiro inicio com o status apontado pelo ponteiro final
      do deque.*/
    if (d->inicio->dados.status < d->final->dados.status) {
        printf("Matricula: %d Nome: %s \n", d->inicio->dados.num, d->inicio->dados.nome);
        remove_inicio(d);
    } else if (d->inicio->dados.status > d->final->dados.status) {
        printf("Matricula: %d Nome: %s \n", d->final->dados.num, d->final->dados.nome);
        remove_final(d);
    } else {
        printf("Matricula: %d Nome: %s \n", d->inicio->dados.num, d->inicio->dados.nome);
        remove_inicio(d);
    }
    /*foi previamente definido que o dado com menor status deveria ser imprimido
      primeiro, se o status dos dois arquivos forem iguais ele ira imprimir
      o dado contido no inicio do deque.
      para a remoção foi utilizado as funções já definidas pela TAD de deque
      remove_inicio e remove_final     
     */
}

void menu(deque *d) {
    FILE *arq1;
    FILE *arq2;
    
    int stat, matr, x, i, n = 0, c1[20],c2[20];
    char nome[20];
    printf("        Simulação de uma impressora para 2 computadores usando Deque\n\n");

    /*esse momento o menu abre para que o usuario digite o nome dos arquivos
     o nome utilizado para nossos testes foram impressora1.txt e impressora2.txt
     */
    printf ("Digite o nome do arquivo recebido pelo computador 1: ");
    scanf (" %[^\n]",c1);
    printf ("\nDigite o nome do arquivo recebido pelo computador 2: ");
    scanf (" %[^\n]",c2);
    
    //abertura e verificação dos arquivos de texto.
    arq1 = fopen(c1, "r");
    arq2 = fopen(c2, "r");
    if (!arq1 || !arq2) {
        printf("Falha ao abrir arquivo.\n");
        exit(1);
    } else
        printf("\narquivo 1 e 2 recebido com sucesso!!\n\n");

    /*o arquivo a ser lido foi previamente definido para ser lido como:
     numero de matricula nome indice do status*/
    
    /*leitura e adição dos dados ao deque, arquivo 1 será inserido no inicio do
     deque e o arquivo 2 será inserido no final do deque*/
    while (!feof(arq1)) {
        fscanf(arq1, "%d %s %d", &matr, nome, &stat);
        insere_inicio(d, matr, nome, stat);
        n++;
    }
    
    while (!feof(arq2)) {
        fscanf(arq2, "%d %s %d", &matr, nome, &stat);
        insere_final(d, matr, nome, stat);
        n++;
    }
    
    //utiliza a função remove_prioridade para remover e mostrar na tela o dado removido
    for (i = 0; i < n; i++) {
        remove_prioridade(d);
    }

    /*neste momento será chamado a função libera_deque para liberar a memoria
     alocada pelo deque e então iremos fechar os arquivos de texto assim o
     programa será encerrado com segurança*/
    libera_deque(d);
    fclose(arq1);
    fclose(arq2);
    return;
}