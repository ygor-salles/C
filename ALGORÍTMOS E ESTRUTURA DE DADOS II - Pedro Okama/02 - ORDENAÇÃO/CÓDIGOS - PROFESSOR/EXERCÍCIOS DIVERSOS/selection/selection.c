#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoas{
  int Chave;
  char name[100];
} Pessoas;

//gcc -std=c99 -Wall -pedantic-errors selection.c -o ordena
void selection(Pessoas *P, int n){ 
  int i,j,min;
  Pessoas x;

  for(i = 0; i < n-1; i++)
  {
    min = i;
    for(j = i+1; j < n; j++)
    {
      if(P[j].Chave < P[min].Chave){
        min = j;
      }
    }
    x = P[min];
    P[min] = P[i];
    P[i] = x;
  }
}

int main(int argc, char * argv[]){
    FILE *fp;
    int n;
    Pessoas * P;
    fp = fopen(argv[1], "r"); // read mode
    
    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    
    fscanf(fp, "%d\n", &n);
    P = calloc(sizeof(Pessoas), n);
    if(P==NULL){
        perror("Error while allocating memory.\n");
        exit(EXIT_FAILURE);
    }
 
    for(int i = 0; i < n; i++){
      fscanf(fp, "%d ", &(P[i].Chave));
      fgets(P[i].name, 100, fp);
      P[i].name[strlen(P[i].name) - 1] = '\0';
    }
    
    selection(P, n);
    
    for(int i = 0; i < n; i++){
      printf("%d %s\n", P[i].Chave, P[i].name);
    }
}
