#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*3. A partir da estrutura criada no exercício 1, crie um vetor para armazenar uma lista de 40 alunos.
a. Preencha o vetor com informações digitadas pelo usuário.
b. Depois de preenchido o vetor, imprima a quantidade de alunos que possuem rendimento maior que 60.
c. Aumente em 10% os rendimentos acadêmicos de todos os alunos do curso de código = 125. */

typedef struct aluno
{
    long mat, cod;
    float rend;
    char nome[51];
} aluno;

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    aluno a[40];
    int i, k=0;

    for (i=0; i<40; i++){
        printf ("Digite nome: ");
        scanf (" %[^\n]",a[i].nome);
        printf ("Digite matrícula: ");
        scanf ("%d",&a[i].mat);
        printf ("Digite código: ");
        scanf ("%d",&a[i].cod);
        printf ("Digite rendimento: ");
        scanf ("%f",&a[i].rend);
        printf ("\n");
    }

    printf ("\n\n********************************************************\n\n");
    printf (" Nome           Matrícula       Código      Rendimento  \n");
    for (i=0; i<40; i++){
        if (a[i].rend>60){
            k++;
        }
        if (a[i].cod == 125){
            a[i].cod = a[i].cod + (a[i].cod*0.10);
        }
        printf ("%s         %.8d              %d            R$%.2f\n",a[i].nome, a[i].mat, a[i].cod, a[i].rend);
    }

    printf ("\n\nA quantidade de alunos que posseum rendimentos maior que 60 é: %d\n\n",k);
    return 0;
}
