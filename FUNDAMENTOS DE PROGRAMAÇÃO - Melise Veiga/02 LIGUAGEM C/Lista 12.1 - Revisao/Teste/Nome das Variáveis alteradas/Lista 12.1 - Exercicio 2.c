#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*2. Em uma cidade, foi realizada uma pesquisa de opinião com as perguntas abaixo:
• Entre os clubes abaixo, qual o de sua preferência?
São Paulo
Corinthians
Flamengo
• Qual a sua idade?
• Qual a sua procedência?
São Paulo
Minas Gerais
Rio de Janeiro
a. Defina um novo tipo (estrutura) tParticipante para representar cada participante da pesquisa.
b. Crie um vetor para alocar estaticamente n estruturas do tipo tParticipante. O valor de n deve ser fornecido pelo responsável pela pesquisa (n<=100).
c. Crie uma função para preencher os valores fornecidos pelos candidatos.
d. Cria uma função que retorne a quantidade de torcedores por clube.
e. Crie uma função que retorne a média de idade dos torcedores de um determinado clube (o nome do clube deve ser passado como parâmetro).
f. Crie uma função que retorne a quantidade de pessoas nascidas na cidade X que torcem pelo time T. O nome da cidade e o nome do time devem ser passados como parâmetros para função;
g. Crie o programa principal e faça a chamada das funções criadas. */

//Questão A
typedef struct participante
{
    char time[31], procedencia[31];
    int idade;
} tparticipante;

void preenche (tparticipante list[], int n);
void retorna_qtd (tparticipante list[], int n, int *psp, int *pcor, int *pfla);
void retorna_media (tparticipante list[], int n, char clube[], float *pmedia);
void retorna_cidade (tparticipante list[], int n, char xx[], char tt[], int *pqtd_pes);

//Questão G
int main ()
{
    //Questão B
    int n;
    printf ("Digite a quantidade de participante <=100: ");
    scanf ("%d",&n);
    if (n<=0 || n>100){
        printf ("\nDigite a quantidade adequada!\n");
        return 0;
    }
    tparticipante lista[n];

    //Questão C
    preenche (lista, n);

    //Questão D
    int sp=0, cor=0, fla=0;
    retorna_qtd (lista, n, &sp, &cor, &fla);
    printf ("Torcedores sao paulinos: [%d], corinthianos: [%d], flamenguistas: [%d]\n",sp, cor, fla);

    //Questão E
    char club[31];
    float media;
    printf ("\nDigite um determinado clube: ");
    scanf (" %[^\n]",club);
    retorna_media (lista, n, club, &media);
    printf ("A media de idade dos torcedores do %s eh: %.2f\n",club, media);

    //Questão F
    char cidadeX[31], timeT[31];
    int qtd_pes=0;
    printf ("\nDigite o nome da cidade: ");
    scanf(" %[^\n]",cidadeX);
    printf ("Digite o nome do time: ");
    scanf (" %[^\n]",timeT);
    retorna_cidade (lista, n, cidadeX, timeT, &qtd_pes);
    printf ("A quantidade de pessoas nascidas na cidade %s e que torcem para o %s eh %d\n",cidadeX, timeT, qtd_pes);

    return 0;
}

void preenche (tparticipante list[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite o seu time: ");
        scanf (" %[^\n]",list[i].time);
        printf ("Digite a sua procedencia: ");
        scanf (" %[^\n]",list[i].procedencia);
        printf ("Digite a sua idade: ");
        scanf ("%d",&list[i].idade);
        printf ("\n");
    }
    return ;
}

void retorna_qtd (tparticipante list[], int n, int *psp, int *pcor, int *pfla)
{
    int i;
    for (i=0; i<n; i++){
        if (strcmp(list[i].time,"sao paulo")==0){
            ++(*psp);
        }
        else if (strcmp(list[i].time,"corinthians")==0){
            ++(*pcor);
        }
        else if (strcmp(list[i].time,"flamengo")==0){
            ++(*pfla);
        }
    }
    return ;
}

void retorna_media (tparticipante list[], int n, char clube[], float *pmedia)
{
    int i, soma=0, cont=0;
    if (strcmp(clube,"sao paulo")==0){
        for (i=0; i<n; i++){
            if (strcmp("sao paulo",list[i].time)==0){
                soma = soma + list[i].idade;
                cont++;
            }
        }
    }
    else if (strcmp(clube,"corinthians")==0){
        for (i=0; i<n; i++){
            if (strcmp("corinthians",list[i].time)==0){
                soma = soma + list[i].idade;
                cont++;
            }
        }
    }
    else if (strcmp(clube,"flamengo")==0){
        for (i=0; i<n; i++){
            if (strcmp("flamengo",list[i].time)==0){
                soma = soma + list[i].idade;
                cont++;
            }
        }
    }
    *pmedia = soma/(float)cont;

    return ;
}

void retorna_cidade (tparticipante list[], int n, char xx[], char tt[], int *pqtd_pes)
{
    int i;
    for (i=0; i<n; i++)
        if (strcmp(list[i].time,tt)==0  &&  strcmp(list[i].procedencia,xx)==0)
            ++(*pqtd_pes);

    return ;
}
