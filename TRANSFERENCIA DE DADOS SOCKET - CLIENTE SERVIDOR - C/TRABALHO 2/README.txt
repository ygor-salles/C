@	-------------------------------TRANSFERÊNCIA CONFIÁVEL DE ARQUIVOS VIA SOCKET UDP------------------------------
#	Universidade Federal de Itajubá, trabalho referente à disciplina de redes de computadores, 1º semestre de 2016.
#	Alunos:
#		Bruno Felipe de Moraes , 2017009453.
#		Mateus Henrique Toledo, 34849.
#	Linguagem de programação: C
#
@	---------------------------------------------------COMPILAR----------------------------------------------------
#	Executável de cliente e servidor devem ser compilados individualmente, conforme instruções a seguir:
#	-> Linux: 
#		gcc cliente.c -o client
#		gcc servidor.c -o server
#	-> Outras plataformas:
#		Recomenda-se o uso de um IDE para auxiliar na visualização do código e na compilação.
#
@	---------------------------------------------------EXECUTAR----------------------------------------------------
#		Para que a transferência funcione corretamente o servidor deve ser executado em um diretório diferente do 
#	cliente, já que será gerado um arquivo com o mesmo nome do arquivo que está sendo recebido do cliente. É 
#	recomendável que o servidor seja iniciado primeiro para este esperar pelos arquivos.
#		Os arquivos são abertos em modo de leitura binária, ou seja, o cliente pode enviar qualquer tipo de arquivos
#	ao servidor, sejam arquivos de texto, vídeo, imagens, entre outros.
#
#	-> Linux: 
#		1º: Abrir 2 abas no terminal (ou 2 terminais), onde uma aba esteja "apontando" para o diretório contendo 
#			o executável do cliente e outra para o do servidor.
#		2º: Na aba referente ao diretório do servidor, executaro comando: 	./server
#			2.1: A partir deste momento o servidor está aguardando solicitações para receber arquivos de clientes.
#		3º: Na aba referente ao diretório do cliente, executar comando:		./client
#			3.1: A partir deste momento o cliente está apto a enviar arquivos a um servidor remoto.
#			3.2: O software do cliente irá solicitar o endereço IP do servidor, informe-o corretamente.
#			3.3: Informe os nomes de arquivo corretamente. Um arquivo não aberto "mata" a aplicação do cliente.
#	-> Demais plataformas: 
#		Utilizar opção de compilar e executar no IDE desejado. É recomendada que a execução inicie pela aplicação de
#		servidor, para que não ocorram erros de servidor não encontrado.
#
@	-----------------------------------------------------------------------------------------------------------------
