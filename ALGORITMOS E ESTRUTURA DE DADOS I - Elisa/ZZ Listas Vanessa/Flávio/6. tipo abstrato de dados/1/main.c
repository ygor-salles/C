#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"
#include <string.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    //declaração das variáveis
    Cpf *dados;
    char n[50], c[12];
    int d, m, a, alunos, i;
    
    printf("Digite quantos alunos você quer cadastrar: ");
    scanf("%d", &alunos);
    
    dados = cria(alunos);
    preenche(dados,alunos);
    imprime(dados,alunos);
    



    return 0;
}

