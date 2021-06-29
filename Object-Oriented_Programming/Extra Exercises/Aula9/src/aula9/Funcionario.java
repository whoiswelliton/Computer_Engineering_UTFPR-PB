
package aula9;

public class Funcionario extends Pessoa
{
    private String setor;
    private boolean trab;

    public Funcionario(String setor, boolean trab, String nome, int idade, String sexo) {
        super(nome, idade, sexo);
        this.setor = setor;
        this.trab = trab;
    }

    @Override
    public String toString() {
        return "Funcionario{" + "setor=" + setor + ", trab=" + trab + '}';
    }
    
    
    
    public void MudarTrab ()
    {
        this.trab =! this.trab;
    }

    public String getSetor() {
        return setor;
    }

    public void setSetor(String setor) {
        this.setor = setor;
    }

    public boolean isTrab() {
        return trab;
    }

    public void setTrab(boolean trab) {
        this.trab = trab;
    }
    
    
}
