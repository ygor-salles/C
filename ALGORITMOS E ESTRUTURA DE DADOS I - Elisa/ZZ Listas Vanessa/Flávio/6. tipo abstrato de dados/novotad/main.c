#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    
    //declaração das variaveis
    int i, j, m, n;
    mat *tmat;
    float valor;
    
    printf("Digite o número de linhas: ");
    scanf("%d", &m);
    printf("Digite o número de colunas: ");
    scanf("%d", &n);
    tmat = cria(m,n);
    preenchealeatoriamente(tmat);
    imprime(tmat);
    
    printf("Digite a linha que deseja mudar: ");
    scanf("%d", &i);
    printf("Digite a coluna que deseja mudar: ");
    scanf("%d", &j);
    printf("Digite o valor a ser alterado: ");
    scanf("%f", &valor);
    atribui(tmat,i,j,valor);
    imprime(tmat);

    
    


    return 0;
}

