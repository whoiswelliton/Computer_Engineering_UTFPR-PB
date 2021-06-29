package simulador;

public class Roda {
    private boolean calibragem;

    public Roda() {
        this.calibragem = false;
    }
    
    public boolean getCalibragem() {
        return calibragem;
    }
    public void setCalibragem() {
        this.calibragem = true;
    }
    public void setEsvaziar() {
        this.calibragem = false;
    }
}
