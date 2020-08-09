#ifndef TAD_H
#define TAD_H

typedef struct alunos al;

//Criar uma lista com n alunos e preencher as informações
al *cria (int n);

//Retornar a média de um determinado aluno dado sua matrícula
float media (int cod, int n, al *dados);

//Retornar a média das médias de todos os alunos
float mediamedia (int cod, int n, al *dados);

//liberar a memória
void libera (al *dados);








#endif /* TAD_H */

