#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
int i,tam;
int *v1; 
srand(time(NULL));
printf("Digite o tamanho do vetor: ");
scanf("%d",&tam);
v1=(int *) malloc(tam * sizeof(int));
for(i=0; i<tam; i++){
v1[i] = rand()%100;
printf("[%d=%d] ", i, v1[i]);
}
printf("\n");
free(v1);
return 0;
}