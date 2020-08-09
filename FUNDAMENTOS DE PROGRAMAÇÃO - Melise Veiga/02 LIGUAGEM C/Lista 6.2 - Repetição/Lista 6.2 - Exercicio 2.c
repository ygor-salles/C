#include<stdio.h>

/*Faça um programa que leia o salário de um funcionário, calcule o salário reajustado de acordo com a regra abaixo e imprima o novo salário.
• salários até 300, reajuste 50%
• salários maiores que 300, reajuste 30% */


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
