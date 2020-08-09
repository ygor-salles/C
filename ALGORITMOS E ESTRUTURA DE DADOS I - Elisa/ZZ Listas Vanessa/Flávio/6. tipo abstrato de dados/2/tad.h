#ifndef TAD_H
#define TAD_H

//Defina uma estrutura em C, denominada produto, que tenha os campos apropriados para guardar as informações de um produto.
typedef struct produto prod;

//Aloque dinamicamente um conjunto de n produtos
prod *cria (int n);

//Entrar com as informações dos produtos
void preenche(int n, prod *cadastro);

//Retornar produto com maior preço
int maiorpreco (int n, prod *cadastro);

//Aumentar x% do salario 
void aumento (int n, int x, prod *cadastro);

//Maior produto em estoque
int estoque (int n, prod *cadastro);


#endif /* TAD_H */

