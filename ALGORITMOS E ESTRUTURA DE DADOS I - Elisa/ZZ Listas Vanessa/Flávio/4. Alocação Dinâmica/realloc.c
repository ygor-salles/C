#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL, "portuguese");
	int i, *vet; 
	
	vet = (int*) malloc((5)*sizeof(int));
		if (!vet) {
			printf("Erro ao alocar a memória\n");
			return 0;
		}
		for (i=0; i<5; i++){
			vet[i] = rand()%100;
		}
		

	
	return 0;
}
