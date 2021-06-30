
package aula7;


public class Lutador {
    private String nome, nacionalidade, categoria;
    private int idade, vitorias, derrotas, empates;
    private float altura, peso;
    
    public void apresentar()
    {
        System.out.println("----------------------------------");
        System.out.println("LUTADOR:" + this.getNome());
        System.out.println("NACIONALIDADE: " + this.getNacionalidade());
        System.out.println("ALTURA: " + this.getAltura());
        System.out.println("PESO: " + this.getPeso());
        System.out.println("VITÓRIAS: " + this.getVitorias());
        System.out.println("DERROTAS: " + this.getDerrotas());
        System.out.println("EMPATES: " + this.getEmpates());
        
    }
    public void status()
    {
        System.out.println("============== STATUS ATUALIZADO ============");
        System.out.println(this.getNome());
        System.out.println("CATEGORIA: " + this.getCategoria());
        System.out.println("GANHOU: " + this.getVitorias() + " Vezes");
        System.out.println("PERDEU: " + this.getDerrotas() + " Vezes");
        System.out.println("EMPATOU: " + this.getEmpates() + " Vezes");
    }
    public void ganharLuta ()
    {
        this.setVitorias(this.getVitorias() + 1);
        //this.vitorias = this.vitorias + 1;
    }
    public void perderLuta()
    {
        this.setDerrotas(this.getDerrotas() + 1);
    }
    public void empatarLuta()
    {
        this.setEmpates(this.getEmpates() + 1);
    }

    public Lutador(String nome, String nacionalidade, int idade, int vitorias, int derrotas, int empates, float altura, float peso) {
        this.nome = nome;
        this.nacionalidade = nacionalidade;
        this.idade = idade;
        this.vitorias = vitorias;
        this.derrotas = derrotas;
        this.empates = empates;
        this.altura = altura;
        this.setPeso(peso);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNacionalidade() {
        return nacionalidade;
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }

    public String getCategoria() {
        return categoria;
    }

    private void setCategoria() {
        if(this.peso < 52.2)
        {
            this.categoria = "Invalido";
        }
        else if(this.peso <= 78.3 && this.peso > 52.2)
        {
            this.categoria = "Leve";
        }
        else if(this.peso > 78.3 && this.categoria <= 83.9)
        {
            this.categoria = "Médio";
        }
        else if (this.peso > 83.9 && this.peso <= 120.2)
        {
            this.categoria = "Pesado";
        }
        else
        {
            this.categoria = "Invalido";
        }
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getVitorias() {
        return vitorias;
    }

    public void setVitorias(int vitorias) {
        this.vitorias = vitorias;
    }

    public int getDerrotas() {
        return derrotas;
    }

    public void setDerrotas(int derrotas) {
        this.derrotas = derrotas;
    }

    public int getEmpates() {
        return empates;
    }

    public void setEmpates(int empates) {
        this.empates = empates;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
        this.setCategoria();
    }
    
    
    
}
