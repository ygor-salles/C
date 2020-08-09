#include<stdio.h>
#include<stdlib.h>

/* 3. Escreva:
(a) Uma função para converter uma matriz representada por um vetor numa matriz represen-
tada por um vetor de ponteiros:
float **converte_a(int m, int n, float *mat);
(b) Uma função para converter uma matriz representada por um vetor de ponteiros numa
matriz representada por um vetor:
float *converte_b(int m, int n, float **mat);
Escreva também as funções para criar as matrizes e implemente uma função main para testar
as conversões. */

float **converte_a(int m, int n, float *mat);
float *converte_b(int m, int n, float **matb);

int main ()
{
    int m, n, i, j;
    float *mat, **matb, **mat2, *mat3;

    printf ("Digite o valor de linhas: ");
    scanf ("%d",&m);
    printf ("Digite o valor de colunas: ");
    scanf ("%d",&n);

    //Questão A
    mat = (float*) malloc(m*n*sizeof(float));
    if (mat==NULL){
        printf ("MEMORIA INSUFICIENTE!");
        exit(1);
    }

    printf ("\nPreencha matriz com vetor: \n");
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            scanf (" %f",&mat[i*n+j]);

    mat2 = converte_a(m, n, mat);

    printf ("\nMatriz representada por vetor de ponteiros: \n");
     for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf (" %.0f",mat2[i][j]);
        }
        printf ("\n");
     }

    //Questão B
    matb = (float**) malloc(m*sizeof(float*));
    if (matb == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        exit(1);
    }
    for (i=0; i<m; i++){
        matb[i] = (float*) malloc(n*sizeof(float));
        if (matb[i] == NULL){
            printf ("MEMORIA INSUFICIENTE!");
            exit(1);
        }
    }

    printf ("\nPreencha a matriz com vetor de ponteiro: \n");
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            scanf ("%f",&matb[i][j]);

    mat3 = converte_b(m, n, matb);

    printf ("\nMatriz representada por Vetor: \n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++)
            printf (" %.0f",mat3[i*n+j]);
        printf ("\n");
    }

    //Desalocar memoria
    free(mat3);
    for (i=0; i<m; i++)
        free(matb[i]);
    free(matb);
    for (i=0; i<m; i++)
        free (mat2[i]);
    free (mat2);
    free (mat);

    return 0;
}

float **converte_a(int m, int n, float *mat)
{
    int i, j; float **mat2;

    mat2 = (float**) malloc(m * sizeof(float*));
    if (mat==NULL){
        printf ("MEMORIA INSUFICIENTE!");
        return NULL;
    }
    for (i=0; i<n; i++){
        mat2[i] = (float*) malloc(n * sizeof(float));
        if (mat==NULL){
            printf ("MEMORIA INSUFICIENTE!");
            return NULL;
        }
    }
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            mat2[i][j] = mat[i*n+j];

    return mat2;
}

float *converte_b(int m, int n, float **matb)
{
    float *mat3; int i, j;

    mat3 = (float*) malloc(m*n*sizeof(float));
    if (mat3 == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        return NULL;
    }
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            mat3[i*n+j] = matb[i][j];

    return mat3;
}
