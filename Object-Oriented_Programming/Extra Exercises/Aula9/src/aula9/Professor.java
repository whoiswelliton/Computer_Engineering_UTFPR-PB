
package aula9;

public class Professor extends Pessoa
{
    private String esp;
    private float sal;

    public Professor(String esp, float sal, String nome, int idade, String sexo) {
        super(nome, idade, sexo);
        this.esp = esp;
        this.sal = sal;
    }

    @Override
    public String toString() {
        return "Professor{" + "esp=" + esp + ", sal=" + sal + '}';
    }
    

    public String getEsp() {
        return esp;
    }

    public void setEsp(String esp) {
        this.esp = esp;
    }

    public float getSal() {
        return sal;
    }

    public void setSal(float  sal) {
        this.sal = sal;
    }

    
    
}
