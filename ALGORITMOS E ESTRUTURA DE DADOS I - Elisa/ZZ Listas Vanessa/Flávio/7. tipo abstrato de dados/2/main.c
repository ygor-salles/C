#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"
#include <string.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    int n, q;
    car *dados;
    char p[8], np[8], m[20];
    
    //alocando os dados
    printf("Digite o número de carros: ");
    scanf("%d", &n);
    dados = cria(n);
    
    //alterar os dados pela placa 
    printf("\n          ALTERANDO OS DADOS PELA PLACA\n\n");
    printf("Digite a placa a ser alterada: ");
    scanf(" %[^\n]", p);
    altera(n,p,dados);
    
    //imprimindo os dados pela placa  
    printf("\n          IMPRIMINDO OS DADOS PELA PLACA\n\n");
    printf("Digite a placa a ser pesquisada: ");
    scanf(" %[^\n]", np);
    imprime(n,np,dados);
    
    //quantidade de carros por marca
    printf("\n          PESQUISANDO OS CARROS PELA MARCA\n\n");
    printf("Digite a marca a ser pesquisada: ");
    scanf(" %[^\n]", m);
    q = quantidade(n,m,dados);
    printf("\nHá %d carros dessa marca\n\n",q);
    
    //libera memória
    libera(dados);
    
    return 0;
}



