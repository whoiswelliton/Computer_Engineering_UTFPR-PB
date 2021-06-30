package simulador;

public class Ferrari extends VeiculoMotorizado{

    public Ferrari(String id, int qtdrodas) {
        super(id, qtdrodas);
    }

    @Override
    public void mover() {
        if(this.getCalibragem())
        {
            if(this.getCombustivel() >= 1.5)
            {
                this.setDistpercorrida(10);
                this.abastecer(-1.5);
                System.out.println("O Veículo "+ this.getId() +" Foi Movido.");
            }
            else
            {
                 System.out.println("O veículo:"+ this.getId() +" está com Combustível Insuficiente");
            }
        }
        else
        {
            System.out.println("O veículo:"+ this.getId() +" está com os Pneus Descalibrados");
        }
    }

    @Override
    public void imprimirTrajetoria() {
        System.out.print("|");
        for(int i=0; i<this.getDistpercorrida(); i++)  
        {
            System.out.print("-");
        }
        System.out.println(this.getId());
    } 
    
    @Override
    public String toString() {
        return ("|" + getId() +  " |Percorrido: " + getDistpercorrida() + " |Combustível: " + getCombustivel() + " |Calibragem: "+ getCalibragem());
    }
    
}
