public class Auxiliar {
	private String direcao;

	private Aldeao selecionado;// unidade a ser movida

	private Aldeao[] unidades;

	private String[][] Mapa;

	private int id;// id da unidade
	
	private Randomico rand = new Randomico(); //Esse objeto gera ids, posiçoes aleatórios

	public void Movimenta(int id, String direcao, Aldeao[] Vetor, String[][] Mapa){
		this.unidades = Vetor;
		this.Mapa = Mapa;
		this.id = id; 
		this.direcao = direcao;
		this.selecionado = this.ExisteUnidade();
		                    
		
		if(this.selecionado == null) {
			System.out.println("Unidade não Existe.");	
		}
		else {
			if((this.direcao.equals("N") && this.selecionado.GetPosX() == 0) || (this.direcao.equals("S") && this.selecionado.GetPosX() == 9)){
					System.out.println("Limite da Arena - Movimento Inválido.");
			}
			else if((this.direcao.equals("O") && this.selecionado.GetPosY() == 0) || (this.direcao.equals("L") && this.selecionado.GetPosY() == 9)) {
				System.out.println("Limite da Arena - Movimento Inválido.");
			}
			else {
				this.VerificaMapaPos();
			}
		}
	}
		
	public Aldeao[] getUnidade() {
		return this.unidades;
	}

	public String[][] getMapa() {
		return this.Mapa;
	}
	
	public void Atacar(int id, Aldeao[] Vetor, String[][] Mapa) {
		this.id = id;
		this.Mapa = Mapa;
		this.unidades = Vetor;
		this.selecionado = this.ExisteUnidade();
		
		
		
		if(this.selecionado != null) {
			this.direcao = this.selecionado.GetFrente();
			if(this.selecionado.getTipoUnidade().equals("A")){
				this.direcao = this.selecionado.GetFrente();
				this.Ataque();//funcao que percorre a matriz e realiza as operacoes
			}
			
			/*O arqueiro ataca a sua frente com alcance de 5 posicoes e pode abater 
			 * apenas aldeoes e outros arqueiros. 
			 * Caso outros personagens mais fortes estejam na direcao do ataque, os
			 * mesmos nao serao abatidos*/
			else if(this.selecionado.getTipoUnidade().equals("Q")) {
				this.Ataque();
			}
			
			/*guerreiro ataca em duas direcoes, a frente e a direita*/
			else if(this.selecionado.getTipoUnidade().equals("G")) {
				if(this.direcao.equals("N")){
					this.Ataque();
					this.direcao = "L";
					this.Ataque();
				}
				else if(this.direcao.equals("S")) {
					this.Ataque();
					this.direcao = "O";
					this.Ataque();
				}
				else if(this.direcao.equals("L")) {
					this.Ataque();
					this.direcao = "S";
					this.Ataque();
				}
				else if(this.direcao.equals("O")) {
					this.Ataque();
					this.direcao = "N";
					this.Ataque();
				}
			}
			
			/*O cavaleiro ataca em tres direcoes, a frente, a direita e  a esquerda*/
			else if(this.selecionado.getTipoUnidade().equals("C")) {
				if(this.direcao.equals("N")){
					this.Ataque();
					this.direcao = "L";
					this.Ataque();
					this.direcao = "O";
					this.Ataque();
				}
				else if(this.direcao.equals("S")) {
					this.Ataque();
					this.direcao = "O";
					this.Ataque();
					this.direcao = "L";
					this.Ataque();
				}
				else if(this.direcao.equals("L")) {
					this.Ataque();
					this.direcao = "S";
					this.Ataque();
					this.direcao = "N";
					this.Ataque();
				}
				else if(this.direcao.equals("O")) {
					this.Ataque();
					this.direcao = "N";
					this.Ataque();
					this.direcao = "S";
					this.Ataque();
				}
			}
			/*O navio ataca em quatro dire¸c˜oes, norte, sul, leste e oeste*/
			else if(this.selecionado.getTipoUnidade().equals("N")) {
				this.direcao = "N";
				this.Ataque();
				this.direcao = "S";
				this.Ataque();
				this.direcao = "O";
				this.Ataque();
				this.direcao = "L";
				this.Ataque();
			}
			
			
		}
		else {
			System.out.println("Esta Unidade não existe!");
		}
		
    }
	
	public void RemoverPersonagem(int id, Aldeao[] Vetor, String[][] Mapa) {
		Aldeao aux;
		this.unidades = Vetor;
		this.Mapa = Mapa;
		this.id = id;
		aux = this.ExisteUnidade();
		if(aux!= null) {
			this.ExcluirUnidade(aux.getId());
			System.out.println("Unidade com id: " + this.id + ", foi removida com sucesso!");
		}
		else {
			System.out.println("Não existe a unidade com esse ID.");
		}
	}

	
	public void InserirPersonagem(String tipo, Aldeao[] unidades, String[][] Mapa, int x, int y) {
		this.unidades = unidades;
		this.Mapa = Mapa;
		this.direcao = tipo;//reutilizacao do atributo só para guardar o tipo da unidade(Arqueiro, Aldeoa, ...)
		int i;
		this.selecionado = null;
		
		//caso não haja nenhuma unidade na posicao solicitada para inserçao
		if(this.Mapa[x][y].equals("-")){
			//verifica se o vetor unidades ainda tem espaco, sendo que o limite é 30
			for(i = 0; i < this.unidades.length; i++) {
				if(this.unidades[i] == null) {
					this.selecionado = unidades[i]; //reaproveitamento do atributo, para guardar a posicao no vetor que esta vazia
					if(this.SetaUnidade(x, y)) {
						this.unidades[i] = this.selecionado;
						System.out.println("Unidade Criada com Sucesso, verifique no Mapa. Sua id é: " + this.selecionado.getId());
						return;
					}
					else {
						System.out.println("Erro ao criar unidade, por favor contate o administrador do sistema.");
						return;
					}
				}
			}
			//caso saia do for e o selecionado seja nulo, significa que no vetor unidades não havia uma posicao nulla, ou seja vazia
			if(this.selecionado == null) {
				System.out.println("Infelizamente não há mais espacos para inserir novas unidades.");
			}
		}
		//caso exista uma unidade na posicao
		else {
			System.out.println("Desculpe, nessas coordenadas ja existe uma unidade alocada. Por favor escolha outra posica.");
		}
		
	}
	
	
	
	/*-----------------------------------------------METODOS PRIVADOS------------------------------------------------------*/
	
	private boolean ExcluirUnidade(int idExclui) {
		int i;
		for (i = 0; i < this.unidades.length; i++) {
			if(this.unidades[i] != null) {
				if (this.unidades[i].getId() == idExclui) {
					this.Mapa[unidades[i].GetPosX()][unidades[i].GetPosY()] = "-";
					this.unidades[i] = null;
					return true;
				}
			}
		}
		return false;
	}
	/*
	 * Esse metodo aloca a nova unidade no mapa, e no vetor unidades
	 */
	private boolean SetaUnidade(int x, int y) {
		this.id = this.rand.getID();//recebe um id
		System.out.println("NOVO ID: " + this.id);
		String frente = this.rand.getletraFrente();//recebe uma orientacao aleatoria
		
		//variavel direcao tem guardado o TIPO do personage, Aldeao(A), Arqueiro(Q), etc...
		if(this.direcao.equals("A")) {
			this.selecionado = new Aldeao(id);
		}
		else if(this.direcao.equals("Q")) {
			this.selecionado = new Arqueiro(this.id);
		}
		else if(this.direcao.equals("G")) {
			this.selecionado = new Guerreiro(this.id);
		}
		else if(this.direcao.equals("N")) {
			this.selecionado = new Navio(this.id);
		}
		else {
			this.selecionado = new Cavaleiro(this.id);
		}
		
		if(this.selecionado != null) {
			this.selecionado.setFrente(frente);
			this.selecionado.SetPosXY(x, y);
			this.Mapa[x][y] = "" + this.selecionado.getId() + this.selecionado.getTipoUnidade() + this.selecionado.GetFrente();
			return true;
		}
		else {
			return false;
		}
		
	}
	
	private void Ataque() {
		Aldeao aux;
		int k, w; //indices percorrer matriz
		int alcance = this.selecionado.getAtaque();
		int i = this.selecionado.GetPosX();
		int j = this.selecionado.GetPosY();
		String frente = this.direcao;
		 
		
			if(frente.equals("N")) {
				k = i;
				//para o ataque o da matriz diminui
				while((k >= (i-alcance)) && (k >= 0)) {
					if(this.Mapa[k][j].equals("-") == false) {
						this.id = getIDMapa(k, j);
						aux = this.ExisteUnidade();
						if(aux != null) {
							if(aux.getId() != this.selecionado.getId()) {
								if(aux.getLevel() <= this.selecionado.getLevel()) {
									this.ExcluirUnidade(aux.getId());
								}
							}
						}
					}
					k--;
				}
			}
			else if(frente.equals("S")) {
				k = i;
				//para o ataque o da matriz diminui
				while((k <= (i+alcance)) && (k <= 9)) {
					if(this.Mapa[k][j].equals("-") == false) {
						this.id = getIDMapa(k, j);
						aux = this.ExisteUnidade();
						if(aux != null) {
							if(aux.getId() != this.selecionado.getId()) {
								if(aux.getLevel() <= this.selecionado.getLevel()) {
									this.ExcluirUnidade(aux.getId());
								}
							}
						}
					}
					k++;
				}
			}
			else if(frente.equals("L")) {
				k = j;
				//para o ataque o da matriz diminui
				while((k <= (j+alcance)) && (k <= 9)) {
					if(this.Mapa[i][k].equals("-") == false) {
						this.id = getIDMapa(i, k);
						aux = this.ExisteUnidade();
						if(aux != null) {
							if(aux.getId() != this.selecionado.getId()) {
								if(aux.getLevel() <= this.selecionado.getLevel()) {
									this.ExcluirUnidade(aux.getId());
								}
							}
						}
					}
					k++;
				}
			}
			if(frente.equals("O")) {
				k = j;
				//para o ataque o da matriz diminui
				while((k >= (j-alcance)) && (k >= 0)) {
					if(this.Mapa[i][k].equals("-") == false) {
						this.id = getIDMapa(i, k);
						aux = this.ExisteUnidade();
						if(aux != null) {
							if(aux.getId() != this.selecionado.getId()) {
								if(aux.getLevel() <= this.selecionado.getLevel()) {
									this.ExcluirUnidade(aux.getId());
								}
							}
						}
					}
					k--;
				}
			}
			
	}
	
	
	/**
	 * Retorna o id do personagem na posicao solicitada
	 * @param i linha da matriz
	 * @param j coluna da matriz
	 * @return int : Id do personagem 
	 */
	private int getIDMapa(int i, int j) {
		if(this.Mapa[i][j].equals("-") == false) {
			String id = this.Mapa[i][j].substring(0, 2);//pega o id do personagem
			int idConvert = Integer.valueOf(id);//transforma em inteiro
			return idConvert;
		}
		return -1;
	}

	/**
	 * Retorna a Unidade se Existir
	 */
	private Aldeao ExisteUnidade() {
		int i;
		for (i = 0; i < this.unidades.length; i++) {
			if (this.unidades[i] != null) {
				if (this.unidades[i].getId() == this.id) {
					return this.unidades[i];
				}
			}
			
		}
		return null;
	}
	
	/**
	 * Verifica a Existencia de outras unidades na direçao do movimento
	 */
	private void VerificaMapaPos() {
		int i = this.selecionado.GetCasasMovimento();//recebe como a unidade em questao anda pelo mapa
		//coordenadas da unidade a mover
		int y = this.selecionado.GetPosY();//posicao da coluna da matriz
		int x = this.selecionado.GetPosX();//posicao da linha da matriz
		

		
		/**************MOVIMENTO PARA CIMA *********************/
		if(this.direcao.equals("N")) {
			if((x-i) < 10 && (x-i) >= 0) {
				this.SetMovPos((x-i), y);
			}
			else {
				if(x-i< 0) {
					this.SetMovPos(0, y);
				}
			}
		}
		
		/**************MOVIMENTO PARA BAIXO *********************/
		else if(this.direcao.equals("S") == true) {
			if((x+i) < 10 && (x+i) >= 0) {
				this.SetMovPos(x+i, y);
			}
			else {
				if(i+x > 10) {
					this.SetMovPos(9, y);
				}
			}	
		}
		
		/**************MOVIMENTO PARA LADO ESQUERDO *********************/
		else if(this.direcao.equals("O")) {
			if((y-i) < 10 && (y-i) >= 0) {
				this.SetMovPos(x, y-i);
			}
			else {
				if(x-i < 0) {
					this.SetMovPos(x, 0);
				}
			}	
		}
		
		/**************MOVIMENTO PARA LADO DIREITO *********************/
		else if(this.direcao.equals("L")) {
			if((y+i) < 10 && (y+i) >= 0) {
				this.SetMovPos(x, (i+y));
			}
			else {
				if(i+x > 10) {
					this.SetMovPos(x, 9);
				}
			}	
		}
	}
	/*
	 * Esse metodo serve apenas para em certa posicao do mapa verificar se tem uma unidade
	 * e fazer as operacoes convenientes
	 */
	private void SetMovPos(int i, int j) {
		Aldeao aux; //caso haja uma unidade no mapa em determinada posicao essa variavel guarda
		String vazio ="-";
		
		if(this.Mapa[i][j].equals(vazio) == false) {
			this.id = this.getIDMapa(i, j);//transforma em inteiro
			aux = this.ExisteUnidade();//verifica se a unidade existe
			if(aux != null) {
				//nivel do personagem que esta na posicao e maior de quem esta sendo movido
				if(aux.getLevel() > this.selecionado.getLevel()) {
					if(this.ExcluirUnidade(this.selecionado.getId())) {
						System.out.println("Sua Unidade foi Excluida! Há uma unidade mais forte na posicao destino.");
					}
				}
				else {
					System.out.println("Movimento Inválido: A posicao esta ocupada por outra Unidade.");
				}
			}
			}

		else {
			this.selecionado.setFrente(this.direcao);
			//atualiza o Mapa
			this.Mapa[i][j] = "" + this.selecionado.getId() + this.selecionado.getTipoUnidade() + this.selecionado.GetFrente();
			this.Mapa[this.selecionado.GetPosX()][this.selecionado.GetPosY()] = "-";
			//atualiza a posicao da unidade
			this.selecionado.SetPosXY(i, j);
		}
	}
}
			
		
	