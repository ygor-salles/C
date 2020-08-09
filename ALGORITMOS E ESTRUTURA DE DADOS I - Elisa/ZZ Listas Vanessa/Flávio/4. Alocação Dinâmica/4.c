#include <stdio.h>
#include <stdlib.h>

void criptografar (int n, char *cadeia) {
	int i;
	for(i=0; i<n; i++) {
		if(cadeia[i] =='a' || cadeia[i] == 'e' || cadeia[i] == 'i' || cadeia[i] == 'o' || cadeia[i] == 'u') {
			cadeia[i] = '*' ;
		}
	}	
}

int main () {
	//declaração de variaveis
	int n, i;
	char *cadeia;
	
	// ler o tamanho da cadeia
	printf("Digite o tamanho: ");
	scanf("%d", &n);
	
	//alocar o vetor
	cadeia = (char *) malloc(n*sizeof(char));
		if(!cadeia){
			printf("Erro ao alocar\n");
			return 1;
		}
	
	//ler a string
	printf("\nDigite a cadeia: ");
	scanf(" %[^\n]", cadeia);
	printf("%s\n", cadeia);	
	
	//criptografar
	criptografar(n,cadeia);
	printf("\nCriptografado: %s\n", cadeia);
	
	//libera memória	
	free(cadeia);
	return 0;
}
