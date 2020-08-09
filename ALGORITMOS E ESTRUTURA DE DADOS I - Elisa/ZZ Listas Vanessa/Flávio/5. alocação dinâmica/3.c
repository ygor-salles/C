#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

FILE *arquivo;

void aloca(int x, int *v) {
	int i;
	v = (int*) malloc(x*sizeof(int));
	if (!v) {
		printf("Erro ao alocar\n");
		return ;
	}
}



int main () {
	setlocale(LC_ALL, "portuguese");
	//declaração de variaveis
	int *v, x, i, **mat, z, j, t=0;
	float y;
	char nome[50];
	
	
	//numero de termos
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &x); 
	
	//alocação
	//aloca(x, v);
	v = (int*) malloc(x*sizeof(int));
	if (!v) {
		printf("Erro ao alocar\n");
		return ;
	}
	//preenchendo randomicamente o vetor
	for (i=0; i<x; i++){
		v[i] = rand () %100;
	}
	
	//alocando a matriz
	z = sqrt(x);
	y = sqrt(x);
	if (y>z) {
		z +=1;
	}
	mat = (int**) malloc (z*sizeof(int));
		for (i=0; i<z; i++) {
			mat[i] = (int*) malloc (z*sizeof(int));
		}
	if (!mat) {
		printf("Erro ao alocar\n");
		return ;
	}		
	
	//preenchendo a matriz
	for(i=0; i<z; i++) {
		for(j=0; j<z; j++) {
			mat[i][j] = v[t];
			t++;
		}
	}
	
	//imprimindo a matriz
	printf("\n");
	for(i=0; i<z; i++) {
		for(j=0; j<z; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}	
	
	//salvando no arquivo
	printf("Digite o nome para salvar o arquivo: ");
	scanf(" %[^\n]", nome);
	printf("%s\n", nome);
	
	arquivo = fopen("%s.txt", "w");
	
	fclose(arquivo);
	
	
	
	
	
	return 0;
}
