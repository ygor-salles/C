#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void preenche (int n, int *A) {
	int i;
	for(i=0; i<n; i++) {
		printf("Digite o valor de A%d: ",i+1);
		scanf("%d", &A[i]);
	}
}

void realoca (int x, int *A, int n) {
	int i, aux, qtd, y=n-1;
	for(i=0; i<n; i++){
		if (x == A[i]) {
			aux = A[i];
			A[i] = A[y];
			A[y] = aux;
			y = y-1;
		}
	}	
}

void print (int n, int *A) {
	int i;
	printf("\n");
	for(i=0; i<n; i++) {
		printf("A%d: %d\n", i+1, A[i]);
	}
}


int main () {
	setlocale(LC_ALL,"portuguese");
	
	//declaração de variaveis
	int i, n, elemento, *A, qtd=0, x;
	
	//ler o tamanho de A
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	//Alocar A
	A = (int *) malloc(n*sizeof(int));
	if (!A) {
		printf("Erro ao alocar\n");
		return 1;
	}
	
	//Preencher A
	preenche(n,A);
	
	//aparecer na tela antes
	print(n,A);
	
	//Realoca A
	printf("\nDigite um número: ");
	scanf("%d", &x);
	realoca(x,A,n);
	
	//aparecer na tela depois
	print(n,A);
	
	free(A);
	
	
	
	
	
	
	
	return 0;
}
