import java.util.Random;

/**
 * Retorna um valor randomico de 0 a 10. Diferenciado para X e Y
 */
public class Randomico {

	private static int ID = 10;
    
    private Random x = new Random();
    
    private int posX;
    private int posY;
    
    
    
    /**
     *  recebe uma valor aleatório entre 0 e 9 para o eixo X da posicao
     * @return doubel posX
     */
    public int getPosX() {
    	this.posX = x.nextInt(10);
        return posX;
    }
   


	/**
     * recebe uma valor aleatório entre 0 e 9 para o eixo Y da posicao
     * @return double posY
     */
    public int getPosY() {
    	this.posY = x.nextInt(10);
        return posY;
    }
    
     /**
    * Para gerar ID's de cada personagem de forma ordenada
    * @return int ID
   */
    public int getID() {
        ID++;
        return ID;
    }
    
    /**
     * Recebe um valor aleatório entre 0 e 3, e retorna a letra correspondente a uma direcao aleatória para a Frente do Aldeao
     * @return String letras
     */
    public String getletraFrente() {
        Random w = new Random();
        int frente = w.nextInt(3);
    
        String[] letras = new String[4];
         letras[0] = "N";
         letras[1] = "S";
         letras[2] = "L";
         letras[3] = "O";
        
        return (letras[frente]);
    }



}