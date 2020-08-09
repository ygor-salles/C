#include <stdio.h>
#include <string.h>

/*5. Escreva um programa em C que recebe uma cadeia de caracteres de tamanho máximo 100 e
retorna 1 se esta cadeia é um palíndromo e zero caso contrário. Uma palavra é dita ser
palíndromo se a sequência de seus caracteres da esquerda para a direita é igual à sequência
de seus caracteres da direita para a esquerda. Ex.: arara.*/

int main (){
	char string1[101], string2[101];
	int i, x;

	printf ("Entre com a cadeia de carater: \n");
	scanf (" %[^\n]", string1);
	x = strlen (string1);
	printf ("Quantidade de caracter dessa string e= %d\n", x);

	for (i=0;i<x;i++)
		string2[i]=string1[x-i-1];
		string2[x]= '\0';
		printf ("Palavra: %s\n", string2);
		if (strcmp(string1,string2)==0)
			printf("1\n");
		else
			printf("0\n");
    
    return 0;
}
