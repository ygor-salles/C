#include <stdio.h>
#include <stdlib.h>

int potencia(int k, int n) {
    if (n==1) 
        return k;
    else 
        return k* potencia(k,n-1);
}



int main() {
    int k,n;
    
    printf("Digite o valor de K: ");
    scanf("%d", &k);
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    printf("\n\nA potência é: %d\n\n", potencia(k,n));

    return 0;
}