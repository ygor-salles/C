#include <stdio.h>

int main () {

    int idade, numMas=0, numFem=0,  numFemExp=0, numFem35=0;
    char sexo, exp;
    float media, iddM=0, contM=0;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    while(idade!=0) {
        printf("Digite seu sexo (M ou F): ");
        scanf(" %c", &sexo);
        //o número de candidatos do sexo feminino e masculino;
        if (sexo == 'M') {
            numMas++;
        }
        else if (sexo == 'F') {
            numFem++;
        }
        printf("Voce tem experiencia? (S ou N): ");
        scanf(" %c", &exp);
        printf("\n\n");
        //a idade média dos homens que já têm experiência no serviço;
        if((sexo == 'M') && (exp == 'S')) {
            iddM = (iddM + idade);
            contM++;
        }
        //o número de mulheres que já têm experiência no serviço;
        if((sexo == 'F') && (exp == 'S')) {
            numFemExp++;
        }

        //o número de mulheres com idade inferior a 35 anos e com experiência no serviço
        if((sexo == 'F') && (exp == 'S') && (idade < 35)) {
            numFem35++;
        }

        printf("Digite sua idade: ");
        scanf("%d", &idade);

        if(contM>0) {
        media=iddM/contM;
        }else{
        media=0;
        }
    }
    printf("\n\n");
    printf("Numero de candidatos Homens: %d\n", numMas);
    printf("Numero de candidatos Mulheres: %d\n", numFem);
    printf("Idade media dos homens com experiencia no servico: %f\n", media);
    printf("Numero de Mulheres com experiencia no servico: %d\n", numFemExp);
    printf("Numero de Mulheres com idade inferior de 35 anos e com experiencia no servico: %d\n", numFem35);

    return 0;
}
