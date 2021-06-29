package jogodosavioes;

public class Motor {
    private String tipoMOTOR;
    public boolean estadoMOTOR;
    public int potenciaMOTOR;

    public Motor(String tipoMOTOR, boolean estadoMOTOR, int potenciaMOTOR) {
        this.tipoMOTOR = tipoMOTOR;
        this.estadoMOTOR = estadoMOTOR;
        this.potenciaMOTOR = potenciaMOTOR;
    }

    public void setEstadoMOTOR(boolean estadoMOTOR) {
        this.estadoMOTOR = estadoMOTOR;
    }

    public void setPotenciaMOTOR(int potenciaMOTOR) {
        this.potenciaMOTOR = potenciaMOTOR;
    }
}
