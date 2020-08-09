#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int multiplica(int n1, int n2) {
    if(n2 == 1) 
        return n1;
    else 
        return n1 + multiplica(n1,n2-1);
}



int main() {
    setlocale(LC_ALL, "portuguese");
    int n1, n2;
    printf("Digite dois números para multiplicar: \n");
    scanf("%d""%d", &n1, &n2);
    printf("\nA multiplicação é: %d\n",multiplica(n1,n2));
    return 0;
}