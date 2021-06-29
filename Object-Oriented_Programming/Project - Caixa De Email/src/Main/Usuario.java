package Main;

public class Usuario {
	private String nome;
	
	//nao teremos construtor vazio, pois todo usuário "DEVEE" CONTER UM NOME
	
	public Usuario(String nome) {
		if(nome != null) {
			this.nome = nome;
		}
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String e) {
		this.nome = e;
	}

}
