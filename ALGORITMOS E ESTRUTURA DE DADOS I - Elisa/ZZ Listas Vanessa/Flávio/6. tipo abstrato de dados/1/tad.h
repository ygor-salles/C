#ifndef TAD_H
#define TAD_H

typedef struct cpf Cpf;

//atribuição da estrutura
Cpf *cria (int alunos);

//preencher os dados
void preenche (Cpf *dados, int alunos);

//impressão dos dados
void imprime (Cpf *dados, int alunos);

#endif /* TAD_H */

