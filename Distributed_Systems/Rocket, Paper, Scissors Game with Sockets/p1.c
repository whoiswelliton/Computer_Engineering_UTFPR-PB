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

int main(int argc , char *argv[]){
	// variaveis
	int socket_desc;
	struct sockaddr_in servidor;
	char *ipservidor = "127.0.0.1";
	
	char *mensagem;
	char *resultado;
	char resposta_servidor[MAX_MSG];
	int tamanho;
	
        //Passo 1: Criar o socket 
	// AF_INET = ARPA INTERNET PROTOCOLS
	// SOCK_STREAM = TCP
	// 0 = protocolo IP
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
     
	if (socket_desc == -1){
		printf("Nao foi possivel criar socket\n");
		return -1;	
	}

	/* Informacoes para conectar no servidor */
	// IP do servidor
	// familia ARPANET
	// Porta - hton = host to network short (2bytes)
	servidor.sin_addr.s_addr = inet_addr(ipservidor);
	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(PORTA);


	//Conectar no servidor
	if (connect(socket_desc , (struct sockaddr *)&servidor , sizeof(servidor)) < 0){
		printf("Nao foi possivel conectar com o jogador 2\n");
		return -1;
	}
	printf("Conectado no servidor!!!\n");


	/*******COMUNICAO - TROCA DE MENSAGENS **************/

	//Passo 3: Realizar a comunição com o servidor segundo um protocolo.


	//while(1)
	//{
		int m, n;
		
		srand(time(0));
		n = rand() % 100;
		
		//m = 1 + (rand() % 3);
		printf("n = %d \n",n);
		
		if(n < 33)
		{
			mensagem = "Pedra";
		}
		else if(n > 33 && n < 66)
		{
			mensagem = "Papel";
		}
		else
		{
			mensagem = "Tesoura";
		}
		
		printf("Jogador 1: %s\n", mensagem);
		
		//Envia jogada para o servidor
		if( send(socket_desc , mensagem , strlen(mensagem) , 0) < 0){
			printf("Erro ao enviar jogada\n");
			return -1;
		}

		//Recebendo resposta do jogador 2 (echo)
		if( (tamanho = recv(socket_desc, resposta_servidor, MAX_MSG , 0)) < 0){
			printf("Falha ao receber jogada\n");
			return -1;
		}
		printf("Jogador 2: ");
		resposta_servidor[tamanho] = '\0';
		//puts(resposta_servidor);
		printf("%s\n",resposta_servidor);
		
		//char aux;
		//aux = resposta_servidor;
		//resultado = resposta_servidor;
		
		
		if(strcmp(mensagem, resposta_servidor) == 0)
		{
			resultado = "Empate";
			
		}
		else
		{
			if(strcmp(mensagem, "Pedra") == 0 && strcmp(resposta_servidor,"Tesoura") == 0 || strcmp(mensagem, "Papel") == 0 && strcmp(resposta_servidor,"Pedra") == 0 || strcmp(mensagem, "Tesoura") == 0 && strcmp(resposta_servidor,"Papel") == 0)
			{
				resultado = "Vencedor: Jogador 1";
				
			}
			else if(strcmp(mensagem, "Pedra") == 0 && strcmp(resposta_servidor,"Papel") == 0 || strcmp(mensagem, "Papel") == 0 && strcmp(resposta_servidor,"Tesoura") == 0 || strcmp(mensagem, "Papel") == 0 && strcmp(resposta_servidor,"Tesoura") == 0)
			{
				resultado = "Vencedor: Jogador 2";
				
			}
		}
		
		//break;
	//}
	
	printf("Resultado da Rodada: %s\n", resultado);
	//Envia resultado
	if( send(socket_desc , resultado , strlen(resultado) , 0) < 0){
			printf("Erro ao enviar jogada\n");
			return -1;
		}

	/*****************************************/
        //Passo 4: Encerrar conexão

	close(socket_desc);

	printf("####### Rodada finalizada #######\n");
	return 0;
}
