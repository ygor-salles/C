#include <stdio.h>

void troca(float *p, float *q) {
	float aux;
	aux = *p;
	*p = *q;
	*q = aux;
}

int main () {
	float p,q;
	printf("Digite o valor de P: ");
	scanf("%f", &p);
	printf("Digite o valor de Q: ");
	scanf("%f", &q);
	
	troca(&p,&q);
	printf("\nP: %.0f, Q: %.0f\n", p, q); 
	
	return 0;
	
}
