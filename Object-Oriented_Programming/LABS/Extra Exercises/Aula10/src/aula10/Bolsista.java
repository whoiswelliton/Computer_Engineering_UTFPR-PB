package aula10;

public class Bolsista extends Aluno
{
        private float bolsa;

    public Bolsista(float bolsa, int mat, String curso, String nome, int idade, String sexo) {
        super(mat, curso, nome, idade, sexo);
        this.bolsa = bolsa;
    }

    @Override
    public String toString() {
        return "Bolsista{" + "bolsa=" + bolsa + '}';
    }
        
   
    public void renovarBolsa()
    {
         System.out.println("Renovando bolsa de: " + this.getNome());
    }
    
    @Override
    public void pagarMensalidade()
    {
        System.out.println(this.getNome()  + "é bolsista! Pagamento Facilitado*");
    }

    public float getBolsa() {
        return bolsa;
    }

    public void setBolsa(float bolsa) {
        this.bolsa = bolsa;
    }
    
    
    }
