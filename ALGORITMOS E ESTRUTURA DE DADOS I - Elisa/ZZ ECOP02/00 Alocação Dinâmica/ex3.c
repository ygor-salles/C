#include <stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct st_livros{
  char nome[30];
  char autor[30];
  int ano;
  char editor[30];
  char classificacao[30];
}st_livros;

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese");
    st_livros *v;
    int i;

    v = (st_livros*) malloc(10*sizeof(st_livros));
 

    printf ("\nPreencha o vetor: \n");
    for(i=0; i<10; i++){
      printf("Digite nome do livro: ");
      scanf (" %[^\n]",v[i].nome);
      printf("Digite nome do autor: ");
      scanf (" %[^\n]",v[i].autor);
      printf("Digite o ano: ");
      scanf ("%d",&v[i].ano);
      printf("Digite nome do editor: ");
      scanf (" %[^\n]",v[i].editor);
      printf("Digite a classificação: ");
      scanf (" %[^\n]",v[i].classificacao);
      printf("\n");
    }

    for(i=0; i<10; i++){
        printf("\nNome: %s",v[i].nome);
        printf("\nAutor: %s",v[i].autor);
        printf("\nAno: %d",v[i].ano);
        printf("\nEditor: %s",v[i].editor);
        printf("\nClassificacao: %s\n",v[i].classificacao);
    }

     free(v);

    return 0;
}
