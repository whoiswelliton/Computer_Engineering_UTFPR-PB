public class Complexo{
	private double real;
	private double img;
	private double somareal, somaimg;

	public Complexo()
	{
		real =0; 
		img=0; 
	}
	public Complexo(double r, double i)
	{
		real = r;
		img = i;
	}
	public boolean eIgual(Complexo x)
	{	
		if(x.real == real && x.img == img)
			return true;
		else
			return false;
	}
	public void soma(double a, double b)
	{
		(a.real+b.img)-(c.real+d.img) = (a.real-c.real)+(b.img+d.img)
	}
	public void inicializaNumero(double a, double b)
	{
		real = a;
		img = b;
	}
	public void imprimeNumero()
	{
		System.out.println(real + " + " + img + "i");
	}
	
}
