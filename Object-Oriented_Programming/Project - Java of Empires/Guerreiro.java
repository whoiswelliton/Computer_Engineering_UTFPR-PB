
import java.util.*;

/**
 * 
 */
public class Guerreiro extends Aldeao implements AldeaoSet {

    /**
     * 
     */
    private static int movimento = 3;

    /**
     * 
     */
    private final int ataqueGrr = 3;
    
    private String tipo = "G";
    
    /**
     * Default constructor
     */
    public Guerreiro(int id) {
    	super(id);    
    }

    /**
     * @param PosX 
     * @param PosY
     */
    @Override
	public void SetPosXY(int PosX, int PosY) {
		super.SetPosXY(PosX, PosY);
	}
    

    /**
     * Esse metodo serve para desferir ataque atraves da unidade selecionada, cada personagem tem sua propria configuração de ataque.
     * @param ataque Se for tue então o ataque é desferido, caso contrario não.
     */
    public void Atacar(boolean ataque) {
        // TODO implement here
    }
    
    public int GetCasasMovimento() {
    	return this.movimento;
    }
    
    @Override
    public String getTipoUnidade() {
    	return this.tipo;
    }

	@Override
	public int getLevel() {
		return 3;
	}

	@Override
	public int getAtaque() {
		return this.ataqueGrr;
	}

    


}