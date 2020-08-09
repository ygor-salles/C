#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad.h"

struct matriz1 {
    int valor1;
};
struct matriz2 {
    int valor2;
};

mat1 **cria1 (int n) {
    int i;
    mat1 **m1;
    
    m1 = (mat1 **) malloc (n*sizeof(mat1*));
    for (i=0; i<n; i++) {
        m1[i] = (mat1*) malloc (n*sizeof(mat1));
    }
    
    if(!m1) {
        printf("Erro ao alocar\n");
        exit (1);
    }
    return m1 ;
}

mat2 **cria2 (int n) {
    int i;
    mat2 **m2;
    
    m2 = (mat2 **) malloc (n*sizeof(mat2*));
    for (i=0; i<n; i++) {
        m2[i] = (mat2*) malloc (n*sizeof(mat2));
    }
    
    if(!m2) {
        printf("Erro ao alocar\n");
        exit (1);
    }
    return m2 ;
}

void preenche1 (int n, mat1 **m1) {
    int i,j;
    printf("\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("Digite o valor da matriz i%d j%d: ", i,j);
            scanf("%d", &m1[i][j].valor1);
        }
    }
    return ;
}

void preenche2 (int n, mat2 **m2) {
    int i,j;
    printf("\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("Digite o valor da matriz i%d j%d: ", i,j);
            scanf("%d", &m2[i][j].valor2);
        }
    }
    return ;
}

void imprime1 (int n, mat1 **m1) {
    int i, j;
    printf("\n              IMPRIMINDO AS MATRIZES\n\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d  ", m1[i][j].valor1);
        }
        printf("\n");
    }
    return ;
}

void imprime2 (int n, mat2 **m2) {
    int i, j;
    printf("\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d  ", m2[i][j].valor2);
        }
        printf("\n");
    }
    return ;
}

void soma (int n, mat1 **m1, mat2 **m2) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            
        }
    }
    
    
}