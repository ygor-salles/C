#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void invertestring(char nome[], int inicio){
    if(nome[inicio] == '\0')
        return ;
    else {
        invertestring(nome, inicio+1);
        printf("%c",nome[inicio]);
    }
    return;
}


int main() {
    setlocale(LC_ALL, "portuguese");
    char nome[20];
    printf("Digite uma palavra: ");
    scanf("%[^\n]", nome);
    invertestring(nome,0);
    printf("\n\n");
    return 0;
}