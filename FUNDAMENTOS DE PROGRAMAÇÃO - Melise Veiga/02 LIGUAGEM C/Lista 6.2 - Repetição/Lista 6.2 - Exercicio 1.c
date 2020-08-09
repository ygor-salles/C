#include<stdio.h>

/*Escreva um programa que exiba o menu abaixo e retorne o valor de acordo com a opção desejada. Caso o usuário escolher uma opção diferente das apresentadas, exibir uma mensagem informando o erro.
Digite a opção:
1- Multiplicar x e y
2- Dividir x e y
3- Sair do programa  */

int main ()
{

	float x, y, resultado;
	int op;

	printf ("DIgite o valor de x: ");
	scanf ("%f",&x);
	printf ("DIgite o valor de y: ");
	scanf ("%f",&y);

	printf ("\n1 - Multiplicar x e y \n\n");
	printf ("2 - Divividir x e y \n\n");
	printf ("3 - Sair do programa \n\n");

	printf ("Digite uma das opcoes acima: ");
	scanf ("%d",&op);

    if ((op<1) || (op>3)){
        printf ("\n\n Error, necessario digitar uma opcao valida!! \n\n");
    }else{
	switch (op){
 case 1:
	resultado = x * y;
	printf ("\n\n O produto de x e y eh: %.2f\n\n",resultado);
	break;
 case 2:
	resultado = x / y;
	printf ("\n\n A divisao de x e y eh: %.2f\n\n",resultado);
	break;
 case 3:
    return 0;
	}
    }
    return 0;
}
