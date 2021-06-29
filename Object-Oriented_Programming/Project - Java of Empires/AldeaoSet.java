
import java.util.*;

/**
 * 
 */
public interface AldeaoSet {

    
    /**
     * Esse metodo serve para retornar o level do Personagem.
     * Sendo eles: 
     * Aldeao (1)
     * Arqueiro (2)
     * Guerreiro (3)
     * Cavaleiro (4)
     * Navio (5)
     */
    public int getLevel();
    
    /**
     * Esse metodo serve para retornar o alcance de ataque do Personagem.
     * Sendo eles: 
     * Aldeao (1)
     * Arqueiro (5)
     * Guerreiro (3)
     * Cavaleiro (5)
     * Navio (100)
     */    
    public int getAtaque();
    

    /**
     * @param PosX posicao X do personagem
     * @param PosY posicao Y do personagem
     */
	public void SetPosXY(int PosX, int PosY);

   
}