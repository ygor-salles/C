#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int **cria (int x) {
    int **vet, i;
    vet = (int**) malloc(x*sizeof(int));
    if (!vet) {
        printf("Erro ao alocar\n");
        exit (1);
    }
    for (i=0; i<x; i++) {
        vet[i] = (int*) malloc(x*sizeof(int));
        
    }
    if (!vet) {
        printf("Erro ao alocar\n");
        exit (1);
    }
    return vet;   
}

void preencherandom (int x, int **vet) {
    int i, j;
       for (i=0; i<x; i++) {
           for(j=0; j<x; j++) {
                vet[i][j] = rand()%100;
           }
    } 
    return;
}

void imprimerandom (int x, int **vet) {
    int i,j;
    printf("\n");
    for (i=0; i<x; i++) {
        for (j=0; j<x; j++) {
            printf("%d ", vet[i][j]);
        }
    printf("\n");   
    } 
    printf("\n");
    return ;   
}

int main() {
    setlocale (LC_ALL, "portuguese");
    //inicialização das variaveis
    int i,x,**vet;
    
    //alocação do vetor
    printf("Digite quantas posições o vetor terá: ");
    scanf("%d", &x);
    vet = cria(x);
    
    //preenchendo os vetores aleatoriamente
    preencherandom(x,vet);
    
    //imprimindo os vetores aleatoriamente
    imprimerandom(x,vet);
    
   
    
    free(vet);
    return 0;
}

