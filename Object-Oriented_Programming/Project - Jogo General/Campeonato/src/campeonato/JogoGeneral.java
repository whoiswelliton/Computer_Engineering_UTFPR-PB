package campeonato;
import java.io.Serializable;

public class JogoGeneral implements Serializable{
	private Dado dados[]= new Dado[5];
	private int jogadas[]= new int[13];
	
	public JogoGeneral(){ // Metodo construtor, Cria-se 5 dados com 6 faces; e inicia-se o vetor jogadas com zero em todas as posições
		for(int i=0; i<5; i++){
			this.dados[i]= new Dado(6);
		}
		zerarJogadas();
	}
	public void zerarJogadas(){ // Zerar o contador de jogadas
		for(int i=0; i<13; i++){
			this.jogadas[i]=0;
		}
	}
	public void marcarJogada(int n){ // marcar uma jogada no contador de jogadas
		this.jogadas[n]=1;	
	}
	public boolean verificarJogadaMarcada(int n){  // verifica se a jogada escolhida ja foi feita
		return this.jogadas[n]==1;
	}
	public void imprimirJogadas(){ // Imprimi quais jogadas foram marcadas e quais estao disponiveis
		System.out.println("1\t2\t3\t4\t5\t6\t7(T)\t8(Q)\t9(F)\t10(S+)\t11(S-)\t12(G)\t13(X)");
		for(int i=0; i<13; i++){
			if(verificarJogadaMarcada(i)==true){
				System.out.print("X\t");
			}
			else{
				System.out.print("--\t");
			}
		}
		System.out.println("");
	}
	public void jogarDados(){  // rolar os dados
		for(int i=0; i<5; i++){
			this.dados[i].roll();		
		}	
	}
	public void imprimirDados(){  // imprimir os valores dos dados
		for(int i=0; i<5; i++){
			System.out.print (this.dados[i].getSideUp());
			if(i<4){
				System.out.print ("-");
			}
		}
		System.out.println ("");
	}
	public int jogadaUmSeis(int n){		// verifica se as jogadas escolhidas entre jogada um e jogada seis e compativel com os numeros nos dados
		int cont=0;							// e retorna a pontuação da jogada
		for(int i=0; i<5; i++){
			if(this.dados[i].getSideUp() == n){
				cont++;
			}
		}
		return cont;		
	}
	public int trinca(){	// verifica se obteve uma combinaçao trinca e retorna a pontuação
		int arr[]={0,0,0,0,0};
		int cont[]={0,0,0,0,0,0};
		int pontos=0;
		for(int i=0; i<5; i++){
			arr[i] = this.dados[i].getSideUp();
			if(arr[i] == 1){
				cont[0]++;
			}
			else if(arr[i] == 2){
				cont[1]++;
			}
			else if(arr[i] == 3){
				cont[2]++;
			}
			else if(arr[i] == 4){
				cont[3]++;
			}
			else if(arr[i] == 5){
				cont[4]++;
			}
			else{
				cont[5]++;
			}
		}
		for(int i=0; i<6; i++){
			if(cont[i]==3){
				pontos = arr[0]+arr[1]+arr[2]+arr[3]+arr[4];			
			}
		}		
		return pontos;
	}
	public int quadra(){ 	// verifica se obteve uma combinaçao quadra e retorna a pontuação
		int arr[]={0,0,0,0,0};
		int cont[]={0,0,0,0,0,0};
		int pontos=0;
		for(int i=0; i<5; i++){
			arr[i] = this.dados[i].getSideUp();
			if(arr[i] == 1){
				cont[0]++;
			}
			else if(arr[i] == 2){
				cont[1]++;
			}
			else if(arr[i] == 3){
				cont[2]++;
			}
			else if(arr[i] == 4){
				cont[3]++;
			}
			else if(arr[i] == 5){
				cont[4]++;
			}
			else{
				cont[5]++;
			}
		}
		for(int i=0; i<6; i++){
			if(cont[i]==4){
				pontos = arr[0]+arr[1]+arr[2]+arr[3]+arr[4];
			}
		}		
		return pontos;
	
	}
	public int fullHouse(){ // verifica se obteve uma combinaçao full house e retorna a pontuação
		int arr[]=new int[5];
		int cont[]={0,0,0,0,0,0};
		int cont1=0;
		for(int i=0; i<5; i++){
			arr[i] = this.dados[i].getSideUp();
			if(arr[i] == 1){
				cont[0]++;
			}
			else if(arr[i] == 2){
				cont[1]++;
			}
			else if(arr[i] == 3){
				cont[2]++;
			}
			else if(arr[i] == 4){
				cont[3]++;
			}
			else if(arr[i] == 5){
				cont[4]++;
			}
			else{
				cont[5]++;
			}
		}
		for(int i=0; i<5; i++){
			if(cont[i]==2){
				cont1+=5;
			}
			if(cont[i]==3){
				cont1+=2;
			}
		}
		if(cont1 == 7){
			return 25;
		}		
		return 0;
	}
	public int sequenciaMaior(){ // verifica se obteve uma combinaçao sequencia maior 2,3,4,5,6 e retorna a pontuação
		int arr[]=new int[5];
		for(int i=0; i<5; i++){
			arr[i]=this.dados[i].getSideUp();
		}
		int n = 5;
		for (int i=0; i<n-1; i++){   // Utiliza o algoritmo bubble sort para ordenar o vetor
			for (int j = 0; j < n-i-1; j++){
				if (arr[j] > arr[j+1]){
				    int temp = arr[j]; 
					arr[j] = arr[j+1]; 
				    arr[j+1] = temp; 
				}
			}
		}	
		if(arr[0]==2 && arr[1]==3 && arr[2]==4 && arr[3]==5 && arr[4]==6){
			return 30;
		}
		else{
			return 0;
		}
	}
	public int sequenciaMenor(){  // verifica se obteve uma combinaçao sequencia menor 1,2,3,4,5  e retorna a pontuação
		int arr[]=new int[5];
		for(int i=0; i<5; i++){
			arr[i]=this.dados[i].getSideUp();
		}
		int n = 5;
		for (int i=0; i<n-1; i++){	// Utiliza o algoritmo bubble sort para ordenar o vetor
			for (int j = 0; j < n-i-1; j++){
				if (arr[j] > arr[j+1]){
				    int temp = arr[j]; 
					arr[j] = arr[j+1]; 
				    arr[j+1] = temp; 
				}
			}
		}	
		if(arr[0]==1 && arr[1]==2 && arr[2]==3 && arr[3]==4 && arr[4]==5){
			return 40;
		}
		else{
			return 0;
		}
	
	}
	public int general(){  // verifica se obteve uma combinaçao general, onde todos os dados sao iguais e retorna a pontuação
		int arr[]=new int[5];
		int cont=0;
		for(int i=0; i<5; i++){
			arr[i]=this.dados[i].getSideUp();
		}
		for(int i=0; i<4; i++){
			if(arr[i] == arr[i+1]){
				cont++;
			}
		}
		if(cont==4){
			return 50;
		}
		else{
			return 0;
		}
	
	}
	public int jogadax(){ // retorna a soma de todos os dados como pontuação
		int pontos=0;
		for(int i=0; i<5; i++){
			pontos += this.dados[i].getSideUp();
		}
		return pontos;
	}

	public int verificarPontos(int n){ // verifica se a jogada escolhida para marcar é valida, retorna a pontuaçao caso valida
		if(n==1){ 						//zero caso seja invalida
				int i=jogadaUmSeis(1);
				if( i!=0 ){
					return i*1;
				}
				else{
					return 0;
				}
		}
		else if(n==2){
				int i=jogadaUmSeis(2);
				if( i!=0 ){
					return i*2;
				}
				else{
					return 0;
				}
		}
		else if(n==3){
				int i=jogadaUmSeis(3);
				if( i!=0 ){
					return i*3;
				}
				else{
					return 0;
				}
		}
		else if(n==4){
				int i=jogadaUmSeis(4);
				if( i!=0 ){
					return i*4;
				}
				else{
					return 0;
				}
		}
		else if(n==5){
				int i=jogadaUmSeis(5);
				if( i!=0 ){
					this.jogadas[4]=1;
					return i*5;
				}
				else{
					return 0;
				}
		}
		else if(n==6){
				int i=jogadaUmSeis(6);
				if( i!=0 ){
					return i*6;
				}
				else{
					return 0;
				}
		}
		else if(n==7){       
				int i=trinca();
				if( i!=0 ){
					return i;
				}
				else{
					return 0;
				}
		}
		else if(n==8){
				int i=quadra();
				if( i!=0 ){
					return i;
				}
				else{
					return 0;
				}
		}
		else if(n==9){
				int i=fullHouse();
				if( i!=0 ){
					return i;
				}
				else{
					return 0;
				}
		}	
		else if(n==10){  
				int i=sequenciaMaior();
				if( i!=0 ){
					return i;
				}
				else{
					return 0;
				}
		}	
		else if(n==11){
				int i=sequenciaMenor();
				if( i!=0 ){
					return i;
				}
				else{
					return 0;
				}
		}
		else if(n==12){
				int i=general();
				if( i!=0 ){
					return i;
				}
				else{
					return 0;
				}
		}
		else{
			int i=jogadax();
			if( i!=0 ){
				return i;
			}
			else{
				return 0;
			}
		}
	}
}
