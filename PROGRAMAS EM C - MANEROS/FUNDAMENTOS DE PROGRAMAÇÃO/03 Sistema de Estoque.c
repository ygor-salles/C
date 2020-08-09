#include<stdio.h>
#include<stdlib.h>

/* Faça um programa para controlar o estoque de mercadorias de uma empresa. Inicialmente, o programa deverá
preencher dois vetores com dez posições cada, onde o primeiro corresponde ao código do produto e o
segundo, ao total desse produto em estoque. Logo após, o programa deverá ler um conjunto indeterminado
de dados contendo o código de um cliente e o código do produto que ele deseja comprar, juntamente com a
quantidade. Código do cliente igual a zero indica fim do programa. O programa deverá verificar:
° se o código do produto solicitado existe. Se existir, tentar atender ao pedido; caso contrário, exibir
mensagem Código inexistente;
° cada pedido feito por um cliente só pode ser atendido integralmente. Caso isso não seja possível,
escrever a mensagem Não temos estoque suficiente dessa mercadoria. Se puder atendê-lo, escrever
a mensagem Pedido atendido. Obrigado e volte sempre;
° efetuar a atualização do estoque somente se o pedido for atendido integralmente;
° no final do programa, escrever os códigos dos produtos com seus respectivoss etoques já atualizados. */

int main ()
{
    int cod_prod[10], total_est[10], cod_cliente, prod_atual, est_atual,  i, j, teste_prod;
    printf ("Cadastre uma sequencia de 10 codigos de produtos e a qtd deles no estoque\n\n");

/*Primeiramente devemos cadastrar os cod dos produtos e suas respectivas quantidades no estoque */
    for (i=0; i<10; i++){
        printf ("Digite o codigo do produto: ");
        scanf ("%d",&cod_prod[i]);
        if (i > 0) {
/*Necessário validar se o usuário não irá cadastrar codigos duplicados, para não haver conflitos. (Varrer os codigos ja digitados no loop referente)*/
            for (j=0; j<i; j++){
                while (cod_prod[i] == cod_prod[j]) {
                    printf ("Esse codigo de produto ja existe, digite outro!\n");
                    printf ("\nDigite o codigo do produto: ");
                    scanf ("%d",&cod_prod[i]);
                }
            }
        }
        printf ("Digite a quantidade de produtos no estoque: ");
        scanf ("%d",&total_est[i]);
    }
    printf ("Produtos ja cadastrados!\n");

/* Após o cadastramento, necessário a validação do codigo do cliente, sempre diferente de 0 */
    while (cod_cliente != 0){
		printf ("\nDigite o codigo do cliente: ");
		scanf ("%d",&cod_cliente);
/*Se o  cod do cliente for igual a 0 ele ja sai do laço e mostra o resultado final, senao continua com os procedimentos */
		if (cod_cliente == 0){
			break;
		}
		else{
            printf ("Digite o codigo de produto: ");
            scanf ("%d",&prod_atual);
            teste_prod = 0;
/*Necessario varrer o vetor para verificar produto digitado pelo cliente corresponde a algum produto cadastrado*/
            for (i=0; i<10; i++){
                if (prod_atual == cod_prod[i]){
/*A variável test_prod servirá de validação para ver se o cod digitado pelo cliente entrou no laço. Caso tenha entrado sua saída do laço será 1 caso não será 0 */
                    teste_prod = 1;
/*Necessário validar se o cliente não irá digitar uma quantidade negativa para retirar do estoque, o que não seria possível*/
                    do{
                        printf ("Digite a quantidade a retirar: ");
                        scanf ("%d",&est_atual);
                        } while (est_atual < 0);
                    if (est_atual <= total_est[i]){
                        printf ("Pedido atendido! Obrigado, volte sempre!\n");
                        total_est[i] = total_est[i]-est_atual;
                    }else{
                        printf ("Nao temos estoque suficiente dessa mercadoria!\n");
                    }
                }
            }
/*Se a saída da variável test_prod for igual a 0, exibira a mensagem, senao não exibira nada */
            if (teste_prod == 0) {
                printf ("Codigo Inexistente!\n");
            }
		}
    }

/*Após o cod do cliente for igual a zero, exibirá o estoque atualizado e finalizará o programa*/
    printf ("|-------------------------------------------|\n");
	printf ("|---- COD. PRODUTO ----|---- QUANTIDADE ----|\n");
	for (i = 0; i < 10; i++){
		printf ("       %d                     %d    \n", cod_prod[i], total_est[i]);
	}
	printf ("|--------------------------------------------|\n");
	system ("pause");
	return 0;
}
