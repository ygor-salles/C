#ifndef TAD_H
#define TAD_H

typedef struct matriz1 mat1;
typedef struct matriz2 mat2;

//alocando matriz 1
mat1 **cria1 (int n);

//alocando matriz 2
mat2 **cria2 (int n);

//preenche matriz1
void preenche1 (int n, mat1 **m1);

//preenche matriz2
void preenche2 (int n, mat2 **m2);

//imprimindo matriz1
void imprime1 (int n, mat1 **m1);

//imprimindo matriz2
void imprime2 (int n, mat2 **m2);

//somando as matrizes
void soma (int n, mat1 **m1, mat2 **m2);



#endif /* TAD_H */

