#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa que preencha um vetor com dez n�meros inteiros e um segundo vetor com cinco n�meros
inteiros, calcule e mostre dois vetores resultantes. O primeiro vetor resultante ser� composto pela
soma de cada n�mero par do primeiro vetor somado a todos os n�meros do segundo vetor. O segundo
vetor resultante ser� composto pela quantidade de divisores que cada n�mero �mpar do primeiro vetor
tem no segundo vetor. */

int main ()
{
   int vet1[10], vet2[5], res1[10], res2[10], i, j, c1, c2, k=0, l=0;

/* Primeiramente necess�rio preencher os vetores 1 e 2 */
   printf ("Primeiro Vetor\n");
   for (i=0; i<10; i++){
        printf ("Digite um numero: ");
        scanf ("%d",&vet1[i]);
   }
   printf ("\nSegundo Vetor\n");
   for (i=0; i<5; i++){
        printf ("Digite um numero: ");
        scanf ("%d",&vet2[i]);
   }

/*Realizar a soma do vetor resultante 1*/
   for (i=0; i<10; i++){
/*Necess�rio varrer o primeiro vetor e encontrar todos os pares dele para somar com todos do 2� vetor, ser� preciso de um auxiliar*/
        if (vet1[i]%2 == 0){
            c1 = vet1[i];
            for (j=0; j<5; j++){
                c1 = c1+vet2[j];
            }
            res1[k] = c1;
            k++;
        }
/*O vetor resultante 2 corresponde a todos �mpares do vetor 1 e quantas vezes o mesmo dividi por todos valores do vetor 2*/
        else{
            c2 = 0;
            for (j=0; j<5; j++){
                if (vet1[i] % vet2[j] == 0){
                    c2++;
                }
            }
            res2[l] = c2;
            l++;
        }
   }

/*Ao exibir o resultado ser� necess�rio exibir um a um */
   printf ("Para a leitura dos vetores considere (POSICAO : VALOR)\n\n");
	printf ("Vetor 1 = {\n");
	for (i = 0; i < k; i++){
		printf ("%d : %d\n",  i, res1[i]);
	}
	printf ("}\n\n");
	printf ("Vetor 2 = {\n");
	for (i = 0; i < l; i++){
		printf ("%d : %d\n",  i, res2[i]);
	}
	printf ("}\n\n");
	return 0;
}
