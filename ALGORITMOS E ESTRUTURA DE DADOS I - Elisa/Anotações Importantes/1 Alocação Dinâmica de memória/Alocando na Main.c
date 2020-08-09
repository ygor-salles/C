#include<stdio.h>
#include<stdlib.h>

int main ()
{
    // linha 3
    //coluna 3
    int *v, **m, i, j, k=0, tam_vet=9, linha=3, coluna=3;

    //Aloca Vetor
    v = (int*) malloc(tam_vet * sizeof(int));
    if (v == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        exit (1);
    }

    //Aloca matriz
    m = (int**) malloc(linha * sizeof(int*));
    if (m == NULL){
        printf ("MEMORIA INSUFICIENTE!");
        exit (1);
    }
    for (i=0; i<linha; i++){
        m[i] = (int*) malloc(coluna * sizeof(int));
        if (m[i] == NULL){
            printf ("MEMORIA INSUFICIENTE!");
            exit (1);
        }
    }

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

    //Desaloca vetor
    free(v);
    //Desaloca matriz
    free (m);
    return 0;
}
