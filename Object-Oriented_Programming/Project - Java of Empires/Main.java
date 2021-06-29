import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Arena mapa = new Arena();		
		Scanner teclado = new Scanner(System.in);
		int id;
		String direcao;
		int i = 0;
		
		while(i != -1) {
			System.out.println("8: Para começar um novo Jogo\n 9: Para carregar um jogo salvo \n -1: Para Sair");
			i = teclado.nextInt();
			
			if(i == 8) {
				mapa.NovoJogo();
				
				do {
					System.out.println("\n\nEscolha uma opcao:\n 1: Printar Mapa\n 2: Atacar\n 3: Mover\n 4: Inserir Unidade \n 5: Excluir Unidade \n 6: Salvar Jogo \n -1: SAIR");
					i = teclado.nextInt();
					
					if(i == 1) {
						mapa.PrintMapa();
					}
					else if(i ==2) {
						System.out.println("Digite o id do personagem para efetuar o Ataque: ");
						id = teclado.nextInt();
						mapa.Atacar(id);
					}
					else if(i == 3) {
						System.out.println("Digite o id do personagem.");
						id = teclado.nextInt();
						System.out.println("E a direcao sendo: \n N->Norte\n S->Sul\n L->Leste\n O->Oeste\n ");
						direcao = teclado.next();
						mapa.MovimentarUnidade(id, direcao);;
					}
					else if(i == 4) {
						int x, y;
						System.out.println("Digite o Tipo do personagem: \n (Q) Arqueiro\n(C) Cavaleiro\n (A) Aldeao\n (N) Navio\n (G) Guerreiro");
						direcao = teclado.next();
						System.out.println("Digite a posicao X do Personagem (linha do Mapa): Valor entre 0 a 9");
						x = teclado.nextInt();
						System.out.println("Digite a posicao Y do Personagem (coluna do Mapa): Valor entre 0 a 9");
						y = teclado.nextInt();
						mapa.InserirUnidade(direcao, x, y);
					}
					else if( i == 5) {
						System.out.println("Digite o ID do personagem que você quer Excluir: ");
						id = teclado.nextInt();
						mapa.DeleteUnidade(id);
					}
					else if(i == 6) {
						System.out.println("Seu jogo será salvo!");
						mapa.SalvarJogo();
					}
				}while(i != -1);
				
			}
			else if( i == 9) {
				System.out.println("Carregando jogo....");
				mapa.LerJogo();
				
				do {
					System.out.println("\n\nEscolha uma opcao:\n 1: Printar Mapa\n 2: Atacar\n 3: Mover\n 4: Inserir Unidade \n 5: Excluir Unidade \n 6: Salvar Jogo \n -1: SAIR");
					i = teclado.nextInt();
					
					if(i == 1) {
						mapa.PrintMapa();
					}
					else if(i ==2) {
						System.out.println("Digite o id do personagem para efetuar o Ataque: ");
						id = teclado.nextInt();
						mapa.Atacar(id);
					}
					else if(i == 3) {
						System.out.println("Digite o id do personagem.");
						id = teclado.nextInt();
						System.out.println("E a direcao sendo: \n N->Norte\n S->Sul\n L->Leste\n O->Oeste\n ");
						direcao = teclado.next();
						mapa.MovimentarUnidade(id, direcao);;
					}
					else if(i == 4) {
						int x, y;
						System.out.println("Digite o Tipo do personagem: \n (Q) Arqueiro\n(C) Cavaleiro\n (A) Aldeao\n (N) Navio\n (G) Guerreiro");
						direcao = teclado.next();
						System.out.println("Digite a posicao X do Personagem (linha do Mapa): Valor entre 0 a 9");
						x = teclado.nextInt();
						System.out.println("Digite a posicao Y do Personagem (coluna do Mapa): Valor entre 0 a 9");
						y = teclado.nextInt();
						mapa.InserirUnidade(direcao, x, y);
					}
					else if( i == 5) {
						System.out.println("Digite o ID do personagem que você quer Excluir: ");
						id = teclado.nextInt();
						mapa.DeleteUnidade(id);
					}
					else if(i == 6) {
						System.out.println("Seu jogo será salvo!");
						mapa.SalvarJogo();
						
					}
				}while(i != -1);
			}
		}
		
	}
}
