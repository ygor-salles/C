#include<stdio.h>

/*Fa�a um programa que leia o sal�rio de um funcion�rio, calcule o sal�rio reajustado de acordo com a regra abaixo e imprima o novo sal�rio.
� sal�rios at� 300, reajuste 50%
� sal�rios maiores que 300, reajuste 30% */


int main ()
{
	float salario, novoSal;

	printf ("Digite o seu salario: ");
	scanf ("%f",&salario);

	if (salario<=300){
		novoSal = salario+(salario*0.50);
		printf ("\n\n O seu novo salario eh de: %.2f\n\n",novoSal);
	}
	else{
		novoSal = salario+(salario*0.30);
		printf ("\n\n O seu novo salario eh de: %.2f\n\n",novoSal);
	}
	return 0;
}
