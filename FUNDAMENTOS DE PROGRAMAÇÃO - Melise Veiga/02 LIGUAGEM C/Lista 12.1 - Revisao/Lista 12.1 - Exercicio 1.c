#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*1. Considere o tipo tCliente definido abaixo. Escreva funções para:
a. Ler do teclado o código e o nome do cliente e salvar as informações em um arquivo.
b. Imprimir os dados dos clientes armazenados no arquivo.
c. Dado um nome de cliente, procurar o nome no arquivo e imprimir o código do cliente.
struct tAluno {
int codigo;
char nome[50];
} */

typedef struct cliente
{
    int cod;
    char nome[51];
} tCliente;

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    tCliente a;
    int i;
    FILE *arq;
    arq = fopen("ArquivoCliente.txt","w+");

    if (arq == NULL){
        printf ("\nArquivo inexistente!\n");
        exit(1);
    }
    else{
        printf ("Digite nome: ");
        scanf (" %[^\n]",a.nome);
        printf ("Digite código: ");
        scanf ("%d",&a.cod);
        fprintf (arq, "\n Nome: %s\n Código: %d\n",a.nome, a.cod);

        i=1;
        rewind(arq);

        printf ("\n [%d] Nome: %s\n Código: %d\n",i++, a.nome, a.cod);
        fscanf (arq, "%s %d",a.nome, &a.cod);
        fclose(arq);
    }
    char nom[51];
    printf ("\n\n Digite um nome de cliente: ");
    scanf (" %[^\n]",nom);

    if (strcmp(nom, a.nome)==0)
        printf ("\n O código do nome é: %d\n",a.cod);

    return 0;
}
