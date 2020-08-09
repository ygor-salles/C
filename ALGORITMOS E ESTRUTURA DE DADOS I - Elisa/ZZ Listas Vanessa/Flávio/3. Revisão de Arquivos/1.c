#include <stdio.h>

FILE *arquivo;

int main () {
	int i=0, cod[10], preco[10], soma = 0;
	
	arquivo = fopen("1.txt", "r");
	while ((fscanf(arquivo, "%d %d\n", &cod[i], &preco[i])) !=EOF) {
		soma += preco[i];
		i++;
	}
	fclose(arquivo);
	printf("A soma dos produtos e %d\n", soma);
		
	return 0;
}
