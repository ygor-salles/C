#include<stdio.h>

/*Matriz Quadrada - Uri 1557 */

int main ()
{
  int n, k=1, i, j;
  printf ("Digite o valor de N: ");
  scanf ("%d",&n);
  if (n<0 || n>15){
    printf ("Entrada de dados invalida!");
    return 0;
  }
  int mat[n][n];
  while (n != 0){
    k = 1;
    for (i=0; i<n; i++){
      for (j=0; j<n; j++){
        if (j==0){
          mat[i][j] = k;
          printf (" %d",mat[i][j]);
        }else{
          mat[i][j] = mat[i][j-1] *2;
          printf (" %d",mat[i][j]);
        }
      }
      k = k*2;
      printf ("\n");
    }
    printf ("\n");
    printf ("Digite o valor de N: ");
    scanf ("%d",&n);
    if (n<0 || n>15){
      printf ("Entrada de dados invalida!\n");
    }
  }
  printf ("\nFim do programa\n");
  return 0;
}