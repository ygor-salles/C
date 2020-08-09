#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
typedef struct {
    int vet [MAX];
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

bool insereListaEncadeada(int valor ){
    int ant, atual, novo;
    if(dispo == -1){
    return false;
    }//end if
    else{
    ant = -1;
    atual = prim;
    novo = dispo; //guarda a posicao onde deve ser inserido
    while((atual!=-1)&&(lista[atual].elem<valor)){
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
    lista[novo].elem=valor;
    lista[novo].prox = atual;
    quant++; return true;
    }//end else
}//end insereListaEstEnc

bool removeListaEstEnc(int valor){
    int ant, atual;
    ant = -1;
    atual = prim;
    while((atual != -1)&&(lista[atual].elem!=valor)){
    ant = atual;
    atual = lista[atual].prox;
    }//end while
    if(atual == -1){ //nao existe o elemento
    return false;
    }//end if
    else{
    //1a fase) removendo na lista de elementos
    if(ant == -1){//na primeira posicao da lista
    prim = lista[atual].prox;
    }//end if
    else{//em qualquer posicao da lista
    lista[ant].prox = lista[atual].prox;
    }//end else
    //2a fase) inserindo na lista de disponivel
    lista[atual].prox = dispo;
    dispo = atual;
    quant--;
    return true;
    }//end else
}//end removeListaEstEnc

int pesqSeqListaEstEnc(int chave){
    int pos = prim;
    while((pos!=-1) && (lista[pos].elem!=chave)){
    pos = lista[pos].prox;
    }//end while
    return pos;
}//end posicaoListaEstEnc

void imprimeListaEstEnc()
{
    int i = 0;
    int pos = prim;
    while(pos != -1){
    printf("[(%d)%d] ", pos, lista[pos].elem);
    pos = lista[pos].prox;
    i++;
    if((i%1) == 0){ //pula linha a cada 10 impressoes
    printf("\n");
    }//end if
    }//end while
    printf("\n");
}//end imprimeListaEstEnc

int main (){
    int vetor[10]={
    7,
    4,
    2,
    9,
    1,
    5,
    0,
    8,
    3,
    6
    };
    int i,valor;
    inicializaListaEstEnc();
    for(i=0;i<MAX;i++){
    valor=vetor[i];
    if(pesqSeqListaEstEnc(valor)==-1){
    insereListaEncadeada(valor);
    }
    }
    imprimeListaEstEnc();
    printf("removendo os valores,4,0,7,9\n");
    removeListaEstEnc(4);
    removeListaEstEnc(7);
    removeListaEstEnc(0);
    removeListaEstEnc(9);
    imprimeListaEstEnc();
    printf("inserindo os valores 22 e 13\n");
    insereListaEncadeada(22);
    insereListaEncadeada(13);
    imprimeListaEstEnc();
return 0;
}
