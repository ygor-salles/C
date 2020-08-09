#ifndef TAD_H
#define TAD_H

typedef struct matriz mat;

//Função cria - Aloca e retorna matriz m por n
mat *cria(int m, int n);

//Função libera - Libera a memória de uma matriz
void libera(mat *m);

//Função acessa - Retorna o valor do elemento [i][j]
float acessa(mat *m, int i, int j);

//Função atribui - Atribui valor ao elemento [i][j]
void atribui(mat *m, int i, int j, float valor);

//Função linhas - Retorna o no. de linhas da matriz
int linhas (mat *m);

//Função colunas - Retorna o no. de colunas da matriz
int colunas (mat *m);

//Função preencheAleatoriamente – Preenche a matriz aleatoriamente
void preenchealeatoriamente (mat *m);

//Função imprime – Imprime a matriz com dimensões m por n
void imprime (mat *m);

#endif /* TAD_H */

