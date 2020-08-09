/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int buscalinear(int num[], int ini, int fim, int x){
    int pos = -1, aux = 0; 
    if(ini == fim) {
        if(num[fim] != x){ 
            return -1;
        }
        return (ini);
    }else {
        if(num[ini] == x)
            return (ini);
        buscalinear(num,ini+1,fim,x);
    }  
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int num[7] = {1,2,3,4,5,6,7}, x;
    printf("Digite um número: ");
    scanf("%d", &x);
    printf("\nPosição %d\n", buscalinear(num,0,6,x));
    
    

}