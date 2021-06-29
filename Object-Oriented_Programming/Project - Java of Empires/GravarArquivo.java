
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import java.lang.System;

public class GravarArquivo {
	private Aldeao[] unidades;
	
	/**
	 * 
	 * 
	 * @param unidades
	 * vetor contendo todos as unidades
	 */
	public void gravarArquivo(Aldeao[] unidades) {
		if (unidades != null) {
			this.unidades = unidades;
			this.Gravar();
		}
		else {
			System.out.println("Erro! Vetor Vazio");
		}

	}

	public Aldeao[] LerArquivo() {
		this.Ler();
		return this.unidades;
	}

	

	// apagar esse metodo, só para testes
	private void IMPRIME() {

		System.out.println("email do objeto gravar ");
		for (Aldeao unidade : this.unidades) {
			System.out.println(unidade);
		}
		System.out.println("Unidades do Objeto");

	}
	
	private void diminuivetor() {
		int contador = 0;

		// percore o vetor todo e dispensa as posisoes que sao nulas
		for (Aldeao unidade : this.unidades) {
			if (unidade != null) {
				contador++;
			}
		}

		// cria um novo vetor que tera o tamanho "real"
		Aldeao[] novoVetor = new Aldeao[contador];
		int i = 0;

		// Percorre o "novoVetor" armazenando as posisoes "nao nulas" do vetor original
		for (Aldeao newUnidade : this.unidades) {
			if (newUnidade != null) {
				novoVetor[i] = newUnidade;
				i++;
			}
		}

		// A variavel inicial recebe o vetor sem as posisoes nulas
		this.unidades = novoVetor;
		
		this.IMPRIME();
	}

	private void Gravar() {
		
		File arquivo = new File("padrao.dat");
		
		try {
			FileOutputStream fout = new FileOutputStream(arquivo);
			ObjectOutputStream objGravar = new ObjectOutputStream(fout);
			
			objGravar.writeObject(unidades);
			
			objGravar.flush();
			objGravar.close();
			fout.close();
			
		} catch (Exception ex) {
			System.err.println("Erro : " + ex.toString());
		}
	}

	private void Ler() {
		File arquivo = new File("padrao.dat");
		try {
			FileInputStream fin = new FileInputStream(arquivo);
			ObjectInputStream oin = new ObjectInputStream(fin);

			Aldeao[] agendaArq = (Aldeao[]) oin.readObject();
			oin.close();
			fin.close();
			this.unidades = agendaArq;
			
		} catch (Exception ex) {
			System.err.println("erro:" + ex.toString());
		}
	}

}
