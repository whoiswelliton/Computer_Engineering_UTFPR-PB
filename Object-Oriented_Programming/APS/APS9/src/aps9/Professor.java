package aps9;

public class Professor extends Pessoa
{
    private float salario;
    private int numMaterias;
    public String departamento;

    public Professor(float salario, int numMaterias, String departamento, String nome, int ra) {
        super(nome, ra);
        this.salario = salario;
        this.numMaterias = numMaterias;
        this.departamento = departamento;
    }

    
    public void status2()
    {
        status();
        System.out.println("Departamento: " + this.departamento);
        System.out.println("Salario: " + this.salario);
        System.out.println("Matérias " + this.numMaterias);
    }
    
  
    @Override
   public void cargaHoraria (float qtdHoras)
   {
       System.out.println(this.getNome() + " passa " + qtdHoras + " horas na universidade");
   }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public int getNumMaterias() {
        return numMaterias;
    }

    public void setNumMaterias(int numMaterias) {
        this.numMaterias = numMaterias;
    }

    public String getDepartamento() {
        return departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }
   
}
