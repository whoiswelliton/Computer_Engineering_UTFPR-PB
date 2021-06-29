package campeonato;
import java.io.Serializable;

public class Jogador implements Serializable{
	private String nome;
	private JogoGeneral jogo;
	
	public Jogador(String nome){  // Metodo Construitor com nome e inicia um objeto da classe JogoGeneral
		this.nome=nome;	
		this.jogo = new JogoGeneral();
	}
	public void jogarDados(){  //Metodo que chama o metodo jogarDados para o objeto Jogo
		System.out.println("Rolando dados para "+ this.nome +"...");
		this.jogo.jogarDados();
	}
	public void imprimirDados(){  // Metodo que imprimi os valores dos das faces dos 5 dados que foram jogados
		System.out.print("Valores obtidos: ");
		this.jogo.imprimirDados();
	}
	public void marcarJogada(int n){   // Marca uma jogada no objeto jogo
		this.jogo.marcarJogada((n-1));
	}
	public boolean verificarJogadaMarcada(int n){    // verifica se uma jogada ja foi marcada no objeto jogo
		return this.jogo.verificarJogadaMarcada((n-1));
	}
	public int verificarPontos(int n){ // chama o metodo VerificarPontos no objeto Jogo, verifica se a jogada escolhida para marcar é valida, retorna a pontuaçao caso valida ou zero caso jogada invalida
		return this.jogo.verificarPontos(n);
	}
	public void zerarJogadas(){   // Metodo que zera o vetor que marca as jogadas, para iniciar outro campeonato
		this.jogo.zerarJogadas();
	}
	public void imprimirJogadas(){  //Chama o metodo imprimirJogadas do objeto jogo, que Imprimi quais jogadas foram marcadas e quais estao disponiveis
		this.jogo.imprimirJogadas();
	}	
	public String toString(){  // Retorna uma string com o nome do jogador
		return this.nome; 
	}
}
