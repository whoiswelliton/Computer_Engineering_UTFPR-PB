
package usacontrole;


public class Foguete {
    private boolean estadof;
    private double combustivel;
    private Propulsor[] propulsores = new Propulsor[4];

    public Foguete(boolean estadof, double combustivel) {
        this.estadof = estadof;
        this.combustivel = combustivel;
        
        for(int i =0 ; i< propulsores.length; i++)
        {
            propulsores[i] = new Propulsor(0,false);
        }
    }
    
    public void setPotencia(int valor)
    {
        for(int i =0 ; i< propulsores.length; i++)
        {
            propulsores[i].setPotencia(valor);
        }
    }
    public void setDirecao(String direcao)
    {
        if("Norte".equals(direcao))
        {
            if(propulsores[1].getPotencia() == 100)
            {
                propulsores[0].setPotencia(-10);
            }
            else
            {
                propulsores[1].setPotencia(+10);
            }
        }
        if("Sul".equals(direcao))
        {
            if(propulsores[0].getPotencia() == 100)
            {
                propulsores[1].setPotencia(-10);
            }
            else
            {
                propulsores[0].setPotencia(+10);
            }            
        }
        if("Oeste".equals(direcao))
        {
            if(propulsores[3].getPotencia() == 100)
            {
                propulsores[2].setPotencia(-10);
            }
            else
            {
                propulsores[3].setPotencia(+10);
            } 
        }
        if("Leste".equals(direcao))
        {
            if(propulsores[2].getPotencia() == 100)
            {
                propulsores[3].setPotencia(-10);
            }
            else
            {
                propulsores[2].setPotencia(+10);
            } 
        }
   
    }

    public boolean getEstadof() {
        return estadof;
    }

    public void setEstadof(boolean estadof) {
        if(estadof == true)
        {
            this.estadof = estadof;
            for(int i =0 ; i< propulsores.length; i++)
            {
                propulsores[i].setEstadop(true);
            }
            this.setPotencia(10);
        }
        else
        {
            {
                this.estadof = estadof;
                for(int i =0 ; i< propulsores.length; i++)
                {
                    propulsores[i].setEstadop(false);
                }
                this.setPotencia(0);
            }
        }
        
        
    }

    public double getCombustivel() {
        return combustivel;
    }

    public void setCombustivel(double combustivel) {
        this.combustivel = combustivel;
    }
    
    
  
}
