package Main;

import java.io.Serializable;

public class Email implements Serializable {
	
	private String de;
	private String para;
	private String assunto;
	private String mensagem;
	
//	nao teremos construtor vazio, pois todo email DEVE ter todos os parametros: de, para, assunto, mensagem
	/**
	 * 
	 * @param de
	 * @param para
	 * @param assunto
	 * @param mensagem
	 */
	
	public Email (String de, String para, String assunto, String mensagem) {
		if((de != null) && (para != null) && (assunto != null) && (mensagem != null)) {
			this.de = de; this.para = para;	this.assunto = assunto; this.mensagem = mensagem;
		}
	}
	
	public String getDe() {
		return this.de;
	}
	public String getPara() {
		return this.para;
	}
	public String getAssunto() {
		return this.assunto;
	}
	public String getMensagem() {
		return this.mensagem;
	}
	
	
	public void setDe(String e) {
		this.de = e;
	}
	public void setPara(String e) {
		this.para = e;
	}
	public void setAssunto(String e) {
		this.assunto = e;
	}
	public void setMensagem(String e) {
		this.mensagem = e;
	}
	
	public String toString() {
		return "====================================\n"
	+"Remetente: " + this.de + "\nDestinatario: " + 
				this.para + "\nAssunto: " + this.assunto + "\nMensagem: " + this.mensagem + 
	"\n" + "====================================\n";
		
	}
	
	

}
