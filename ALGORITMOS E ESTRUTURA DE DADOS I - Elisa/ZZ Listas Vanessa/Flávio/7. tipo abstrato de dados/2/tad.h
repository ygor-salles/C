#ifndef TAD_H
#define TAD_H

typedef struct carros car;

//Criar uma lista com N carros. O valor de N deve ser fornecido pelo usuário
car *cria(int n);

//Alterar as informações de um carro com uma determinada placa
void altera(int n, char p[], car *dados);

//Imprimir os dados de um veículo com uma determinada placa
void imprime(int n, char p[], car *dados);

//Retornar a quantidade de veículos de uma marca
int quantidade(int n, char m[], car *dados);

//Liberar a memória
void libera(car *dados);

#endif /* TAD_H */

