
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "pilha.h"

// funcao principal
int main(void) {
  
  Pilha *t1, *t2, *t3;
  char letra;
  int cont = 0;

  t1 = criar_pilha();
  t2 = criar_pilha();
  t3 = criar_pilha();

  empilhar(t1,'A');
  empilhar(t1,'E');
  empilhar(t1,'I');
  empilhar(t1,'O');
  empilhar(t1,'U');

  imprimir(t1,t2,t3);
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t3);
  empilhar(t2,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t1,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t2);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  letra = desempilhar(t1);
  empilhar(t3,letra);
  imprimir(t1,t2,t3);
  cont++;
  printf("\n------------------------------\n");

  printf("\nTotal de movimentos: %d\n", cont);

  liberar_pilha(t1);
  liberar_pilha(t2);
  liberar_pilha(t3);
  
  
  printf("\nFinalizando...\n");
  return 0;
}
