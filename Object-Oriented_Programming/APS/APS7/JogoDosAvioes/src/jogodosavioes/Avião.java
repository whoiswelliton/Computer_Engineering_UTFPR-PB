package jogodosavioes;

/**
 *
 * @author WELLITON LEAL (W)
 */
public class Avião {
    private int peso;
    private int numTRIP;
    private int numPASS;
    private int qtdMOTORES = 8;
    
    Motor M[] = new Motor[qtdMOTORES];;
    Movimento MOV = new Movimento("Parado", 0);
   
    public Avião(int peso, int numTRIP, int numPASS, int qtdMOTORES) {
        this.peso = peso;
        this.numTRIP = numTRIP;
        this.numPASS = numPASS;
        this.qtdMOTORES = qtdMOTORES;
      
        for(int i = 0; i < qtdMOTORES; i++)
        {
            M[i] = new Motor("Helice", false, 0); 
        }
    }
    
    public void setEstado(boolean estado)
    {
        if(estado = true)
        {
            for(int i = 0; i < qtdMOTORES; i++)
            {
                M[i] = new Motor("Helice", true, 10); 
            }
        }
        else
        {
            for(int i = 0; i < qtdMOTORES; i++)
            {
                M[i] = new Motor("Helice", false, 0); 
            }
        }
    }
    
    public void setDireção(String direcao) 
    {
        if("Esquerda".equals(direcao))
        {
            MOV.setDireção(direcao);
            
            for(int i = 0; i < (int)qtdMOTORES/2; i++)
            {
                M[i].setPotencia = -30; 
            }
            
        }
        else if(direcao == "Direita")
        {
            MOV.setDireção(direcao);
            
            for(int i = (int)qtdMOTORES/2; i < qtdMOTORES; i++)
            {
                M[i].setPotencia = -30; 
            }
        }
        else if(direcao == "Cima")
        {
            MOV.setDireção(direcao);
            
            for(int i = 0; i < qtdMOTORES; i++)
            {
                M[i].setPotencia = +30; 
            }
        }
        else if(direcao == "Baixo")
        {
            MOV.setDireção(direcao);
            
            for(int i = 0; i < qtdMOTORES; i++)
            {
                M[i].setPotencia = -30; 
            }
        }
    }
    
    public void setVelocidade(int intensidade)
    {
        MOV.setManche(+10);
        for(int i = 0; i < qtdMOTORES; i++)
        {
            M[i].setPotencia = +30; 
        }
    }
    
}
