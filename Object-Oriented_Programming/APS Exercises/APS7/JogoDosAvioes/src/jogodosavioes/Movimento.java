package jogodosavioes;

public class Movimento {
    private String direção;
    private int manche;

    public Movimento(String direção, int manche) {
        this.direção = direção;
        this.manche = manche;
    }

    public void setDireção(String direção) {
        this.direção = direção;
    }

    public void setManche(int manche) {
        this.manche = manche;
    }
   
}
