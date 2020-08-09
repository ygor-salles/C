#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*3. A partir da estrutura criada no exercício 1, crie um vetor para armazenar uma lista de 40 alunos.
a. Preencha o vetor com informações digitadas pelo usuário.
b. Depois de preenchido o vetor, imprima a quantidade de alunos que possuem rendimento maior que 60.
c. Aumente em 10% os rendimentos acadêmicos de todos os alunos do curso de código = 125. */

struct aluno
{
    long mat[4], cod[4];
    float rend[4];
    char nome[4][101];
};

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    struct aluno a;
    int i, k=0;

    for (i=0; i<4; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",a.nome[i]);
        printf ("Digite matrícula: ");
        scanf ("%d",&a.mat[i]);
        printf ("Digite código: ");
        scanf ("%d",&a.cod[i]);
        printf ("Digite rendimento: ");
        scanf ("%f",&a.rend[i]);
        printf ("\n");
    }

    printf ("\n\n********************************************************\n\n");
    printf (" Nome           Matrícula       Código      Rendimento  \n");
    for (i=0; i<4; i++){
        if (a.rend[i]>60){
            k++;
        }
        if (a.cod[i] == 125){
            a.cod[i] = a.cod[i] + (a.cod[i]*0.10);
        }
        printf ("%s         %.8d              %d            R$%.2f\n",a.nome[i], a.mat[i], a.cod[i], a.rend[i]);
    }

    printf ("\nA quantidade de alunos que posseum rendimentos maior que 60 é: %d\n",k);
    return 0;
}
