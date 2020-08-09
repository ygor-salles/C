#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* O Depto de Meio Ambiente de um país mantém 2 listas de indústrias conhecidas
por serem altamente poluentes. Os resultados de várias medidas são combinados para formar
o que é chamado de índice de poluição. Isto é controlado regularmente.
Normalmente os valores ficam entre 0.05 e 0.25. Porém, se o valor atingir 0.30,
 as indústrias da lista A serão chamadas a suspender as operações até que os valores
retornem ao intervalo normal. Se o índice atingir 0.40, as indústrias da lista B serão notificadas também.
Se o índice exceder 0.50, indústrias das 2 listas serão avisadas.
Preparar um programa em C para ler o índice de poluição de 100 cidades e indicar quais
listas deverão ser avisadas. */

int main ()
{

	float indice;
	int i, a=0, b=0, aEb=0;

	for (i=1; i<=100; i++){
		printf ("\n\n Digite o indice de poluicao de sua industria: ");
		scanf ("%f",&indice);

		if ((indice>=0.30) && (indice<0.40)){
			printf ("\n A lista A deve ser avisada! \n");
			a++;
		}
		else if ((indice>=0.40) && (indice<0.50)){
			printf ("\n A lista B deve ser avisada! \n");
			b++;
		}
		else if (indice>=0.50){
			printf ("\n A lista A e B deve ser avisada! \n");
			aEb++;
		}

	}
	printf ("\n\nTotal de notificacoes para a lista A: %d\n\n",a);
	printf ("Total de notificacoes para a lista B: %d\n\n",b);
	printf ("Total de notificacoes para a lista A e B: %d\n\n",aEb);

	return 0;
}