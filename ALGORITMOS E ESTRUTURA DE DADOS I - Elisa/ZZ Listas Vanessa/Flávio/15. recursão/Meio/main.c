#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int buscabinariaint(int num[], int ini, int fim, int x){
    int meio;
    while(meio!=fim) {
        meio = (ini + fim)/2;
        if (num[meio]>)
    }
    
}



int main() {
    setlocale(LC_ALL, "portuguese");
    int num[11] = {0,1,2,3,4,5,6,7,8,9,10};
    printf("Digite um número para procurar: ");
    scanf("%d", &x);
    printf("Número encontrado: %d\n",buscabinariaint(num,0,10,9));

}