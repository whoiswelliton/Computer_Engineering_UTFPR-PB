
import java.util.*;

/**
 * 
 */
public class Arqueiro extends Aldeao implements AldeaoSet {

    private static int movimento = 2;

    private final int ataqueArq = 5;

    private String tipo = "Q";
	
    /**
     * Default constructor
     */
    public Arqueiro( int id) {
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

    public int GetCasasMovimento() {
    	return this.movimento;
    }
    
    @Override
    public String getTipoUnidade() {
    	return this.tipo;
    }


	@Override
	public int getLevel() {
		return 2;
	}

	@Override
	public int getAtaque() {
		return this.ataqueArq;
	}
    

	

}