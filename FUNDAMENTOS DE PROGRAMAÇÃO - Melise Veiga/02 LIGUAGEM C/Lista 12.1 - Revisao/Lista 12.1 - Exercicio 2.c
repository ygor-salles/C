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

void preenche (tparticipante lista[], int n);
void retorna_qtd (tparticipante lista[], int n, int *sp, int *cor, int *fla);
void retorna_media (tparticipante lista[], int n, char clube[], float *media);
void retorna_cidade (tparticipante lista[], int n, char cidadeX[], char timeT[], int *qtd_pes);

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
    char clube[31];
    float media;
    printf ("\nDigite um determinado clube: ");
    scanf (" %[^\n]",clube);
    retorna_media (lista, n, clube, &media);
    printf ("A media de idade dos torcedores do %s eh: %.2f\n",clube, media);

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

void preenche (tparticipante lista[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("Digite o seu time: ");
        scanf (" %[^\n]",lista[i].time);
        printf ("Digite a sua procedencia: ");
        scanf (" %[^\n]",lista[i].procedencia);
        printf ("Digite a sua idade: ");
        scanf ("%d",&lista[i].idade);
        printf ("\n");
    }
    return ;
}

void retorna_qtd (tparticipante lista[], int n, int *sp, int *cor, int *fla)
{
    int i;
    for (i=0; i<n; i++){
        if (strcmp(lista[i].time,"sao paulo")==0){
            ++(*sp);
        }
        else if (strcmp(lista[i].time,"corinthians")==0){
            ++(*cor);
        }
        else if (strcmp(lista[i].time,"flamengo")==0){
            ++(*fla);
        }
    }
    return ;
}

void retorna_media (tparticipante lista[], int n, char clube[], float *media)
{
    int i, soma=0, cont=0;
    if (strcmp(clube,"sao paulo")==0){
        for (i=0; i<n; i++){
            if (strcmp("sao paulo",lista[i].time)==0){
                soma = soma + lista[i].idade;
                cont++;
            }
        }
    }
    else if (strcmp(clube,"corinthians")==0){
        for (i=0; i<n; i++){
            if (strcmp("corinthians",lista[i].time)==0){
                soma = soma + lista[i].idade;
                cont++;
            }
        }
    }
    else if (strcmp(clube,"flamengo")==0){
        for (i=0; i<n; i++){
            if (strcmp("flamengo",lista[i].time)==0){
                soma = soma + lista[i].idade;
                cont++;
            }
        }
    }
    *media = soma/(float)cont;

    return ;
}

void retorna_cidade (tparticipante lista[], int n, char cidadeX[], char timeT[], int *qtd_pes)
{
    int i;
    for (i=0; i<n; i++)
        if (strcmp(lista[i].time,timeT)==0  &&  strcmp(lista[i].procedencia,cidadeX)==0)
            ++(*qtd_pes);

    return ;
}
