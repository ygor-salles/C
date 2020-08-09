#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Elabore um algoritmo para calcular e imprimir o valor dos seguintes somatórios:
• Si2 de i=1 até 20 */

int main ()
{
	int i, soma=0;

	for (i=1; i<=20; i++){
		soma = soma+(i*i);
	}
	printf ("\n\n O total do somatorio eh de: %d\n\n",soma);
	return 0;

}
