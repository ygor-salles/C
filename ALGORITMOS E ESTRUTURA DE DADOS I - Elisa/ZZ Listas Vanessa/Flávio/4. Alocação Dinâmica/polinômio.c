#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mostrar_polinomio (int n, float *c, char p) {
	int i ;
	printf("\n%c(x) = %.1f",p,c[0]);
	for(i=1; i<=n; i++) {
		if (c[i] > 0) {
			printf(" +");
		}
		printf(" %.1f(x)",c[i]);
		if (i>1) {
			printf("^%d",i);
		}	
	}
	return;
}


int main () {
	setlocale(LC_ALL, "portuguese");
	int n, i;
	float *c;
	char p;
	
	printf("Digite o nome do polinômio: ");
	scanf(" %c", &p);
	printf("Digite o número de graus: ");
	scanf("%d", &n);
	c = (float *) malloc((n+1)*sizeof(float));
		if (!c) {
			printf("Erro ao alocar a memória\n");
			return 1;
		}
	
	for(i=0; i<=n; i++) {
		printf("Digite o coeficiente %d: ", i+1);
		scanf("%f", &c[i]);
	}
	mostrar_polinomio (n,c,p);
	free(c);
		
	
	return 0;
}
