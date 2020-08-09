#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int mat, i;
    float nota1, nota2;
    FILE *arq;
    arq = fopen("exercicioArquivo.dat","w+");

    if (arq == NULL) {
        printf("\nArquivo inválido");
        exit(1);
    }
    else {
        printf("Digite a mat:");
        scanf("%d", &mat);

        while (mat!=0){
            printf("\nDigite a N1:");
            scanf("%f", &nota1);
            printf("\nDigite a N2:");
            scanf("%f", &nota2);
            fprintf(arq, "%d %.2f %.2f\n", mat, nota1, nota2);
            printf("\nDigite a mat:");
            scanf("%d", &mat);
        }
        i= 1;
        rewind(arq);
        
        fscanf(arq, "%d %f %f", &mat, &nota1, &nota2);
        while (!feof(arq)) {
            printf("\nMatricula do aluno %d: %d - Nota1: %.2f / Nota2: %.2f", i++, mat, nota1, nota2);
            fscanf(arq, "%d %f %f", &mat, &nota1, &nota2);
        }
    }
    printf("\n\n");
    fclose(arq);
    system("pause");
 }
