
import java.util.*;

/**
 * 
 */
public class Cavaleiro extends Aldeao implements AldeaoSet {

    /**
     * Default constructor
     */
    public Cavaleiro(int id) {
    	super(id);
    }

    /**
     * 
     */
    private static int movimento = 4;

    /**
     * 
     */
    private final int ataqueCvl = 5;

    private String tipo = "C";


    /**
     * @param PosX 
     * @param PosY
     */
    @Override
	public void SetPosXY(int PosX, int PosY) {
		super.SetPosXY(PosX, PosY);
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
		return 4;
	}


	@Override
	public int getAtaque() {
		
		return this.ataqueCvl;
	}
    
    
	

}