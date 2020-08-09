#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* O Depto de Meio Ambiente de um pa�s mant�m 2 listas de ind�strias conhecidas
por serem altamente poluentes. Os resultados de v�rias medidas s�o combinados para formar
o que � chamado de �ndice de polui��o. Isto � controlado regularmente.
Normalmente os valores ficam entre 0.05 e 0.25. Por�m, se o valor atingir 0.30,
 as ind�strias da lista A ser�o chamadas a suspender as opera��es at� que os valores
retornem ao intervalo normal. Se o �ndice atingir 0.40, as ind�strias da lista B ser�o notificadas tamb�m.
Se o �ndice exceder 0.50, ind�strias das 2 listas ser�o avisadas.
Preparar um programa em C para ler o �ndice de polui��o de 100 cidades e indicar quais
listas dever�o ser avisadas. */

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