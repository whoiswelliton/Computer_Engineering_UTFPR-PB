
package aula11;

public class Ave extends Animal
{
    private String corPena;
    
    @Override
    public void locomover()
    {
        System.out.println("Voando");
    }
    @Override
    public void alimentar()
    {
        System.out.println("Comendi insetos");
    }
    @Override
    public void emitirSom()
    {
        System.out.println("Som de Pássaro");
    }

    public String getCorPena() {
        return corPena;
    }

    public void setCorPena(String corPena) {
        this.corPena = corPena;
    }
    
        
}
