package simulador;

public abstract class VeiculoMotorizado extends Veiculo{
    private double combustivel;

    public VeiculoMotorizado (String id, int qtdrodas) {
        super(id, qtdrodas);
        this.combustivel = 0;
    }

    public void abastecer(double L)
    {
        this.combustivel += L; 
        
        if(L > 0)
        {
            System.out.println("Veículo "+ getId() +" abastecido.");
        }  
    }

    public double getCombustivel() {
        return combustivel;
    }
}
