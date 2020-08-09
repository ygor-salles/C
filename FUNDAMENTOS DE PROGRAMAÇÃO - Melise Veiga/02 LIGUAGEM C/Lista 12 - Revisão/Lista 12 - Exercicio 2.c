#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* 2. Elaborar um programa que auxilie no controle de uma fazenda de gado. A base de
dados � formada por um conjunto de estruturas (registros) contendo os seguintes
campos referentes a cada cabe�a de gado:
� c�digo: c�digo da cabe�a de gado,
� leite: n�mero de litros de leite produzido por semana,
� alim: quantidade de alimento ingerida por semana - em quilos,
� nasc: data de nascimento - m�s e ano,
� abate: �N" (n�o) ou �S� (sim)
Crie uma estrutura data para representar a data de nascimento. A estrutura deve ter dois
campos: m�s e ano. Use a estrutura data para definir o campo data nasc (data de
nascimento) da estrutura que representar� as informa��es do gado. O n�mero de cabe�as de
gado que dever�o ser armazenadas deve ser fornecido pelo usu�rio. Use o typedef nos dois
casos (para cria��o da estrutura para data e para o gado).
Crie fun��es para:
a) Preencher a lista com as informa��es sobre as cabe�as de gado que ser�o digitadas
pelo usu�rio (com exce��o do campo abate).
b) Preencher o campo abate de todos os gados cadastrados considerando que um gado
vai para o abate se atender a uma das condi��es abaixo:
o tenha mais de 5 anos ou
o produza menos de 40 litros de leite por semana ou
o produza entre 50 e 70 litros de leite por semana e ingira mais de 50 quilos de
alimento por semana */

struct Data
{
    int mes, ano;
};
typedef struct Data Data;

struct Gado
{
    int leite, alim;
    char abate, cod[10];
    Data nasc;
};
typedef struct Gado Gado;


void preenche_lista(Gado dmais[], int n);
void preenche_abate(Gado dmais[], int n);

int main (void)
{
    setlocale(LC_ALL, "Portuguese");
    int n, i;
    printf ("Digite a quantidade de gado: "); scanf("%d",&n);
    Gado dmais[n];

    //Quest�o A
    preenche_lista(dmais, n);


    //Quest�o B
    printf ("\nListagem de qual gado vai par abate: \n");
    preenche_abate(dmais, n);

    return 0;
}

void preenche_lista(Gado dmais[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf ("\nDigite o c�digo: "); scanf(" %s",dmais[i].cod);
        printf ("Digite o nro de litro de leite produzido por semana: "); scanf("%d",&dmais[i].leite);
        printf ("Digite a qtd de alimento ingerida por semana: "); scanf("%d",&dmais[i].alim);
        printf ("Digite a data de nascimneto m�s/ano: ");
        printf ("M�s: "); scanf("%d",&dmais[i].nasc.mes);
        printf ("Ano: "); scanf("%d",&dmais[i].nasc.ano);
        system("CLS");
    }
    return ;
}

void preenche_abate(Gado dmais[], int n)
{
    int i;
    for (i=0; i<n; i++){
        if (dmais[i].nasc.ano<2013 || dmais[i].leite<40 || ((dmais[i].leite>50 && dmais[i].leite<70) && dmais[i].alim>50))
            dmais[i].abate = 'S';
        else
            dmais[i].abate = 'N';

        printf ("Gado de C�digo [%s]: %c\n",dmais[i].cod, dmais[i].abate);
    }
    return ;
}


