package aps9;

public class Aluno extends Pessoa
{
    private float coeficiente;
    private boolean bolsista;
    private int numMaterias;
    public String curso;

    public Aluno(float coeficiente, boolean bolsista, int numMaterias, String curso, String nome, int ra) {
        super(nome, ra);
        this.coeficiente = coeficiente;
        this.bolsista = bolsista;
        this.numMaterias = numMaterias;
        this.curso = curso;
    }
    
    
    public void status2()
    {
        status();
        System.out.println("Curso: " + this.curso);
        System.out.println("Coeficiente: " + this.coeficiente);
        System.out.println("Bolsista: " + this.bolsista);
        System.out.println("Matérias " + this.numMaterias);
    }
    
   public void cargaHoraria (float qtdHoras)
   {
       System.out.println(this.getNome() + " passa " + qtdHoras + " horas na universidade");
   }

    public float getCoeficiente() {
        return coeficiente;
    }

    public void setCoeficiente(float coeficiente) {
        this.coeficiente = coeficiente;
    }

    public boolean isBolsista() {
        return bolsista;
    }

    public void setBolsista(boolean bolsista) {
        this.bolsista = bolsista;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }
   
   
}
