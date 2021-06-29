package campeonato;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.System;

public class GravarArquivo {
    private Jogador jogadores[] = new Jogador [5];  
    private int cartela[][] = new int [13][5];
    private int size;
    
    /**
	 * 
	 * 
	 * @param jogadores
	 * vetor contendo todos os jogadores
	 */
	public void gravarArquivo(Jogador jogadores[], int cartela[][], int size) {
		if (size != 0) 
                {       
                        this.size = size;
                        
                        for(int k=0; k<this.size; k++)
                        {
                            this.jogadores[k] = jogadores[k];
                        }
                       
                        for(int i=0; i<13; i++)
                        {
                            for(int j=0; j<5; j++)
                            {
                                this.cartela[i][j] = cartela[i][j];
                            }
                        }
                        
			this.Gravar();
		}
		else {
			System.out.println("Erro! Vetor Vazio");
		}

	}
        
        public Jogador[] lerJogadores() {
		this.Ler();
		return this.jogadores;
	}
        public int [][] lerCartela() {
		this.Ler();
		return this.cartela;
	}
        public int lerSize(){
                this.Ler();
                return this.size;
        }
        
        
        private void Gravar() {
		
		File arquivo = new File("savedfile.dat");
		
		try {
			FileOutputStream fout = new FileOutputStream(arquivo);
			ObjectOutputStream objGravar = new ObjectOutputStream(fout);
			
			objGravar.writeObject(jogadores);
                        objGravar.writeObject(cartela);
                        objGravar.writeObject(size);
			
			objGravar.flush();
			objGravar.close();
                        System.out.println("\n\n------------[Salvo no Arquivo]-----------\n\n");
			fout.close();
			
		} catch (Exception ex) {
			System.err.println("Erro : " + ex.toString());
		}
	}
        
        private void Ler() {
            
		File arquivo = new File("savedfile.dat");
                
		try {
			FileInputStream fin = new FileInputStream(arquivo);
			ObjectInputStream oin = new ObjectInputStream(fin);

			this.jogadores = (Jogador[]) oin.readObject();
                        this.cartela = (int [][]) oin.readObject();
                        this.size = (int) oin.readObject();
                        
			oin.close();
			fin.close();
			
		} catch (Exception ex) {
			System.err.println("erro:" + ex.toString());
		}
               
	}
    
}
