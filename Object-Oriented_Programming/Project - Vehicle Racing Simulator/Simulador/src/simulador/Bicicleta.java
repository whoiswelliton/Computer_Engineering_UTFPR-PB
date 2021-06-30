package simulador;

public class Bicicleta extends Veiculo
{
    public Bicicleta(String id, int qtdrodas){
        super(id, qtdrodas);
    }

    @Override
    public void mover() {
        if(this.getCalibragem())
        {
            this.setDistpercorrida(1);
            System.out.println("O Veículo "+ this.getId() +" Foi Movido.");
        }
        else
        {
            System.out.println("O veículo "+ this.getId() +" está com os Pneus Descalibrados");
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
        return ("|" + getId() +  " |Percorrido: " + getDistpercorrida() + " |Calibragem: "+ getCalibragem());
    }
}
