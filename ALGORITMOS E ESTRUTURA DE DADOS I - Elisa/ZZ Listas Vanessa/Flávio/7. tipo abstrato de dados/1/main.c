#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

int main() {
    setlocale(LC_ALL, "portuguese");
    
    //declaração das variáveis
    int n, cod;
    al *dados;
    float med, medmed;
    
    //alocando os alunos
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    dados = cria(n);
    
    //retornar a media dado a matricula
    printf("Digite a matrícula para saber a média: ");
    scanf("%d", &cod);
    med = media(cod,n,dados);
    printf("\nA média do aluno é :%.2f\n", med);

    //retorna a media das medias
    medmed = mediamedia(cod,n,dados);
    printf("\nA média das médias é:%.2f\n ", medmed);
    return 0;
    
    //liberar a memória
    libera(dados);
}

