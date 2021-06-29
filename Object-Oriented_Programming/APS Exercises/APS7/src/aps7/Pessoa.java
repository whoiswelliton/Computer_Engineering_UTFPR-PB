package aps7;

public abstract class Pessoa
{
    private String nome;
    private int ra;

    //metodo concreto
    public void status()
    {
        System.out.println("-----------------------");
        System.out.println("Nome: " + this.nome);
        System.out.println("RA: " + this.ra);
    }
    //metodo abstrato
    public abstract void cargaHoraria (float qtdHoras);
    
    
    public Pessoa( String nome, int ra) {
        
        this.nome = nome;
        this.ra = ra;
    }
    

    public int getRa() {
        return ra;
    }

    public void setRa(int ra) {
        this.ra = ra;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

}
