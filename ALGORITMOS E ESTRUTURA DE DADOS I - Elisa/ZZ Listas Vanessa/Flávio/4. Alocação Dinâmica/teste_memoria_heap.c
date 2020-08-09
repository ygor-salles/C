#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL, "portuguese");
	int *p, n, i;
	
	/*printf("Digite o número de posições: ");
	scanf("%d", &n);*/
	p = (int*) malloc((200)*sizeof(int));
		if (!p) {
			printf("Erro ao alocar a memória\n");
			return 0;
		}
		for (i=0; i<50; i++){
			printf("%d\n", p[i]);
		}
		
	p = (int*) calloc((200),sizeof(int));	
		if (!p) {
			printf("Erro ao alocar a memória\n");
			return 0;
		}
		printf("\n");
		for (i=0; i<50; i++){
			printf("%d\n", p[i]);
		}
	/*while(1==1) {
	p = (int*) malloc((200)*sizeof(int));
		if (!p) {
			printf("Erro ao alocar a memória\n");
			return 0;
		}
		
	free(p);	
	printf("Digite o número de posições: ");
	scanf("%d", &n);
	}*/
	
	
	return 0;
}
