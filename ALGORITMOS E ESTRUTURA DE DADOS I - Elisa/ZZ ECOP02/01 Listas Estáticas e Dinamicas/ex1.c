#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
typedef struct {
    char words [30];
    int prox,elem;
}noListaEncadeada;
noListaEncadeada lista[MAX];
int prim=-1;
int dispo=0;
int quant;

void inicializaListaEstEnc(){
    int i;
    for(i=0;i<MAX-1;i++){
    lista[i] .prox=i+1;
    }
    lista[i] .prox=-1;
}

bool insereListaEncadeada(char palavra []){
    int ant, atual, novo;
    if(dispo == -1){
    return false;
    }//end if
    else{
    ant = -1;
    atual = prim;
    novo = dispo; //guarda a posicao onde deve ser inserido
    while((atual!=-1)&&(lista[atual].words<palavra)){
    //encontrar a posicao de insercao
    ant = atual;
    atual = lista[atual].prox; //elemento anterior
    }//end while
    //1a fase) removendo na lista de disponivel
    dispo = lista[dispo].prox;
    //2a fase) inserindo na lista de elementos
    if(ant == -1){//na primeira posicao da lista
    prim=novo;
    }//end if
    else{//em qualquer posicao da lista
    lista[ant].prox = novo;
    }//end else
    //atualizando valores da insercao da lista
    strcpy(lista[novo].words,palavra);
    lista[novo].prox = atual;
    quant++; return true;
    }//end else
}//end insereListaEstEnc

int pesqSeqListaEstEnc(char palavra []){
    int pos = prim;
    int cont=0;
    while((pos!=-1) && strcmp(lista[pos].words,palavra)!=0){
    cont++;
    pos = lista[pos].prox;
    }//end while
    if(cont!=pos){
    return -1;
    }
    return pos;
}//end posicaoListaEstEnc

void imprimeListaEstEnc(){
    int i = 0;
    int pos = prim;
    while(pos != -1){
    printf("[(%d)%s] ", pos, lista[pos].words);
    pos = lista[pos].prox;
    i++;
    if((i%10) == 0){ //pula linha a cada 10 impressoes
    printf("\n");
    }//end if
    }//end while
    printf("\n");
}//end imprimeListaEstEnc

int main()
{
    char palavra[30];
    int i;
    inicializaListaEstEnc();
    printf("Digite 10 palavras: \n");
    for(i=0;i<10;i++){
    scanf(" %s",palavra);
    if(pesqSeqListaEstEnc(palavra)==-1){
    insereListaEncadeada(palavra);
    }
    }
    imprimeListaEstEnc();
    return 0;
}
