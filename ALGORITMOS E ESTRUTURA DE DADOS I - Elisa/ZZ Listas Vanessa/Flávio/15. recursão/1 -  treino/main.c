#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int mult(int n1, int n2) {
    if(n2 == 1) 
        return n1;
    else 
        return n1 + mult(n1,n2-1);
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int n1, n2;
    printf("Digite dois números: \n");
    scanf("%d""%d", &n1, &n2);
    printf("\nSua multiplicação é: %d\n",mult(n1,n2));
    
    return 0;
}