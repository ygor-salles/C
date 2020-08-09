#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Elabore um algoritmo para calcular e imprimir o valor dos seguintes somatórios:
• Si de i=1 até 20, com contador 10 (de 10 em 10) */

int main ()
{
	int i, soma=0;

	for (i=1; i<=20; i=i+10){
		soma = soma+i;
	}
	printf ("\n\n O total do somatorio eh de: %d\n\n",soma);
	return 0;

}
