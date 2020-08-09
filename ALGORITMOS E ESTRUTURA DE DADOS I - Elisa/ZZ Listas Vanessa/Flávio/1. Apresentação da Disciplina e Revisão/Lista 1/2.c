#include <stdio.h>

void imprimir(int mat[10][10], int m) {
	int i, j;
	for(i=0; i<m; i++) {
		for(j=0; j<m; j++) {
			printf("%d  ", mat[i][j]);
		}
		printf("\n");
	}
}

int main () {
	int m, i, j, mat[10][10], x=0, y, z;
	
	printf("Digite o tamanho da matriz: ");
	scanf("%d", &m);
	for(i=0; i<m; i++) {
		for(j=0; j<m; j++) {
			printf("Digite o valor de A%d B%d: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}	
	imprimir(mat,m);
	for(i=0; i<m; i++) {
		for(j=0; j<m; j++) {
			if (mat[i][j]>x) {
				x = mat[i][j];
				y = i;
			}
		}
	}	
	z = mat[y][0];
	for (j=0; j<m; j++) {
		if(mat[y][j] < z) {
			z = mat[y][j];
		}
	}
	printf("\nO menor elemento e %d\n", z);
	
	return 0;
}
