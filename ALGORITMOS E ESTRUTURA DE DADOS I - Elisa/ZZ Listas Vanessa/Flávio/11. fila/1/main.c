#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
   
    fila *f;
    
    f=criafila();
    int i,a[5], aux;

    enfileirar(f,5);     
    enfileirar(f,15);
    enfileirar(f,20);
    enfileirar(f,25);
    enfileirar(f,30);
    aux=desinfileirar(f);
    enfileirar(f,35);     
    enfileirar(f,40);
    enfileirar(f,45);
    enfileirar(f,60);
    enfileirar(f,60);     
    enfileirar(f,65);
    aux=desinfileirar(f);
    aux=desinfileirar(f);
    aux=desinfileirar(f);
    enfileirar(f,70);     
    enfileirar(f,75);
    imprimefila(f);            
    
    /*enfileirar(f,15);
    enfileirar(f,20);
    enfileirar(f,25);
    aux=desinfileirar(f);
    
    imprimefila(f);
    */
    /*printf("Insira 5 elementos: \n");
    for(i=0;i<5;i++) {
        scanf("%d", &a[i]);
        enfileirar(f,a[i]);
    }
    
    aux = desinfileirar(f);
    printf("\nInsira mais 4 elementos: \n");
    for(i=0;i<4;i++) {
        scanf("%d", &a[i]);
        enfileirar(f,a[i]);
    }   
    printf("\nInsira mais 2 elementos: \n");
    for(i=0;i<2;i++) {
        scanf("%d", &a[i]);
        enfileirar(f,a[i]);
    }     
    aux = desinfileirar(f);
    aux = desinfileirar(f);
    aux = desinfileirar(f);
    printf("\nInsira mais 2 elementos: \n");
    for(i=0;i<2;i++) {
        scanf("%d", &a[i]);
        enfileirar(f,a[i]);
    } 
    imprimefila(f);
     */

    return 0;
}

