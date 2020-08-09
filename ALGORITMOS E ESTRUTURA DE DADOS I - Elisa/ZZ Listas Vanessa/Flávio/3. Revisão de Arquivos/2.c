#include <stdio.h>

FILE *arquivo;

int main () {
	int i=0, mat[15], nota[15], media;
	arquivo = fopen("2.txt", "r");
	
	while((fscanf(arquivo, "%d %d\n", &mat[i], &nota[i])) != EOF) {
		media += nota[i];
		i++;
	}
	printf("A media das notas e %d\n", media/15);
	
	return 0;
}
