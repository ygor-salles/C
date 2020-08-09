#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<conio.h>

/* P3 - Quest�o 1 No c�digo */

//Quest�o A
typedef struct
{
    int cod, ponto;
    char login[51], senha[11];
} usuario;

//Quest�o B
void funcaoB (usuario *pa, int codigo, char log[])
{
    if (pa->cod == codigo) {
        strcpy (pa->login, log);
    }
    return ;
}

//Quest�o C
void funcaoC (usuario list[], int qtd)
{
    int i;
    for (i=0; i<qtd; i++){
        printf ("\n");
        printf ("Digite o c�digo: ");
        scanf ("%d",&list[i].cod);
        printf ("Digite login: ");
        scanf (" %[^\n]",list[i].login);
        printf ("Digite senha: ");
        scanf (" %s",list[i].senha);
        list[i].ponto = 0;
    }
    return ;
}

//Quest�o D
void funcaoD (usuario list[], int qtd, int *cod_maior)
{
    int i, maior_ponto;
    maior_ponto = list[0].ponto;
    for (i=0; i<qtd; i++){
        if (list[i].ponto > maior_ponto){
            *cod_maior = list[i].cod;
            maior_ponto = list[i].ponto;
        }
    }
    if (maior_ponto == 0)
        *cod_maior = 0;
    return ;
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int codigo, qtd, codigo_maior;
    char log[51];
    usuario a;
    usuario lista[100];

    printf ("Digite o c�digo: ");
    scanf ("%d",&a.cod);
    printf ("Digite login: ");
    scanf (" %[^\n]",a.login);
    printf ("Digite senha: ");
    scanf (" %s",a.senha);      //Senha n�o possui espa�o
    a.ponto = 0;
    printf ("\n Valor de c�digo: ");    scanf ("%d",&codigo);
    printf (" Valor de login: ");     scanf (" %[^\n]",log);
    funcaoB (&a, codigo, log);
    printf (" O novo login do usu�rio �: %s\n",a.login);

    printf ("\nDigite a quantidade de usu�rios: ");
    scanf ("%d",&qtd);
    if (qtd<0 || qtd>50){
        printf ("\nQuantidade inv�lida!!\n");
        return 0;
    }
    else{
        funcaoC (lista, qtd);

        funcaoD (lista, qtd, &codigo_maior);
        if (codigo_maior != 0)
            printf ("\nO c�digo do usu�rio com a maior pontua��o �: %d",codigo_maior);
        else
            printf ("\nNenhum usu�rio pontuou at� o momento!\n");
    }

    return 0;
}
