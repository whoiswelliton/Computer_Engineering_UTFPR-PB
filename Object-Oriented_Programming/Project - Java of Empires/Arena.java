
import java.util.*;

/**
 * Ser√° a "Interface" de comunicacao cm os comandos do usuario, como exibir mapa e as unidades, possibilitar movimentacao, excluir ou adicionar unidades.
 */
public class Arena  {

	private Auxiliar auxiliar = new Auxiliar();

    private Aldeao[] unidades;
    private String[][] mapa;
    
    private GravarArquivo RW = new GravarArquivo();

    String[] stringe = new String[3];
 
    private Randomico RD = new Randomico();


    /**
     * Seta a Quantidade inicial de Unidades como 10 .
     * Inicializa o Mapa como null.
     */
    public Arena() {
    	this.mapa = new String[10][10];
    	this.SetMapNull();
    }
    public void LoadJogo() {
    	this.mapa = new String[10][10];
    	this.SetMapNull();
    }

    public void NovoJogo() {
    	this.unidades = new Aldeao[30];
    	this.SetUnidadesStart();
    	this.SetaMapaUnidades();
    }
    /**
     * Printa o Mapa com todas as unidades em suas respectivas posicoes.
     */
    public void PrintMapa() {
    	this.SetaMapaUnidades();
       int i, j;
       for(i = 0; i < 90; i++) {
    	   System.out.print("*");
       }
       System.out.print("\n \t");
       for(i = 0; i < 10; i++) {
    	   System.out.print(i + "\t");
       }
       System.out.println("\n");
       for(i = 0; i < 90; i++) {
    	   System.out.print("-");
       }
       System.out.println("\n");
       for(i = 0; i < 10; i++) {
    	   System.out.print(i + "\t");
    	   for(j = 0; j < 10; j++) {
    		   System.out.print(this.mapa[i][j] + "\t ");    		   
    	   }
    	   System.out.println("\n"); //muda de linha
       }
       
       for(i = 0; i < 90; i++) {
    	   System.out.print("*");
       }
    }

    /**
     * Possibilita a movimentacao da unidade.
     * @param nome Nome da Unidade a ser movimentada.
     * @param direcao Direcao de ser do Tipo: 'S' -> Sul ... 'N' -> Norte ... 'L' -> Leste ... 'O' -> Oeste.
     */
    public void MovimentarUnidade(int id, String direcao) {
    	if(direcao.equals("N") || direcao.equals("S") || direcao.equals("L") || direcao.equals("O")) {
    		auxiliar.Movimenta(id, direcao, this.unidades, this.mapa);
        	this.unidades = auxiliar.getUnidade();
        	this.mapa = auxiliar.getMapa();
        	this.PrintMapa();
    	}
    	
    	else if(direcao.equals("n") || direcao.equals("s") || direcao.equals("l") || direcao.equals("o")) {
    		if(direcao.equals("n")) {
    			direcao = "N";
    			auxiliar.Movimenta(id, direcao, this.unidades, this.mapa);
            	this.unidades = auxiliar.getUnidade();
            	this.mapa = auxiliar.getMapa();
            	this.PrintMapa();
    		}
    		else if(direcao.equals("s")) {
    			direcao = "S";
    			auxiliar.Movimenta(id, direcao, this.unidades, this.mapa);
            	this.unidades = auxiliar.getUnidade();
            	this.mapa = auxiliar.getMapa();
            	this.PrintMapa();
    		}
    		else if(direcao.equals("l")) {
    			direcao = "L";
    			auxiliar.Movimenta(id, direcao, this.unidades, this.mapa);
            	this.unidades = auxiliar.getUnidade();
            	this.mapa = auxiliar.getMapa();
            	this.PrintMapa();
    		}
    		else if(direcao.equals("o")) {
    			direcao = "L";
    			auxiliar.Movimenta(id, direcao, this.unidades, this.mapa);
            	this.unidades = auxiliar.getUnidade();
            	this.mapa = auxiliar.getMapa();
            	this.PrintMapa();
    		}
    	}
    	else {
    		System.out.println("A direcao informada n„o esta nos padrıes corretos! Por favor tente novamente.\n\n\n");
    	}
    	
    }
    
    public void Atacar(int id) {
    	auxiliar.Atacar(id, this.unidades, this.mapa);
    	this.unidades = auxiliar.getUnidade();
    	this.mapa = auxiliar.getMapa();
    	this.PrintMapa();
    }
    
    /** 
     * Insere uma nova unidade. Incluir personagem (deve-se informar o tipo e a posicao (x,y) do personagem)
     * 
     * @param tipo Espera-se:(Q) Arqueiro,(C) Cavaleiro,(A) Aldeao,(N) Navio ou (G) Guerreiro
     * @param PosX A Linha onde sera inserido
     * @param PosY A Coluna onde sera inserido
     */
    
    public void InserirUnidade(String tipo, int PosX, int PosY) {
    	if(PosX > 9 || PosY > 9 || PosX < 0 || PosY < 0) {
    		System.out.println("Posicao invalida, insira um valor de 0 a 9.\n");
    	}
    	else if(tipo.equals("Q") || tipo.equals("C") || tipo.equals("A") || tipo.equals("G") || tipo.equals("N")) {
    		auxiliar.InserirPersonagem(tipo, this.unidades, this.mapa, PosX, PosY);
    		this.unidades = auxiliar.getUnidade();
        	this.mapa = auxiliar.getMapa();
        	this.PrintMapa();
        	
    	}
    	else if(tipo.equals("q") || tipo.equals("c") || tipo.equals("a") || tipo.equals("g") || tipo.equals("n")) {
    		
    		if(tipo.equals("q")) {
    			tipo = "Q";
    			auxiliar.InserirPersonagem(tipo, this.unidades, this.mapa, PosX, PosY);
    			this.unidades = auxiliar.getUnidade();
    	    	this.mapa = auxiliar.getMapa();
    	    	this.PrintMapa();
    		}
    		else if(tipo.equals("a")) {
    			tipo = "A";
    			auxiliar.InserirPersonagem(tipo, this.unidades, this.mapa, PosX, PosY);
    			this.unidades = auxiliar.getUnidade();
    	    	this.mapa = auxiliar.getMapa();
    	    	this.PrintMapa();
    		}
    		else if(tipo.equals("g")) {
    			tipo = "G";
    			auxiliar.InserirPersonagem(tipo, this.unidades, this.mapa, PosX, PosY);
    			this.unidades = auxiliar.getUnidade();
    	    	this.mapa = auxiliar.getMapa();
    	    	this.PrintMapa();
    		}
    		else if(tipo.equals("n")) {
    			tipo = "N";
    			auxiliar.InserirPersonagem(tipo, this.unidades, this.mapa, PosX, PosY);
    			this.unidades = auxiliar.getUnidade();
    	    	this.mapa = auxiliar.getMapa();
    	    	this.PrintMapa();
    		}
    		else if(tipo.equals("c")) {
    			tipo = "C";
    			auxiliar.InserirPersonagem(tipo, this.unidades, this.mapa, PosX, PosY);
    			this.unidades = auxiliar.getUnidade();
    	    	this.mapa = auxiliar.getMapa();
    	    	this.PrintMapa();
    		}
    	}
    	else {
    		System.out.println("Tipo de Unidade inv·lida!");
    	}
    	
    	
    }

    /**
     * Deleta a Unidade Informada
     * @param id Recebe o Nome/Id da Unidade a ser removida
     */
    public void DeleteUnidade(int id) {
       this.auxiliar.RemoverPersonagem(id, this.unidades, this.mapa);
    }

    /**
     * Funcao para salvar o jogo em arquivo.
     */
    public void SalvarJogo() {
        this.RW.gravarArquivo(this.unidades);
    }
    
    public void LerJogo() {
    	this.unidades = new Aldeao[30];
    	this.unidades = this.RW.LerArquivo();
    	this.SetaMapaUnidades();
    }
    
    /*-----------------------------------------------METODOS PRIVADOS------------------------------------------------------*/

    /**
     * Seta o Mapa com as unidades criadas em suas  respectivas posicoes.
     */
    private void SetaMapaUnidades() {
    	int i;
    	int c, l;
    	String nome;
    	
    	for( i = 0; i < 10; i++) {
    		if(this.unidades[i] != null) {
    			l = this.unidades[i].GetPosX();
        		c = this.unidades[i].GetPosY();
        		nome = "" +  this.unidades[i].getId() + this.unidades[i].getTipoUnidade() + this.unidades[i].GetFrente();
        		this.mapa[l][c] = nome;
    		}
    		
    	}
       
    }
    
    /**
     * Seta o Mapa com o simbolo '-' com as posicoes vazias no mapa.
     */    
    private void SetMapNull() {
    	int i, j;
    	for(i = 0; i < 10; i++) {
    		for(j = 0; j < 10; j++) {
    			this.mapa[i][j] = "-";    			
    		}
    	}
    }
    
    /**
     * Seta o Mapa com as 10
     */   
    private void SetUnidadesStart() {
    	int i,x , y, nome;
    	String frente;
    	for(i = 0; i < 10; i++) {
    		nome = RD.getID();
    		x = RD.getPosX(); y = RD.getPosY();
    		frente = RD.getletraFrente();
    		
    		
    		if(i >= 0 && i < 2) {
    			this.unidades[i] = new Aldeao(nome);
    			this.unidades[i].SetPosXY(x,y);
    			this.unidades[i].setFrente(frente);
    		}
    		else if(i >= 2 && i < 4) {
    			this.unidades[i] = new Navio(nome);
    			this.unidades[i].SetPosXY(x,y);
    			this.unidades[i].setFrente(frente);
    		}
    		else if(i >= 4 && i < 6){
    			this.unidades[i] = new Arqueiro(nome);
    			this.unidades[i].SetPosXY(x,y);
    			this.unidades[i].setFrente(frente);
    		}
    		else if(i >= 6 && i < 8){
    			this.unidades[i] = new Guerreiro(nome);
    			this.unidades[i].SetPosXY(x,y);
    			this.unidades[i].setFrente(frente);
    		}
    		else if(i >= 8 && i < 10){
    			this.unidades[i] = new Cavaleiro(nome);
    			this.unidades[i].SetPosXY(x,y);
    			this.unidades[i].setFrente(frente);
    		}
    		
    		
    		
    	}
    }
    

	
		
	
}