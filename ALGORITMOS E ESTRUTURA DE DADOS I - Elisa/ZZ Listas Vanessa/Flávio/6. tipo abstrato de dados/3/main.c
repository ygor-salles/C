#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    
    //declarando as variáveis
    int n;
    cand *dados;
    char id[9], p[20],narq[20];
        
    //alocando os candidatos
    dados = cria("arquivo.txt", &n);
    printf("%d candidatos\n", n);
    //prenchendo os dados
    imprime(n,dados);
    
    //perguntando a identidade
    printf("\nDigite a identidade para procurar: ");
    scanf(" %[^\n]", id);
    ident(n,id,dados);
    
    //perguntando a profissão
    printf("\nDigite a profissão para procurar: ");
    scanf(" %[^\n]", p);
    prof(n,p,dados);

    return 0;
}

