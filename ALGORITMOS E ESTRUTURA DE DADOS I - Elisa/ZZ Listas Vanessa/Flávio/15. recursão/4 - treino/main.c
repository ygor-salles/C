#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void invertestring(char nome[], int indice) {
    if(nome[indice] == '\0')
        return;
    else{
        invertestring(nome, indice +1);
        printf("%c",nome[indice]);
        return;
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    char nome[20];
    
    printf("Digite um nome: ");
    scanf("%[^\n]", nome);
    printf("\nNome invertido: ");
    invertestring(nome,0);
    printf("\n");
    return 0;
}