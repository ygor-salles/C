#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include"mergelista.h"

void main(){
struct Node* a = NULL;
//FILE *arq;
int  dado=0, i=0;
clock_t Ticks[2];
double Tempo;

srand(time(NULL));

/*arq = fopen("entrada.txt","r");
arq2 = fopen("saida.txt","w");

while(!feof(arq)){//leitura do arquivo
fscanf(arq,"%d\n", &dado);
*/

for(i=0; i<30000;i++){
construct(&a, rand() % 999999);}

printf("\n\nLista Desordenada: \n");
mostraLista(a);

Ticks[0] = clock();
MergeSort(&a);
Ticks[1] = clock();
Tempo = (Ticks[1] - Ticks[0])* 1000/CLOCKS_PER_SEC;
    
                    
printf("\n\nLista Ordenada: \n");
mostraLista(a);

printf("\n\nTempo Gasto: %g Milissegundos.", Tempo);
printf("\nMovimentacao: %d ", aumentaMov()-1);
printf("\nComparacao: %d ", aumentaComp()-1);

a = limpar(a);

//fclose(arq);
}
        