#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que preencha um vetor com os nomes de sete alunos e carregue outro vetor com a média
final desses alunos. Calcule e mostre:
º o nome do aluno com maior média (desconsiderar empates);
º para cada aluno não aprovado, isto é, comm édia menor que 7, mostrar quanto essea luno precisa tirar
na prova de exame final para ser aprovado. Considerar que a médiap ara aprovação no exame é 5. */

int main ()
{
    char nome[7], nome_maior;
    float media[7], maior, media_final[7];
    int i;

    for (i=0; i<7; i++){
        printf ("Digite a inicial do seu nome: ");
        scanf (" %c",&nome[i]);
        printf ("Digite a sua media: ");
        scanf ("%f",&media[i]);
        printf ("\n");
    }

    maior = media[0];
    nome_maior = nome[0];
    for (i=1; i<7; i++){
        if (media[i] > maior){
            maior = media[i];
            nome_maior = nome[i];
        }
    }
    printf ("\nO nome com a maior media foi  %c \n",nome_maior);

    printf ("\nLista de exame | Nota necessaria p/ passar \n");
    for (i=0; i<7; i++){
        if (media[i]<7){
            media_final[i] = 7*2-media[i];
            printf ("        %c      |%16.2f\n",nome[i], media_final[i]);
        }
    }
    printf ("\n");
    system ("pause");
    return 0;
}
