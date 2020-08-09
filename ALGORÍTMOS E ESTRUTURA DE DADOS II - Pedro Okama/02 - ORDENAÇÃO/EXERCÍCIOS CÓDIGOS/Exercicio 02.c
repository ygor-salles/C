#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* EXERCÍCIO: Cadastrar nome de 10 funcionários e exibí-los em
 Ordem de valor e em Ordem alafabática utilizando Bubblesort */

typedef struct funcionario {
    char nome[50];
    float salario;
} funcionario;

void bubbleSortDecrescente(funcionario *F, int n) {
    int i, j;
    funcionario aux;

    for(i=1;i<n;i++) {
        for(j=(n-1);j>=i;j--) {
            if(F[j].salario > F[j-1].salario) {
                aux = F[j];
                F[j] = F[j-1];
                F[j-1] = aux;
            }
        }
    }
}

void bubbleSortAlfabetica(funcionario *F, int n) {
    int i, j;
    funcionario aux;
    for(i=1;i<n;i++) {
        for(j=(n-1);j>=i;j--) {
            if(strcmp(F[j].nome,F[j-1].nome) < 0){
                aux = F[j];
                F[j]=F[j-1];
                F[j-1]=aux;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n=10, i,j;
    funcionario *f;
    f = (funcionario*)malloc(n*sizeof(funcionario));

    for(i=0; i<n; i++) {
        printf("Digite o nome do Funcionário %d: ", i+1);
        scanf(" %[^\n]", f[i].nome);
        printf("Digite o salário do Funcionário %d: ", i+1);
        scanf("%f", &f[i].salario);
        printf("\n\n");
    }

    printf("------ORDEM DECRESCENTE------\n");
    bubbleSortDecrescente(f,n);
    for(i=0; i<n; i++) {
        printf("Funcionário %d: %s - Salário: R$ %.2f\n",i+1,f[i].nome, f[i].salario);
    }
    printf("----------------------------\n");
    bubbleSortAlfabetica(f,n);
    printf("------ORDEM ALFABÉTICA------\n");
    for(i=0; i<n; i++) {
        printf("Funcionário %d: %s\n",i+1,f[i].nome);
    }

}
