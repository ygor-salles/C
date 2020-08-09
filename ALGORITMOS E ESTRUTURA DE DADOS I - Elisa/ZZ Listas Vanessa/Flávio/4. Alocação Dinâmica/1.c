#include <stdio.h>

#include <locale.h>

int main () {
	setlocale(LC_ALL, "portuguese");
	int *x, i, n;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	x = (int *) malloc(n*sizeof(int));
		if (!x) {
			printf("Erro ao alocar a memória\n");
			return 1;
		}
	printf("\nLixo de memória");
	printf("\n");		
	for(i=0; i<n; i++) {
		printf("Vetor %d: %d\n", i+1, x[i]);
	}
	printf("\n");
	for(i=0; i<n; i++) {
		printf("Digite o vetor %d: ", i+1);
		scanf("%d", &x[i]);
	}	
	printf("\n");
	for(i=0; i<n; i++) {
		printf("Vetor %d: %d\n", i+1, x[i]);
	}	
	return 0;
}
