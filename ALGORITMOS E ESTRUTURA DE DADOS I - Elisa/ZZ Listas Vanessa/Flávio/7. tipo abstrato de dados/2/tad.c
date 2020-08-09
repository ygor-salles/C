#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"
#include <string.h>

struct carros {
    char placa[8], marca[20], modelo[20], cor[20]; 
};

car *cria (int n) {
    car *dados;
    int i;
    
    dados = (car*) malloc(n*sizeof(car));
    if(!dados) {
        printf("Erro ao alocar\n");
        exit(1);
    }
    printf("\n");
    for (i=0; i<n; i++) {
        printf("Digite a placa do carro: ");
        scanf(" %[^\n]", dados[i].placa);
        printf("Digite a marca do carro: ");
        scanf(" %[^\n]", dados[i].marca);
        printf("Digite o modelo do carro: ");
        scanf(" %[^\n]", dados[i].modelo);
        printf("Digite a cor do carro: ");
        scanf(" %[^\n]", dados[i].cor);
        printf("\n");
    }
        printf("\n          DADOS DOS CARROS\n\n");
    for (i=0; i<n; i++) {
        printf("Placa: %s\n",dados[i].placa);
        printf("Marca: %s\n",dados[i].marca);
        printf("Modelo: %s\n",dados[i].modelo);
        printf("Cor: %s\n",dados[i].cor);
        printf("\n");
    }
    
   return dados; 
}

void altera(int n, char p[], car *dados) {
    int i, aux=0, x=-1;
    for (i=0; i<n; i++) {
        if(aux==strcmp(p,dados[i].placa)){
            x=i;
        }
    }
    if (x==-1) {
        printf("\nCarro não encontrado!\n");
    }
    else {
        printf("Digite a marca do carro: ");
        scanf(" %[^\n]", dados[x].marca);
        printf("Digite o modelo do carro: ");
        scanf(" %[^\n]", dados[x].modelo);
        printf("Digite a cor do carro: ");
        scanf(" %[^\n]", dados[x].cor);
        printf("\n");
    }
        printf("\n          NOVOS DADOS DOS CARROS\n\n");
    for (i=0; i<n; i++) {
        printf("Placa: %s\n",dados[i].placa);
        printf("Marca: %s\n",dados[i].marca);
        printf("Modelo: %s\n",dados[i].modelo);
        printf("Cor: %s\n",dados[i].cor);
        printf("\n");
    }
    return ;
}

void imprime(int n, char p[], car* dados) {
    int i, aux=0, x=-1;
    for (i=0; i<n; i++) {
        if(aux==strcmp(p,dados[i].placa)){
            x=i;
        }
    }
    if (x==-1) {
        printf("\nCarro não encontrado!\n");
    }
    else {
        printf("Placa: %s\n",dados[x].placa);
        printf("Marca: %s\n",dados[x].marca);
        printf("Modelo: %s\n",dados[x].modelo);
        printf("Cor: %s\n",dados[x].cor);
        printf("\n");
    }
    return ;
}

int quantidade(int n, char m[], car *dados) {
    int i, aux=0, x=0;
    for (i=0; i<n; i++) {
        if(aux==strcmp(m,dados[i].marca)){
            x++;
        }
    }
    return x;
}

void libera (car *dados) {
    free(dados);
}

