#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*5. Utilize as funções dos exercícios 3 e 4 em um programa para preencher uma lista
de nomes de 10 alunos que deverão ser digitados pelo usuário.
Em seguida, substituir um nome da lista por um nome novo também digitado pelo usuário. */

void trocanome (char nomes[][101], char origem[], char destino[]);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    char nomes[10][101], origem[101], destino[101];
    int i;

    for (i=0; i<10; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",nomes[i]);
    }

    trocanome (nomes, origem, destino);

    printf ("\nOs nomes após a troca são: ");
    for (i=0; i<10; i++)
        printf ("\n%s", nomes[i]);

    printf ("\n");
    return 0;
}

void trocanome (char nomes[][101], char origem[], char destino[])
{
    int i;
    printf ("\nDigite o nome que deve ser trocado: ");
    scanf (" %[^\n]",origem);
    printf ("Digite um novo nome para troca: ");
    scanf (" %[^\n]",destino);

    for (i=0; i<10; i++){
        if (strcmp(nomes[i],origem)==0){
            strcpy(nomes[i],destino);
        }
    }
    return ;
}
