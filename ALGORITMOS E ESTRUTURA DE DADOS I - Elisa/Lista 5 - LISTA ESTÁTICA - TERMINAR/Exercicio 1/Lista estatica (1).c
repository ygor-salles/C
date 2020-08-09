#include<stdio.h>
#define MAX 100 

typedef enum{false, true} bool; 
int listaEstSeq[MAX]; 
int dispo=0; 

int primeiroListaEstSeq()
{
  if(dispo == 0)
  return -1;
  else
  return listaEstSeq[0];
}

int ultimoListaEstSeq()
{
  if(dispo == 0)
  return -1;
  else
  return listaEstSeq[dispo-1];
}

int quantListaEstSeq()
{
return dispo;
}

void imprimeListaEstSeq()
{
  int i = 0;
  while(i < dispo){
    printf("[(%2d)=%3d] ", i, listaEstSeq[i]);
    i++;
    if((i%10) == 0){ 
      printf("\n");
    }
  }
  printf("\n");
}

bool insereListaEstSeq(int valor)
{
  int i = dispo;
  if(dispo > MAX){
    return false;
  }
  else{
    while((i > 0) && (listaEstSeq[i-1] > valor)){
      listaEstSeq[i] = listaEstSeq[i-1];
      i--;
    }
    listaEstSeq[i] = valor;
    dispo++;
    return true;
  }
}

bool removeListaEstSeq(int valor)
{
  int i = 0;
  while((i < dispo) && (listaEstSeq[i] < valor)){
    i++;
  }
  if((i < dispo) && (listaEstSeq[i] == valor)){
    while(i < dispo-1){
      listaEstSeq[i] = listaEstSeq[i+1];
      i++;
    }
    dispo--;
    return true;
  }
  else{
    return false;
  }
}

int pesqSeqListaEstSeq(int chave)
{
  int i = 0;
  while((i < dispo) && (listaEstSeq[i] < chave)){
    i++;
  }
  if((i < dispo) && (listaEstSeq[i] == chave)){
    return i;
  }
  else{
    return -1;
  }
}

int main(int argc, char **argv)
{
  int aux, i;
  for(i=0; i<MAX; i++){
    aux = rand() % (MAX*2);
    if(pesqSeqListaEstSeq(aux) == -1){
      insereListaEstSeq(aux);
    }
    else{
      i--;
    }
  }
  imprimeListaEstSeq();
  printf("Valor procurado: ");
  scanf("%d", &aux);
  printf("Encontrado na posicao %d\n",
  pesqSeqListaEstSeq(aux));
  removeListaEstSeq(aux);
  imprimeListaEstSeq();
  return 0;
}