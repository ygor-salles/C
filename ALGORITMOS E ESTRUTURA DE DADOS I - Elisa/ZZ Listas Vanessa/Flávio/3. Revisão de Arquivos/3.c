#include <stdio.h>
#include <locale.h>
#include <string.h>

FILE *arquivo;

typedef struct censo {
	float salario;
	int idade, filhos;
	char sexo;
} tcenso;
	tcenso dados[10];
	
int main () {
	setlocale (LC_ALL, "portuguese");
	int i, midade = 0, mfilhos, menorid = 0, aux[2] = {0,0};
	float maiorsal=0, msal;
	for (i=0; i<3; i++) {
		printf("Digite seu salário: ");
		scanf("%f", &dados[i].salario);
		printf("Digite sua idade: ");
		scanf("%d", &dados[i].idade);
		printf("Digite seu sexo (M ou F): ");
		scanf(" %c", &dados[i].sexo);
		printf("Digite quantos filhos você tem: ");
		scanf("%d", &dados[i].filhos);
		printf("\n");
		
		if (dados[i].salario > maiorsal) {
			maiorsal = dados[i].salario;
		}
		if (menorid > dados[i].idade) {
			menorid = dados[i].idade;
		}
		if (dados[i].sexo == 'F' && dados[i].salario < 500) {
			aux[1] ++;
			midade = (midade +dados[i].idade) / aux[1];
		}
		
		aux[2] ++;
		msal = (msal + dados[i].salario) / aux[2];
		mfilhos = (mfilhos + dados[i].filhos) / aux[2];
	}
	
	printf("Média de Idade: %d\n", midade);
	printf("Média de Salário: %.2f\n", msal);
	printf("Média de Filhos: %d\n", mfilhos);
	printf("Maior Salário: %.2f\n", maiorsal);
	printf("Menor Idade: %d\n", menorid);
		
	
	arquivo = fopen("censo.dat", "w");
	
	
	
	fclose (arquivo);
	return 0;
}
