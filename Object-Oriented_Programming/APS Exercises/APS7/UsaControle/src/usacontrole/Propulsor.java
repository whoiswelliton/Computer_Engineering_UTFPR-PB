package usacontrole;

/**
 *
 * @author WELLITON LEAL (W)
 */
public class Propulsor {
    private int potencia;
    private boolean estadop;

    public Propulsor(int potencia, boolean estadop) {
        this.potencia = potencia;
        this.estadop = estadop;
    }

    public int getPotencia() {
        return potencia;
    }

    public void setPotencia(int potencia) 
    {
        if((this.potencia + potencia >= 0) && (this.potencia + potencia <= 100))
        {
            this.potencia += potencia;      
        }
    }

    public boolean getEstadop() {
        return estadop;
    }

    public void setEstadop(boolean estadop) {
        this.estadop = estadop;
    }
    
    
}
