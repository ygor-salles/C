#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int **aloca(int l, int c) {
	int i, **p;
	p = (int**) malloc(l*sizeof(int*));
	for (i=0; i<l; i++) {
		p[i] = (int *) malloc(c*sizeof(int));
	}
	
	if(!p) {
		printf("\nErro ao alocar\n");
		return;
	}
	return p;
}

void preenche (int l, int c, int **p) {
	int i, j;
	printf("\n");
	for(i=0; i<l; i++) {
		for(j=0; j<c; j++) {
			printf("Digite o valor da matriz L%d C%d: ", i+1, j+1);
			scanf("%d", &p[i][j]); 
			}
	}
	return;
}

void imprime(int l, int c, int **p) {
	int i, j;
	printf("\n");
	for(i=0; i<l; i++) {
		for(j=0; j<c; j++) {
			printf("%d  ", p[i][j]);
		}
		printf("\n");
	}
	return;
}

int main () {
	setlocale(LC_ALL, "portuguese");
	//iniciando as variáveis
	int i, j, l, c=1, **p;
	
	//determinando linhas e colunas da matriz
	printf("Digite o número de linhas: ");
	scanf("%d", &l);
	printf("Digite o número de colunas: ");
	scanf("%d", &c);

	
	//alocando a matriz
	p = aloca(l,c);
		
	//preenchendo a matriz
	preenche(l,c,p);
	
	//imprimindo a matriz
	imprime(l,c,p);
	
	
	return 0;
}