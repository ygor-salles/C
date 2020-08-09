#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorial(int n){
    int fat;
    if(n==0)
        return 1;
    else 
        return n*fatorial(n-1); 
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int n;
    
    printf("Digite o número que deseja: ");
    scanf("%d", &n);
    printf("Fatorial: %d\n",fatorial(n));
    return 0;
}