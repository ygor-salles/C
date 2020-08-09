#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int interativa(int vet[]) {
    int i,maior = vet[0];
    for(i=0; i<9; i++) {
        if(maior < vet[i])
            maior = vet[i];
    }
    return maior;
}

int recursiva(int vet[], int ini, int fim){
    int maior = 0;
    if(ini == fim) 
        maior = vet[fim];
    else {
        maior = recursiva(vet,ini+1,fim);
        if(vet[ini] > maior){
            maior = vet[ini];
        }
    }   
    return maior;  
}


int main() {
    setlocale(LC_ALL, "portuguese");
    int vet[10] = {1,2,3,4,10,6,7,8,9,2};
    
    printf("Interativa: %d\n", interativa(vet));
    printf("Recursiva: %d\n", recursiva(vet,0,9));
    
    return 0;

}