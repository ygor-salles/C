
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "pilha.h"

// funcao principal
int main(void) {
  
  Pilha *t1;
  int *x, *y, *res, soma = 0;

  t1 = criar_pilha();

  int *m = (int*)malloc(9 * sizeof(int)); 
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      m[i*3+j] = 3;
    }
  }

  empilhar(t1,m);

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      m[i*3+j] = 2;
    }
  }

  empilhar(t1,m);

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      m[i*3+j] = 1;
    }
  }

  empilhar(t1,m);
  imprimir(t1);

  printf("\n1º Multiplicação\n\n");

  x = (int*)malloc(9 * sizeof(int));
  x = desempilhar(t1);

  y = (int*)malloc(9 * sizeof(int));
  y = desempilhar(t1);

  res = (int*)malloc(9 * sizeof(int));

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      res[i*3+j] = 0;
      for(int k = 0; k < 3; k++){
        soma += x[i*3+k] * y[k*3+j];
      }
      res[i*3+j] = soma;
      soma = 0;
    }
  }

  empilhar(t1,res);
  imprimir(t1);

  printf("\n2º Multiplicação\n\n");

  x = desempilhar(t1);
  y = desempilhar(t1);

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      res[i*3+j] = 0;
      for(int k = 0; k < 3; k++){
        soma += x[i*3+k] * y[k*3+j];
      }
      res[i*3+j] = soma;
      soma = 0;
    }
  }

  empilhar(t1,res);
  imprimir(t1);

  liberar_pilha(t1);
  free(m);
  free(x);
  free(y);
  free(res);
  
  printf("\nFinalizando...\n");
  return 0;
}
