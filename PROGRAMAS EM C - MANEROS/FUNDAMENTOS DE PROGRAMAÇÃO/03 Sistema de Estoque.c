#include<stdio.h>
#include<stdlib.h>

/* Fa�a um programa para controlar o estoque de mercadorias de uma empresa. Inicialmente, o programa dever�
preencher dois vetores com dez posi��es cada, onde o primeiro corresponde ao c�digo do produto e o
segundo, ao total desse produto em estoque. Logo ap�s, o programa dever� ler um conjunto indeterminado
de dados contendo o c�digo de um cliente e o c�digo do produto que ele deseja comprar, juntamente com a
quantidade. C�digo do cliente igual a zero indica fim do programa. O programa dever� verificar:
� se o c�digo do produto solicitado existe. Se existir, tentar atender ao pedido; caso contr�rio, exibir
mensagem C�digo inexistente;
� cada pedido feito por um cliente s� pode ser atendido integralmente. Caso isso n�o seja poss�vel,
escrever a mensagem N�o temos estoque suficiente dessa mercadoria. Se puder atend�-lo, escrever
a mensagem Pedido atendido. Obrigado e volte sempre;
� efetuar a atualiza��o do estoque somente se o pedido for atendido integralmente;
� no final do programa, escrever os c�digos dos produtos com seus respectivoss etoques j� atualizados. */

int main ()
{
    int cod_prod[10], total_est[10], cod_cliente, prod_atual, est_atual,  i, j, teste_prod;
    printf ("Cadastre uma sequencia de 10 codigos de produtos e a qtd deles no estoque\n\n");

/*Primeiramente devemos cadastrar os cod dos produtos e suas respectivas quantidades no estoque */
    for (i=0; i<10; i++){
        printf ("Digite o codigo do produto: ");
        scanf ("%d",&cod_prod[i]);
        if (i > 0) {
/*Necess�rio validar se o usu�rio n�o ir� cadastrar codigos duplicados, para n�o haver conflitos. (Varrer os codigos ja digitados no loop referente)*/
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

/* Ap�s o cadastramento, necess�rio a valida��o do codigo do cliente, sempre diferente de 0 */
    while (cod_cliente != 0){
		printf ("\nDigite o codigo do cliente: ");
		scanf ("%d",&cod_cliente);
/*Se o  cod do cliente for igual a 0 ele ja sai do la�o e mostra o resultado final, senao continua com os procedimentos */
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
/*A vari�vel test_prod servir� de valida��o para ver se o cod digitado pelo cliente entrou no la�o. Caso tenha entrado sua sa�da do la�o ser� 1 caso n�o ser� 0 */
                    teste_prod = 1;
/*Necess�rio validar se o cliente n�o ir� digitar uma quantidade negativa para retirar do estoque, o que n�o seria poss�vel*/
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
/*Se a sa�da da vari�vel test_prod for igual a 0, exibira a mensagem, senao n�o exibira nada */
            if (teste_prod == 0) {
                printf ("Codigo Inexistente!\n");
            }
		}
    }

/*Ap�s o cod do cliente for igual a zero, exibir� o estoque atualizado e finalizar� o programa*/
    printf ("|-------------------------------------------|\n");
	printf ("|---- COD. PRODUTO ----|---- QUANTIDADE ----|\n");
	for (i = 0; i < 10; i++){
		printf ("       %d                     %d    \n", cod_prod[i], total_est[i]);
	}
	printf ("|--------------------------------------------|\n");
	system ("pause");
	return 0;
}
