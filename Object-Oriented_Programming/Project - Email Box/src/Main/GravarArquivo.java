package Main;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class GravarArquivo {
	private Email[] email;
	private String nomeArquivo;
	
	/**
	 * 
	 * @param nome 
	 * Nome do arquivo a ser gravado
	 * @param email 
	 * vetor contendo todos os emails 
	 */
	public void gravarArquivo(String nome, Email[] email) {
		this.nomeArquivo = nome;
		if (email != null) {
			this.email = email;
			this.diminuivetor();
			this.Gravar();
		}
		else {
			System.out.println("Não há emails cadastrados!!");
		}

	}

	public void LerArquivo(String nome) {
		this.nomeArquivo = nome;
		this.Ler();
	}

	private void diminuivetor() {
		int contador = 0;

		// percore o vetor todo e dispensa as posiçoes que são nulas
		for (Email email2 : this.email) {
			if (email2 != null) {
				contador++;
			}
		}

		// cria um novo vetor que tera o tamanho "real"
		Email[] novoVetor = new Email[contador];
		int i = 0;

		// Percorre o "novoVetor" armazenando as posiçoes "não nulas" do vetor original
		for (Email email3 : this.email) {
			if (email3 != null) {
				novoVetor[i] = email3;
				i++;
			}
		}

		// A variavel inicial recebe o vetor sem as posiçoes nulas
		this.email = novoVetor;
	}

	// apagar esse metodo, só para testes
	private void IMPRIME() {

		System.out.println("email do objeto gravar ");
		for (Email email2 : this.email) {
			System.out.println(email2);
		}
		System.out.println("Email do Objeto");

	}

	private void Gravar() {

		File arquivo = new File(nomeArquivo + ".dat");

		try {
			FileOutputStream fout = new FileOutputStream(arquivo);
			ObjectOutputStream objGravar = new ObjectOutputStream(fout);
			objGravar.writeObject(this.email);
			objGravar.flush();
			objGravar.close();
			fout.close();
		} catch (Exception ex) {
			System.err.println("Erro : " + ex.toString());
		}
	}

	private void Ler() {
		File arquivo = new File(nomeArquivo + ".dat");
		try {
			FileInputStream fin = new FileInputStream(arquivo);
			ObjectInputStream oin = new ObjectInputStream(fin);

			Email[] agendaArq = (Email[]) oin.readObject();
			oin.close();
			fin.close();
			for (Email email : agendaArq) {
				System.out.println(email);
			}

		} catch (Exception ex) {
			System.err.println("erro:" + ex.toString());
		}
	}

}
