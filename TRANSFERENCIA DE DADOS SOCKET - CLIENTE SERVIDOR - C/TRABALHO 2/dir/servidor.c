//INCLUSAO DE BIBLIOTECAS
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h> /* close() */
#include <stdlib.h>
#include <string.h> /* memset() */

//DEFINICAO DE CONSTANTES
#define SUCESSO_RECEPCAO 1
#define ERRO_PACOTE 0
#define PACOTE_DUPLICADO -1
#define LOCAL_SERVER_PORT 1501
#define MAX_MSG 650

//---------------------------------------ESTRUTURAS NECESSARIAS---------------------------------------//

/* DEFINICAO DE UM PACOTE */
typedef struct package
{
	int numsequencial;				//Armazena o numero sequencial, identificador do pacote
	long int check_sum;				//Armazena o checksum do pacote
	char segmento[512];				//Armazena um segmento do arquivo que sera enviado
	int flag;						//Valor 1 = CONTINUAR | valor 0 = FINALIZAR
	int dim;						//Armazena o tamanho do segmento em Bytes

} pacote ;

/* DEFINICAO DE UMA RESPOSTA DE SERVIDOR */
typedef struct reply
{
	int status;				// 1 indica sucesso, 0 falha,-1 pacote ja recebido
	int num_sequencial;		//Numero sequencial do pacote (indicador)
}resposta;

//---------------------------------------CABECALHOS DAS FUNCOES---------------------------------------//

void responder_cliente(int status_resposta,int num_pacote,int socket,struct sockaddr_in *cliAddr);
int receber_pacote(pacote *pct,int sock,struct sockaddr_in * cliAddr);
void gerar_socket(int *sock,struct sockaddr_in *servAddr);
long int checksum(char segmento[],int dimensao);
FILE * gerar_arquivo(char *arq);

//---------------------------------------IMPLEMENTACAO DAS FUNCOES---------------------------------------//

/* CALCULA CHECKSUM BASEANDO-SE NO VALOR INT DO BYTE ARMAZENADO */
long int checksum(char segmento[],int dimensao)
{
	long int soma;
	int asc,i;

	//Inicializar variavel que armazena a soma
	soma = 0;

	//Percorrer cadeia de caracteres
	for(i=0 ; i<dimensao ; i++)
	{
		asc = 0;
		asc = (int) segmento[i];		//Obter valor int correspondente ao byte
		if(asc >= 100 || asc <= -100)
			asc	= asc/20;				//Representar o bytepor seu valor dividido por 20
		else
			asc = asc/5;				//Representar o byte por seu valor dividido por 5

		soma += asc*i;					//Adicionar valor do byte na soma
	}

	//Devolver valor total do checksum
	return soma;
}

/* GERAR ARQUIVO DE SAIDA */
FILE * gerar_arquivo(char *arq)
{
	FILE *arquivo;

	//Abrir arquivo em modo de escrita binaria
	arquivo = fopen(arq,"wb");
	//Verificar se o arquivo nao foi aberto
	if(!arquivo)
	{
		printf("[ERRO]: Falha ao abrir arquivo! Execucao encerrada....");
		exit(1);
	}

	return arquivo;
}

/* CRIAR SOCKET E LIGAR PORTA PARA RECEPCAO */
void gerar_socket(int *sock,struct sockaddr_in *servAddr)
{
	int check;

	//Criar socket e verificar se foi criado com sucesso
	*sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(*sock < 0)
	{
		printf("\n[ERRO]: Nao foi possivel abrir socket.. \n");
	    exit(1);
	}

	//Ligar porta local do servidor
	servAddr->sin_family = AF_INET;
	servAddr->sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr->sin_port = htons(LOCAL_SERVER_PORT);
	check = bind (*sock, (struct sockaddr *) servAddr,sizeof(*servAddr));

	//Veridicar disponibilidade da porta
	if(check < 0)
	{
		printf("ERRO]: Nao foi possivel transferir utilizando porta numero %d..\n",LOCAL_SERVER_PORT);
	    exit(1);
	}

	//Mensagem de inicio ao usuario
	printf("\n\n[INFO]: esperando por dados na porta UDP %u\n",LOCAL_SERVER_PORT);
}

/* RECEBER PACOTE DO CLIENTE */
int receber_pacote(pacote *pct,int sock,struct sockaddr_in * cliAddr)
{
	int cliLen;
	int resultado;

	//Iniciar buffer
    memset(pct,0x0,sizeof(pacote)+1);

    //Receber pacote do cliente
    cliLen = sizeof(*cliAddr);
    resultado = recvfrom(sock,pct, sizeof(pacote)+1, 0,(struct sockaddr *) cliAddr, &cliLen);

    return resultado;
}

/* ENVIAR RESPOSTA DE SERVIDOR AO CLIENTE */
void responder_cliente(int status_resposta,int num_pacote,int socket,struct sockaddr_in *cliAddr)
{
	int check;
	resposta rsp;

	//Gerar pacote de resposta de servidor
    rsp.num_sequencial = num_pacote;
    rsp.status = status_resposta;

    //Enviar resposta ao cliente
    check = -1;
    while(check < 0)
	{
		check = sendto(socket,&rsp, sizeof(resposta), 0,(struct sockaddr *) cliAddr, sizeof(*cliAddr));

		//Checar se o envio foi realizado corretamente
		if(check < 0)
		{
			printf("[ERRO]: Falha ao entregar resposta negativa de recepcao de pacote. Reenviando..\n");
		}
	}
}
//---------------------------------------FUNCAO PRINCIPAL C---------------------------------------//
int main(int argc, char *argv[])
{

 	int sock, rc, n,ultimopct =-7,ultimoarq = -7,impedir = 1;
  	long int checar;
  	struct sockaddr_in cliAddr, servAddr;
  	FILE *arquivo;
  	pacote pct;
  	resposta rsp;

  	//Criar socket e ligar porta de recepcao do servidor
  	gerar_socket(&sock,&servAddr);

  	do
  	{
  		//Iniciar recepcao de arquivo somente se o cliente mandar o nome do arquivo
  		if(impedir)
  			pct.flag = 0;

  		//Loop de recepcao de 1 arquivo
  		while(pct.flag)
		{
		  	//Aguardar pacote do cliente
		    n = receber_pacote(&pct,sock,&cliAddr);

		    //Checar se o pacote foi recebido
		    if(n<0)
		    {
		      printf("[ERRO]: Recepção com falha. Solicitando reenvio.. \n");
		      responder_cliente(ERRO_PACOTE,pct.numsequencial,sock,&cliAddr);
		    }
		    else
		    {
		    	printf("[INFO]: Pacote %d recebido do cliente..\n",pct.numsequencial);
		    	printf("[INFO]: Tamanho segmento: %3d | Checksum: %li\n",pct.dim,pct.check_sum);

		    	//Calcular checksum
		    	checar = checksum(pct.segmento,pct.dim);
		    	printf("[INFO]: Checksum de servidor .: %li\n",checar);

		    	//Verificar por checksum se o pacote chegou corretamente
		    	if( checar == pct.check_sum )
		    	{
		    		if(ultimopct == pct.numsequencial)
		    		{
		    			printf("[INFO]: Pacote duplicado recebido....");
		    			responder_cliente(PACOTE_DUPLICADO,pct.numsequencial,sock,&cliAddr);
		    		}
		    		else
		    		{

		    			//Informar ao usuario que checksum confere
			    		printf("[INFO]: Checksum positivo. Escrevendo em arquivo..\n\n");

			    		//Adicionar segmento recebido ao arquivo
				    	fwrite(pct.segmento,pct.dim,1,arquivo);

				    	//Atualizar numero do ultimo pacote recebido
				    	ultimopct = pct.numsequencial;

				    	//Responder cliente
				    	responder_cliente(SUCESSO_RECEPCAO,pct.numsequencial,sock,&cliAddr);
		    		}
		    	}
		    	else
		    	{
		    		//Informar erro de checksum e responder cliente
		    		printf("[ERRO]: Checksum negativo. Solicitando reenvio de pacote..\n\n");
			    	responder_cliente(ERRO_PACOTE,pct.numsequencial,sock,&cliAddr);
		    	}
		    }
		}

		//Fechar o ultimo arquivo recebido
		if(!impedir)
		{
			n = fclose(arquivo);
			printf("\n\n:::::..ARQUIVO RECEBIDO COM SUCESSO..::::\n\n");
		}

		//Esperar pacote do cliente
		n = receber_pacote(&pct,sock,&cliAddr);

		//Caso aconteceu algum erro de recepcao
		if(n<0)
		{
		    printf("\n\n\n[ERRO]: Recepção de solicitacao com falha. Solicitando reenvio.. \n");
		    responder_cliente(ERRO_PACOTE,pct.numsequencial,sock,&cliAddr);
		    pct.flag = 1;
		    impedir = 1;
		}
		//Caso a recepcao ocorreu bem
		else
		{
			printf("\n\n\n[INFO]: Solicitacao de conexao %d recebida do cliente..\n",pct.numsequencial);
			checar = checksum(pct.segmento,pct.dim);

			if(checar == pct.check_sum)
			{
				//Informar ao usuario que checksum confere
			    printf("[INFO]: Checksum positivo...\n\n");

			    //Validar se e' uma solicitacao de novo arquivo ou de termino
			    if(pct.flag == 0)
			    	printf("[INFO]: Solicitaçao de termino de conexao recebida...\n\n");
			    else
			    {
			    	printf("[INFO]: Arquivo a caminho: %s\n\n",pct.segmento);

			    	//Gerar o novo arquivo que sera recebido
			    	arquivo = gerar_arquivo(pct.segmento);

			    	//Permitir recepcao do arquivo
			    	impedir = 0;
			    	pct.flag = 1;
			    }

				//Atualizar numero do ultimo pacote escrito
				ultimoarq = pct.numsequencial;

				//Responder solicitacao do cliente
				responder_cliente(SUCESSO_RECEPCAO,pct.numsequencial,sock,&cliAddr);
			}
			else
			{
				printf("[ERRO]: Checksum negativo...\n\n");
				//Responder solicitacao do cliente - INFORMAR ERRO NO PACOTE
				responder_cliente(ERRO_PACOTE,pct.numsequencial,sock,&cliAddr);

				//Continuar execucao (setar flag = 1) e bloquear recepcao de arquivo
				pct.flag = 1;
				impedir = 1;
			}
		}
  	}while(pct.flag);

  	// MENSAGEM AO USUARIO, FECHAR ARQUIVO, ENCERRAR EXECUCAO
	printf("\n------------------ Transferencia(s) concluida(s) com sucesso!-------------------\n\n");
  	return 0;
}
