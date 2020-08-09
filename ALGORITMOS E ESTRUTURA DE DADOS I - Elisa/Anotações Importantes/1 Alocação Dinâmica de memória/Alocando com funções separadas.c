#include<stdio.h>
#include<stdlib.h>

int *aloca_vetor (int tam_vet);
int **aloca_matriz (int linha, int coluna);

int main ()
{
    // linha 3
    //coluna 3
    int *v, **m, i, j, k=0, tam_vet=9, linha=3, coluna=3;

    v = aloca_vetor(tam_vet);
    m = aloca_matriz(linha, coluna);

    printf ("Preencha com inteiros: \n");
    for (i=0; i<tam_vet; i++)
        scanf ("%d",&v[i]);

    printf ("\n Vetor: \n");
    for (i=0; i<tam_vet; i++)
        printf (" %d",v[i]);

    printf ("\n\n Matriz: \n");
    for (i=0; i<linha; i++){
        for (j=0; j<coluna; j++){
            m[i][j] = v[k];
            k++;
            printf (" %d",m[i][j]);
        }
        printf ("\n");
    }

    //desaloca vetor
    free(v);
    //desaloca matriz
    free(m);
    return 0;
}

int *aloca_vetor (int tam_vet)
{
    int *v;
    v = (int*) malloc(tam_vet * sizeof(int));
    if (v == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        return NULL;
    }
    return v;
}

int **aloca_matriz (int linha, int coluna)
{
    int **m, i;
    m = (int**) malloc(linha * sizeof(int*));
    if (m == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        return NULL;
    }

    for (i=0; i<linha; i++){
        m[i] = (int*) malloc(coluna * sizeof(int));
        if (m[i] == NULL){
            printf ("MEMORIA INSUFICIENTE!");
            return NULL;
        }
    }
    return m;
}
