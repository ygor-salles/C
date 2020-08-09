
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<locale.h>

/* Exercicio 3 */

typedef struct no
{
  int idade, matricula;
  char nome[30];
  struct no *prox;
  }noLista;
noLista *prim;

int quant=0;

bool    insereDados(noLista elemento)
{
     noLista *ant = NULL;
     noLista *atual = prim;
     noLista *ult;
     noLista *novo=(noLista *)malloc(sizeof(noLista));

     while((atual!=NULL) && (atual->matricula<elemento.matricula)){
         ant = atual;
         atual = atual->prox;
     }

     if(ant == NULL){
        prim=novo;
     }
     else{
        ant->prox = novo;
     }

     novo->idade = elemento.idade;
     novo->matricula = elemento.matricula;
     strcpy(novo->nome,elemento.nome);
     novo->prox = atual;

     if(atual == NULL){
        ult=novo;
     }

     quant++;
     return true;
}

void imprimeListaDinEnc()
{
    int i = 0;
    noLista *atual = prim;
    while(atual != NULL){
        printf("\n[POSIÇÃO ELEMENTO]: %d",i);
        printf("\nNome: %s",atual->nome);
        printf("\nIdade: %d",atual->idade);
        printf("\nMatrícula: %d\n",atual->matricula);
        atual = atual->prox;
        i++;
     }
     printf("\n");
}

float desvioPadrao()
{
    int i;
    float media=0, variancia=0, desvPad;
    noLista *aux1 = prim;
    noLista *aux2 = prim;

    //CALCULANDO A MÉDIA
    for(i=0; i<quant; i++){
        media += aux1->idade;
        aux1 = aux1->prox;
    }
    media = media / (float)quant;
    printf("\nA média de idades é: %.2f",media);

    //CALCULANDO A VARIÂNCIA
    for(i=0; i<quant; i++){
        variancia += pow(aux2->idade - media, 2);
        aux2 = aux2->prox;
    }
    printf("\nA variancia de idades é: %.2f",variancia);

    //CALCULANDO E RETORNANDO O DESVIO PADRÃO DE IDADES
    return sqrt(variancia);
}

int buscaNome(int matricula){
    int i = 0;
    noLista *atual = prim;
    while((atual != NULL) && (atual->matricula != matricula)){
        atual=atual->prox;
        i++;
    }
    if(atual == NULL)
        return -1;

    printf("\n\nA MATRÍCULA EXISTE NO SISTEMA \nNOME: %s\n",atual->nome);
    return atual->matricula;
}

void destroiListaDinEnc()
{
    noLista *atual = prim;
    noLista *apaga;
    while(atual != NULL){
        apaga = atual;
        atual = atual->prox;
        free(apaga);
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    noLista elemento;

    for(int i=0; i<3; i++){
        printf("Digite nome: "); scanf(" %[^\n]",elemento.nome);
        printf("Digite idade: "); scanf("%d",&elemento.idade);
        printf("Digite matricula: "); scanf("%d",&elemento.matricula);
        if (buscaNome(elemento.matricula) == -1)
            if(insereDados(elemento))
                printf(".. DADOS INSERIDOS CORRETAMENTE! ..\n");
            else
                printf("\n...... ERROR, DADOS NÃO INSERIDOS ........!");
        else
            i--;
        printf("\n");
    }
    system("pause"); system("CLS");

    imprimeListaDinEnc();

    printf("\nO desvio padrão das idades é: %.3f\n",desvioPadrao());

    system("pause"); system("CLS");
    int matricula, teste;
    printf("Digite a matrícula: "); scanf("%d",&matricula);
    teste = buscaNome(matricula);
    if (teste == -1 )
        printf("\n\nA MATRÍCULA NÃO EXISTE NO SISTEMA!\n");


    destroiListaDinEnc();
    printf("\nLIBERANDO MEMÓRIA... ");
    return 0;
}
