package campeonato;
import java.io.Serializable;
import java.util.Random;

public class Dado implements Serializable{
	private int numberfaces; // quantidade de faces que o dado tem
	private int SideUp;		// face que caiu virada para cima

	public Dado (){ // Metodo construitor que incia um dado com 6 faces
		this.numberfaces=6;
	}
	public Dado(int n){  // Metodo construitor que incia o dado com a quantidade de faces informada
		this.numberfaces=n;	
	}
	public void roll(){  // Metodo que simula jogar um dado retornando o valor da face para cima
		Random x=new Random();
		this.SideUp = x.nextInt(this.numberfaces) + 1;
	}
	public int getSideUp (){ // Metodo que retorna a face que esta para cima
		return SideUp;
	}
	public String toString(){  // Metodo Que imprimi o valor da face
		return ""+this.SideUp; 
	}
}
