#include <stdio.h>
#include <locale.h>

FILE *arquivo;

struct fatorial {
	int numero, fat;
};
	struct fatorial tfat[10];
	
void calculafat() {
	int i, j, fatt = 1;
	for (i=0; i<30; i++){
		for(j=1;j<=tfat[i].numero; j++) {
			fatt = fatt * j;
			tfat[i].fat = fatt;
			}
		fatt = 1;
		}
	}	

void imprimevetor(){
	int i;
	printf("\n");
	for (i=0; i<30; i++) {
		printf("A fatorial de %d é %d\n",tfat[i].numero,tfat[i].fat);
	}
}

int verificavalor (int x, int num) {
	int i;
	for(i=0; i<x; i++) {
		if (tfat[i].fat > num) {
			return 1;
		}
	}
	return 0;
}
	
	
int main () {
	setlocale(LC_ALL, "portuguese");
	int x, num, verifica, i=0;
	

	/*imprimevetor(x);
	printf("\nDigite um número: ");
	scanf("%d", &num);
	verifica = verificavalor(x, num);
	if (verifica == 1) {
		printf("\nExiste fatorial maior que %d\n", num);
	}
	else if (verifica == 0) {
		printf("\nNão existe fatorial maior que %d\n", num);
	}*/ 
	//leitura dos arquivos//
	arquivo = fopen("entrada.txt", "r");
	if (!arquivo) {
		printf("\nErro ao abrir o arquivo\n");
		return 0;
	}
	while((fscanf(arquivo,"%d\n",&tfat[i].numero))!=EOF){
		i++;
	}
	calculafat();
	imprimevetor();
	fclose(arquivo);	
	return 0;
}
