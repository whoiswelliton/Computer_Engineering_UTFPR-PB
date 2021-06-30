
package aula9;


public class Aluno extends Pessoa 
{
    private int mat;
    private String curso;

    public Aluno(int mat, String curso, String nome, int idade, String sexo) {
        super(nome, idade, sexo);
        this.mat = mat;
        this.curso = curso;
    }

    @Override
    public String toString() {
        return "Aluno{" + "mat=" + mat + ", curso=" + curso + '}';
    }
    
    
    
    public void cancelaMat()
    {
            System.out.println("Matrícula Cancelada!");
    }

    public int getMat() {
        return mat;
    }

    public void setMat(int mat) {
        this.mat = mat;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }
    
    
}
