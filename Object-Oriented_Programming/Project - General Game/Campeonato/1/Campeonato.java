package campeonato;
import java.io.Serializable;
import java.io.IOException;
import java.util.Scanner;

public class Campeonato implements Serializable{
	private Jogador jogadores[] = new Jogador[5];	
	private int cartela[][] = new int [13][5];
	private int size;
        
        private GravarArquivo Save = new GravarArquivo();
        
        public void salvarJogo() {
            this.Save.gravarArquivo(this.jogadores, this.cartela, this.size);
        }
         
        public void lerJogadores() {
            this.jogadores = this.Save.lerJogadores();
        }
        public void lerCartela() {
            this.cartela = this.Save.lerCartela();
        }
        public void lerSize() {
            this.size = this.Save.lerSize();
        }
        
        public void lerJogo() {
            lerSize();
            lerJogadores();
            lerCartela();
            System.out.println("\n\n-------------[Arquivo Carregado]------------\n\n");
             
         }

	public Campeonato(){  // Metodo construtor, Inicia o objeto campeonato com zero jogadores e zera a cartela de pontuaçao
		this.size=0;
		zerarCartela();
	}
	public void zerarCartela(){ // metodo que zera a cartela de pontos para iniciar um novo campeonato
		for(int i=0; i<5; i++){
			for(int k=0; k<13; k++){
				 cartela[k][i]=-1;
			}
		}
	}
	public void zerarJogadas(){  // chama o metodo que zera o vetor de jogadas marcadas para o todos os jogadores no campeonato
		for(int i=0; i<this.size; i++){
			jogadores[i].zerarJogadas();
		}
	}
	public void criarJogador(String nome){ // Cria um jogador 
		if(this.size<5){		
			jogadores[this.size]= new Jogador(nome);
			this.size++;
			System.out.println(""+nome+" Agora é um jogador!");
		}
		else{
			System.out.println("Falha ao inserir novo jogador.");
			System.out.println("O número limite de jogadores foi atingido!");
		}		
	}
	public void imprimirJogadores(){  // imprimi a lista de jogadores atualmente no campeonato
		System.out.println("Jogadores");
		for(int j=0; j<this.size; j++){
			System.out.println((j+1)+"-"+jogadores[j]);
		}
	}
	public void removerJogador(int n){  // remove do campeonato o jogador escolhido 
		if(n>=1 && n<=this.size){		
			if(n==this.size){	
				this.jogadores[n-1]=null;
				this.size--;
			}
			else{
				this.jogadores[n-1]=null;
				for(int i=(n-1); i<(this.size-1); i++){
					this.jogadores[i]=this.jogadores[i+1];
					for(int j=0; j<13; j++){
						this.cartela[j][i]=this.cartela[j][i+1];
					}
				}
				this.size--;
			}
		}
		else{
			System.out.println("Jogador inexistente");
		}
	}
	public void iniciarCampeonato(){ // inicia um campeaonato, rolando os dados uma vez para cada jogador ate se completar 13 rodadas para cada um
		zerarJogadas();
		zerarCartela();
		Scanner teclado =new Scanner(System.in);
		int opcao;
		if(this.size!=0){
			for(int i=0; i<13; i++){
				for(int k=0; k<this.size; k++){
						jogadores[k].jogarDados();
						jogadores[k].imprimirDados();
					do{					
						jogadores[k].imprimirJogadas();
						System.out.println("para qual jogada deseja marcar: [1 - 13] "+jogadores[k]+"?");
						opcao=teclado.nextInt();
						if(opcao>=1 && opcao<=13){
							if(jogadores[k].verificarJogadaMarcada(opcao)==false){
								jogadores[k].marcarJogada(opcao);
								marcarCartela(jogadores[k].verificarPontos(opcao),(opcao-1),k);
								imprimirCartela();
							}
							else{
								System.out.println("Essa jogada já foi marcada, tente outra!");
								opcao=-1;
							}					
						}
						else{
							System.out.println("Número inválido,tente novamente");
						}
					}while(opcao<1 || opcao>13);// arrumar condiçao de repetiçao caso entrada invalida
				}
			}
		}
		else{
			System.out.println("Impossivel iniciar o campeonato sem jogadores");
		}
	}
	public void marcarCartela(int i, int j,int k){  // Marca na cartela a pontuaçao da jogada escolhida por cada jogador
		this.cartela[j][k]=i;
	}
	public void imprimirCartela(){  // imprimi uma cartela com os nomes e pontuaçoes de cada jogador participante do campeonato
		if(this.size!=0){
			System.out.println("----------------Cartela de Resultados----------------");
			System.out.print("\t");
			for(int j=0; j<this.size; j++){
				System.out.printf("  %5s",jogadores[j]);
			}
			System.out.println("");
			for(int k=0; k<13; k++){
				if(k==0){
					System.out.print("1     ");
				}
				else if(k==1){
					System.out.print("2     ");
				}
				else if(k==2){
					System.out.print("3     ");
				}
				else if(k==3){
					System.out.print("4     ");
				}
				else if(k==4){
					System.out.print("5     ");
				}
				else if(k==5){
					System.out.print("6     ");
				}
				else if(k==6){
					System.out.print("7(T)  ");
				}
				else if(k==7){
					System.out.print("8(Q)  ");
				}
				else if(k==8){
					System.out.print("9(F)  ");
				}
				else if(k==9){
					System.out.print("10(S+)");
				}
				else if(k==10){
					System.out.print("11(S-)");
				}
				else if(k==11){
					System.out.print("12(G) ");
				}
				else{
					System.out.print("13(X) ");
				}
				for(int i=0; i<this.size; i++){
					if(this.cartela[k][i]!=-1){			
						System.out.printf("   %5d",this.cartela[k][i]);
					}
					else{
						System.out.print("        ");
					}
				}		
				System.out.println("");
			}
			System.out.println("-----------------------------------------------------");
			System.out.print("Total ");
			for(int j=0; j<this.size; j++){
				if(somarPontos(j)>=0){	
					System.out.printf("   %5d",somarPontos(j));
				}
				else{
					System.out.print("        ");
				}
			}
			System.out.println("");
		}
		else{
			System.out.println("Não há jogadores no campeonato");
		}
	}
	public int somarPontos(int n){  // soma o total de pontos de cada jogador na sua cartela
		int total=0;
		for(int i=0; i<13; i++){
			if(cartela[i][n]>=0){
				total= total + cartela[i][n];
			}
		}
		return total;
	}
		public static void main (String[] args){
			Campeonato a= new Campeonato();  // cria um objeto campeonato
			Scanner teclado =new Scanner(System.in);
			Scanner entrada =new Scanner(System.in);
			char opcao;
			int i;
			String nome;
			do{  // imprimi um menu de opçoes para interaçao com o usuario.
				System.out.println("(a) Incluir jogador");
				System.out.println("(b) Remover jogador");
				System.out.println("(c) Iniciar/reiniciar o campeonato");
				System.out.println("(d) Mostrar a cartela de resultados");
				System.out.println("(e) Gravar os dados do campeonato em arquivo");
				System.out.println("(f) Ler os dados do campeonato em arquivo");
				System.out.println("(g) Sair da aplicação");
				opcao=teclado.nextLine().charAt(0);

				if(opcao =='a' || opcao =='A'){
					System.out.print("Insira seu nome: ");
					nome=teclado.nextLine();
					a.criarJogador(nome);
				}	
				else if(opcao =='b' || opcao =='B'){
					a.imprimirJogadores();
						System.out.print("Digite o número do jogador a ser removido: ");
						i=entrada.nextInt();	
						a.removerJogador(i);
				}
				else if(opcao =='c' || opcao =='C'){
					System.out.println("Iniciando Campeonato...");
					a.iniciarCampeonato();
				}
				else if(opcao =='d' || opcao =='D'){
					a.imprimirCartela();
				}
				else if(opcao =='e' || opcao =='E'){
                                        a.salvarJogo();
				}
				else if(opcao =='f' || opcao =='F'){
                                        a.lerJogo();
				}
				else{
					if(opcao != 'g' && opcao != 'G'){
						System.out.println("Opção inválida, tente novamente");
					}
				}
			}while(opcao != 'g' && opcao != 'G');
		}
}
