#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Elabore um algoritmo para calcular e imprimir H,
sendo H = 1 + ½ + 1/3 + ¼ + ... 1/N, N deve ser fornecido pelo usuário */

int main ()
{
	float i, h=0;
	int n;

	printf ("DIgite um numero inteiro N: ");
	scanf ("%d",&n);

	for (i=1; i<=n; i++){
		h = h+(1/i);

	}
	printf ("\n\n O valor da soma H eh de: %f\n\n",h);
	return 0;

}
