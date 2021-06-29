
import java.util.*;

/**
 * 
 */
public class Navio extends Aldeao implements AldeaoSet{
	
	private String frente;
	
	private String tipo = "N";
    /**
     * 
     */
    private static int movimento = 5;

    /**
     * 
     */
    private final int ataqueNv = 100;

    /**
     * Default constructor
     */
    public Navio(int nome) {
    	super(nome);
    }

    /**
     * Seta para onde esta a frente do personagem.
     * @param frente Recebe um valor String : 
     * N (norte)
     * S (sul)
     * L (leste)
     * O (oeste)
     */
    public void SetFrente(String frente) {
    	
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
		return 5;
	}

	@Override
	public int getAtaque() {
		return this.ataqueNv;
	}
    
   
	

	

}