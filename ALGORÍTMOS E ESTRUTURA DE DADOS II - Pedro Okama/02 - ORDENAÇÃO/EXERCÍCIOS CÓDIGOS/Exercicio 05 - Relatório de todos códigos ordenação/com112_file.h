#ifndef COM112_FILE_H
#define COM112_FILE_H
#include "com112_sort.h"

//Gerar números aleatórios no arquivo
void gerarNumeros(int n);
//Ler os números dos arquivos
void lerNumeros(Desordenados *d);
//Desordena os números novamente para poder ordenar outra vez
void desordenar(Desordenados *d);
//Copia os números ordenados para os arquivos
void ordenados(Desordenados *d);
//Gera relatorio de número de elementos, método usado, tempo de execução,
//número de comparações e número de movimentação
void relatorioCompleto(Desordenados *d, FILE *arquivo3);


#endif /* COM112_FILE_H */

