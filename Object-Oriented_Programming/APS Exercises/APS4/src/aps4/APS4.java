package aps4;
/**
 *
 * @author WELLITON LEAL (W)
 */
public class APS4 
{
    public static void main(String[] args) 
    {
        Rational a = new Rational();
	Rational b = new Rational(25,40);
	Rational c = new Rational(2,3);

	//imprimir
	System.out.println("\n Frações");
	a.Imprimir();
	b.Imprimir();
	c.Imprimir();
        
        //Soma
        System.out.println("\n Soma a com b");
	a.Somar(b);
	a.Imprimir();
        a.ImprimirFloat();
        
        //subtração
        System.out.println("\n Subtrai b de a");
        a.Subtrair(b);
	a.Imprimir();
	a.ImprimirFloat();

	//multiplicação
	System.out.println("\n Multiplica c com b");
	c.Multiplicar(b);
	c.Imprimir();
	c.ImprimirFloat();

	//divisão
	System.out.println("\n Divide c por b");
	c.Dividir(b);
	c.Imprimir();
	c.ImprimirFloat();
    }
    
}

    
