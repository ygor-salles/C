//Inclusao de bibliotecas
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 		/* memset() */
#include <sys/time.h>		/* select() */

//Definicao de constantes
#define SUCESSO_RECEPCAO 1
#define ERRO_PACOTE 0
#define PACOTE_DUPLICADO -1
#define REMOTE_SERVER_PORT 1501
#define MAX_MSG 650
#define STATUS_ERRO 0
#define STATUS_SUCESSO 1

//---------------------------------------ESTRUTURAS NECESSARIAS---------------------------------------//

/* DEFINICAO DE UM PACOTE */
typedef struct package
{
	int numsequencial;				//Armazena o numero sequencial, identificador do pacote
	long int check_sum;				//Armazena o checksum do pacote
	char segmento[512];				//Armazena um segmento do arquivo que sera enviado
	int flag;						//Valor 1 = CONTINUAR | valor 0 = FINALIZAR
	int dim;
} pacote ;

/* DEFINICAO DE UMA RESPOSTA DE SERVIDOR */
typedef struct reply
{
	int status;				// 1 indica sucesso, 0 falha e -1 pacote duplicado
	int num_sequencial;		//Numero sequencial do pacote (identificador)
}resposta;

//---------------------------------------CABECALHOS DAS FUNCOES---------------------------------------//

long int checksum(char segmento[],int dimensao);
FILE * abrir_arquivo(char *local);
struct hostent * conectar_com_host(char *dadoshost);
int criar_socket(struct sockaddr_in *cliAddr,struct timeval *tempo);
void vincular_porta(struct sockaddr_in *cliAddr);
void disponibilidade_da_porta(int sock,struct sockaddr_in cliAddr);
void preparar_conexao(struct hostent *host, struct sockaddr_in *remoteServAddr);
pacote gerar_pacote(char *mensagem,int numerosequencia,int dimseg,int pflag);
pacote pacote_inicial(char *nome_arq,int numarq);
pacote pacote_final(int sequencial,int status);
int resposta_servidor(struct sockaddr_in *remoteServAddr, int sock, int numerosequencia);
void enviar_pacote(int sock,pacote *pac, struct sockaddr_in remoteServAddr);
int menu();
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

/* ABRIR ARQUIVO PARA LEITURA */
FILE * abrir_arquivo(char *local)
{
	FILE *arquivo;

   printf("\nInforme o nome do arquivo: ");
   scanf("%s",local);
   arquivo = fopen(local,"rb");

   //Verificar se o arquivo foi aberto
   if(!arquivo)
   {
   		//Se o arquivo nao for aberto a execucao e encerrada
	   	printf("\n[ERRO]: Arquivo nao aberto! Execucao encerrada..\n\n");
	   	exit(1);
   }

   return arquivo;
}

/* CONECTAR COM O HOST UTILIZANDO O IP RECEBIDO */
struct hostent * conectar_com_host(char *dadoshost)
{
	struct hostent * host;

	host = gethostbyname(dadoshost);       //retorna dados do host (host e' uma struct com varios campos)
	if(host == NULL)
	{
		//Se nao conectar a execucao e encerrada
		printf("\n[ERRO]: host desconhecido '%s' \n\n", dadoshost);
		exit(1);
	}

	//Exibir mensagem de inicio ao usuario
	printf("[INICIO]: Preparando tranferência de dados para o IP '%s'..\n\n\n",host->h_name);

	return host;
}

/* CRIAR SOCKET */
int criar_socket(struct sockaddr_in *cliAddr,struct timeval *tempo)
{
	int sock,opt;

	//Criar socket
	sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock<0) {
		printf("[ERRO]: nao foi possivel abrir socket \n");
		exit(1);
	}

	//Definir temporizador de 3/10 segundos
	tempo->tv_sec = 0;
	tempo->tv_usec = 300000;

	//Definir temporizador de recepcao
	opt = setsockopt(sock,SOL_SOCKET,SO_RCVTIMEO,(void *) tempo,sizeof(*tempo));

	//Checar se o temporizador foi definido -> 0 = bem sucedido, -1 = falha
	if(opt < 0)
		printf("[ERRO]: Falha ao definir temporizador de recepcao...");

	//Vincular porta
	vincular_porta(cliAddr);

	return sock;
}

/* VINCULAR UMA PORTA */
void vincular_porta(struct sockaddr_in *cliAddr)
{
	cliAddr->sin_family = AF_INET;
	cliAddr->sin_addr.s_addr = htonl(INADDR_ANY);
	cliAddr->sin_port = htons(0);
}

/* VERIFICAR SE A PORTA ESTA DISPONIVEL */
void disponibilidade_da_porta(int sock,struct sockaddr_in cliAddr)
{
	int resultado;

	//Tentar conectar na porta
	resultado = bind(sock, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
	//Verificar se a conexao ocorreu com sucesso
	if(resultado < 0)
	{
		printf("[ERRO]: Nao foi possivel vincular porta\n");
		exit(1);
	}
}

/* PREPARAR CONEXAO - ADICIONAR INFORMACOES IMPORTANTES SOBRE O SERVIDOR REMOTO */
void preparar_conexao(struct hostent *host, struct sockaddr_in *remoteServAddr)
{
	remoteServAddr->sin_family = host->h_addrtype;
	memcpy((char *) &remoteServAddr->sin_addr.s_addr,host->h_addr_list[0], host->h_length);
	remoteServAddr->sin_port = htons(REMOTE_SERVER_PORT);
}

/* GERA UM PACOTE PARA SER ENVIADO */
pacote gerar_pacote(char * mensagem,int numerosequencia,int dimseg,int pflag)
{
	pacote pac;
	int i=0;

	//Inserir segmento do arquivo no pacote
	for(i=0 ; i<dimseg ; i++)
		pac.segmento[i] = *(mensagem+i);

	//Definir dimensao do segmento contido no pacote
	pac.dim = dimseg;

	//Definir checksum do pacote
	pac.check_sum = checksum(pac.segmento,pac.dim);

	//Definir numero sequencial do pacote
	pac.numsequencial = numerosequencia;

	//Definir flag do pacote
	pac.flag = pflag;

	//Imprimir informaçoes do pacote
	printf("[PACOTE %d]: Tam. segmento: %3d | Checksum: %li\n",pac.numsequencial,pac.dim,pac.check_sum);

	return pac;
}

/* GERA UM PACOTE QUE CONTEM O NOME DO ARQUIVO A SER TRANSFERIDO*/
pacote pacote_inicial(char *nome_arq,int numarq)
{
	pacote pct;

	//ADD nome do arquivo ao pacote
	strcpy(pct.segmento,nome_arq);

	//Definir tamanho da string que define nome do arquivo
	pct.dim = strlen(pct.segmento);

	//Definir checksum do pacote
	pct.check_sum = checksum(pct.segmento,pct.dim);

	//Definir numero sequencial do pacote
	pct.numsequencial = numarq;

	//Definir flag do pacote
	pct.flag = STATUS_SUCESSO;

	//Imprimir informaçoes do pacote
	printf("\n\n[PACOTE DE CONEXAO %d]: Nome do arquivo: %s | Tam. segmento: %3d | Checksum: %3li | Flag: %2d\n\n",pct.numsequencial,pct.segmento,pct.dim,pct.check_sum,pct.flag);

	return pct;
}

/* GERA UM PACOTE COM MENSAGEM DE FINALIZACAO */
pacote pacote_final(int sequencial,int status)
{
	pacote p;

	//Adicionar mensagem ao pacote
	strcpy(p.segmento,"EXIT");

	//Definir tamanho da mensagem do pacote
	p.dim = 4;

	//Definir numero sequencial
	p.numsequencial = sequencial;

	//Definir checksum do pacote
	p.check_sum = checksum("EXIT",p.dim);
	if(status == STATUS_ERRO)
		p.check_sum -= 2;

	//Definir flag do pacote
	p.flag = STATUS_ERRO;

	printf("\n\n[PACOTE DE FINALIZACAO %d]: Msg.: EXIT | Tam. Msg: 4 | Checksum: %3li | Flag: %2d\n",p.numsequencial,p.check_sum,p.flag);
	return p;
}

/* ENVIA UM PACOTE AO SERVIDOR DE DESTINO */
void enviar_pacote(int sock,pacote *pac, struct sockaddr_in remoteServAddr)
{
	int resultado;

	do
	{
		//Enviar pacote
		resultado = sendto(sock,pac, sizeof(pacote)+1, 0,(struct sockaddr *) &remoteServAddr,sizeof(remoteServAddr));

		//Verificar se o envio foi realizado
		if(resultado<0)
			printf("\n[ERRO]: Falha no envio do pacote %d.. \n",pac->numsequencial);
	}while(resultado < 0);
}

/* RECEBE UMA RESPOSTA DO SERVIDOR */
int resposta_servidor(struct sockaddr_in *remoteServAddr, int sock, int numerosequencia)
{
	resposta rsp;
	int aux;
	int n;

	//Iniciar buffer
	memset(&rsp,0x0,sizeof(rsp));

	//Receber resposta do servidor
	aux = sizeof(*remoteServAddr);
	n = recvfrom(sock,&rsp,sizeof(resposta), 0,(struct sockaddr *) remoteServAddr, &aux);

	//Verificar se a resposta foi recebida
	if( n<0 )
	{
	    printf("[ERRO]: Resposta do servidor não recebida!\n");
	    return -1;
	}
	else
	{
		//Resposta positiva
	    if(rsp.status != 0)
	    {
	    	if(rsp.status == 1)
	    		printf("[INFO]: Pacote %d entregue ao servidor..\n\n",numerosequencia);
	    	if(rsp.status == -1)
	    	{
	    		printf("[INFO]: Deteccao de duplicatas pelo servidor no pacote %d ..\n",numerosequencia);
	    		printf("[INFO]: Gerando proximo pacote...\n\n");
	    	}

			return numerosequencia+1;
	    }
	    //Resposta negativa - ERRO
	    else
	    {
	    	printf("[INFO]: Pacote %d com erro detectado pelo servidor. Reenvio em andamento..\n",numerosequencia);
	    	return numerosequencia;
	    }
	}
}

/* EXIBE OPCOES PARA O CLIENTE*/
int menu()
{
	int esc;

	do
	{
		printf(":::..MENU DE TRANSFERENCIA DE ARQUIVOS - CLIENTE ..:::\n\n");
		printf("1. Enviar arquivo  \n");
		printf("2. Encerrar conexao\n");

		printf("\nInforme o numero da opcao desejada.: ");
		scanf("%d",&esc);

	}while(esc!=1 && esc !=2);

	if(esc == 2)
		esc = 0;

	return esc;
}

//---------------------------------------FUNCAO PRINCIPAL C---------------------------------------//
int main(int numparametros, char *listaparametros[])
{
	int sock, numerosequencia,numarquivo=1,aux,n;
  	struct sockaddr_in cliAddr, remoteServAddr;
  	struct hostent *host;
  	struct timeval tempo;
  	char *mensagem;
    FILE *arquivo;
	pacote envio;
	resposta rsp;

	mensagem = malloc(sizeof(char)*512);
	if(!mensagem)
	{
		printf("\n[ERRO]: Falha ao obter memoria para execucao...\n\n");
		exit(0);
	}
	else
	{
		printf("\nInforme o endereco IP do servidor.: ");
		scanf("%s",mensagem);
	}


	// OBTER ENDEREÇO IP DO SERVIDOR (sem verificar se a entrada é o endereço IP ou o nome DNS)
	host = conectar_com_host(mensagem);

	// PREPARAR A CONEXAO COM O SERVIDOR
	preparar_conexao(host,&remoteServAddr);

	// CRIAR SOCKET E VINCULAR PORTA DO CLIENTE
	sock = criar_socket(&cliAddr,&tempo);

	// CHECAR DISPONIBILIDADE DA PORTA
	disponibilidade_da_porta(sock,cliAddr);

	while(menu())
	{
		//Abrir novo arquivo de dados
		arquivo = abrir_arquivo(mensagem);

		//Iniciar variavel que controla o numero sequencial dos pacotes desse arquivo
		numerosequencia= 1;

		//Gerar e enviar pacote de inicio de transferencia de arquivo ao servidor
		envio = pacote_inicial(mensagem,numarquivo);
		enviar_pacote(sock,&envio,remoteServAddr);

		///Receber resposta do servidor
		n = numarquivo;
		while(n == numarquivo || n == -1)
		{
			n = resposta_servidor(&remoteServAddr,sock,numarquivo);

			//Resposta -1 indica estouro de temporizador ou possivel pacote perdido. Necessaria retransmissao
			if(n == -1)
				enviar_pacote(sock,&envio,remoteServAddr);
		}
		//Atualizar numero sequencial do proximo arquivo
		numarquivo++;

		//Iniciar envio do arquivo ao servidor
		while( !feof(arquivo) )
		{
			//Ler um segmento do arquivo
			aux = fread(mensagem,1,512,arquivo);
			printf("[INFO]: Tamanho do segmento: %d",aux);

			//gerar um pacote de envio
			envio = gerar_pacote(mensagem,numerosequencia,aux,STATUS_SUCESSO);

			//Enviar pacote
			enviar_pacote(sock,&envio,remoteServAddr);

			//Receber resposta de servidor
			n = numerosequencia;
			while(n == numerosequencia || n == -1)
			{
				n = resposta_servidor(&remoteServAddr,sock,numerosequencia);

				//Resposta -1 indica estouro de temporizador ou possivel pacote perdido. Necessaria retransmissao
				if(n == -1)
					enviar_pacote(sock,&envio,remoteServAddr);
			}
			//Atualizar numero de sequencia do proximo pacote
			numerosequencia++;
		}

		//Gerar pacote com erro para que o servidor encerre a recepçao do arquivo atual
		envio = pacote_final(numerosequencia,STATUS_ERRO);

		//Enviar pacote de fim de arquivo (Servidor deve detectar erro de checksum)
		do
		{
			enviar_pacote(sock,&envio,remoteServAddr);
			n = resposta_servidor(&remoteServAddr,sock,numerosequencia);

		}while(n < 0);

		//Fechar arquivo ja enviado
		fclose(arquivo);

		printf("\n\n::::::..ARQUIVO ENTREGUE AO SERVIDOR..::::::\n\n");
	}

	//Enviar pacote de fim de conexao ao servidor
	envio = pacote_final(numarquivo,STATUS_SUCESSO);
	enviar_pacote(sock,&envio,remoteServAddr);

	//Receber confirmacao do servidor
	n = numarquivo;
	while(n == numarquivo || n == -1)
	{
		n = resposta_servidor(&remoteServAddr,sock,numarquivo);

		//Resposta -1 indica estouro de temporizador ou possivel pacote perdido
		//Realizando retransmissao
		if(n == -1)
			enviar_pacote(sock,&envio,remoteServAddr);
	}


	//Exibir mensagem ao usuario e encerrar execucao
	printf("\n\n------------------ Transferencias concluidas com sucesso!-------------------\n\n");
	exit(0);
}
