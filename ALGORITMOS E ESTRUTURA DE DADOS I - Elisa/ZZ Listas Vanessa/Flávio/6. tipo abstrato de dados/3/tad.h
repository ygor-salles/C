#ifndef TAD_H
#define TAD_H

//renomeando a struct
typedef struct candidato cand;

//alocando a struct
cand *cria (char nomearquivo[], int *n);

//preenche a struct
void imprime(int n, cand *dados);

//retornar os dados a partir da identidade
void ident(int n, char id[], cand *dados);

//imprimir candidatos com a mesma profissão
void prof(int n, char p[], cand *dados);

#endif /* TAD_H */

