
package aula11;


public class Peixe extends Animal
{
    private String corEscama;
    
    @Override
    public void locomover()
    {
        System.out.println("Nadando");
    }
    @Override
    public void alimentar()
    {
        System.out.println("Comendo Substâncias e Iscas");
    }
    @Override
    public void emitirSom()
    {
        System.out.println("Não emite som");
    }

    public String getCorEscama() {
        return corEscama;
    }

    public void setCorEscama(String corEscama) {
        this.corEscama = corEscama;
    }
    
    
    
}
