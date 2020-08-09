Elabore um programa que leia 5 notas, calcule a media e escreva as notas maiores que a media

int main ()
{
	int i; float media=0, num, vet[5];
	for (i=0; i<5; i++){
		printf ("Escreva num: ");
		scanf("%f",&vet[i]);
		media = media + vet[i];
	}
	media = media/5;
	for (i=0; i<5; i++){
		if (media<vet[i]);
		printf ("%f\n",vet[i]);
	}
}


vet[5] é o tamanho do vetor, 5 posições na memória:

0, 1, 2, 3, 4. Por isso o for deve ir de 0 a 4 (<5)