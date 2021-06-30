#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MSG 1024
#define PORTA 4321

/*
 Servidor recebe mensagem do cliente, imprime na tela e envia uma resposta.
 Se o cliente desconectar, processo do servidor continua ativo esperando
 por novas conexoes.
 */

int main(void){
	//variaveis
	int socket_desc , conexao , c;
	struct sockaddr_in server,client;
	char *mensagem2;   
   	char resposta[MAX_MSG];
   	char resultado[MAX_MSG];
	int tamanho, tamanho2, count;

	// destinado a armazenar o IP e porta do cliente  
	char *client_ip;
	int client_port;

	/*********************************************************/
        //Passo 1: Criar o socket servidor na porta passada por parametro
	// AF_INET = ARPA INTERNET PROTOCOLS
	// SOCK_STREAM = TCP
	// 0 = protocolo IP

	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) {
		printf("Nao foi possivel criar o socket\n");
		return -1;
	}
     
	// Associar (bind) o socket a todos IPs locais 
        // e a PORTA ESPECIFICA para os clientes se conectarem
	server.sin_family = AF_INET; // AF_INET = ARPA INTERNET PROTOCOLS
	server.sin_addr.s_addr = INADDR_ANY; // Obtem IP do S.O.
	server.sin_port = htons(PORTA);
     
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0){
		puts("Erro ao fazer bind!!! \n");
	}
	puts("Bind efetuado com sucesso!!! \n");

        // Passo 2: aguarda por conexões de clientes
        // O segundo parametro indica quantos conexoes podem aguardar no buffer
	listen(socket_desc, 3);
	/*********************************************************/

	//Aceitando e tratando conexoes
	puts("Aguardando por conexoes...");
	c = sizeof(struct sockaddr_in);
	// Fica esperando por conexoes
	while( (conexao = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) ){;
		if (conexao<0){
			perror("Erro ao receber conexao do jogador 1\n");
			return -1;
		}

		//Passo 3: realizar a comunicação 
		// pegando IP e porta do cliente
		client_ip = inet_ntoa(client.sin_addr);
		client_port = ntohs(client.sin_port);
		printf("O Jogador 1 conectou: %s : [ %d ]\n",client_ip, client_port);


		//gerando minha jogada 
		int m, n;
		
		//srand(time(0));
		n = rand() % 100;
		
		//m = 1 + (rand() % 3);
		printf("n = %d \n",n);
		
		if(n < 33)
		{
			mensagem2 = "Pedra";
		}
		else if(n > 33 && n < 66)
		{
			mensagem2 = "Papel";
		}
		else
		{
			mensagem2 = "Tesoura";
		}

		printf("Jogador 2: %s \n", mensagem2);
		
		// lendo jogada do outro jogador
		if((tamanho = read(conexao,resposta, MAX_MSG)) < 0){
			perror("Erro ao receber dados do outro jogador: ");
			return -1;
		}
		
		
		// Coloca terminador de string
		resposta[tamanho] = '\0';
		printf("Jogador 1: %s \n", resposta);

		// Enviando minha jogada
		write(conexao , mensagem2 , strlen(mensagem2));
		
		//lendo resultado
		if((tamanho2 = read(conexao,resultado, MAX_MSG)) < 0){
			perror("Erro ao receber dados do outro jogador: ");
			return -1;
		}
		
		// Coloca terminador de string
		resultado[tamanho2] = '\0';
		printf("Resultado: %s \n", resultado);
		
		//Passo 4: Encerrar conexão
		printf("####### Rodada finalizada #######\n");
		close(conexao);
	}//fim do while

	/*********************************************************/


	printf("Servidor finalizado...\n");
	return 0;
}
