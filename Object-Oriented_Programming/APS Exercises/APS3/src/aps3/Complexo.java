package aps3;
/**
 *
 * @author WELLITON LEAL (W)
 */
public class Complexo{
    
	private double real;
	private double img;
        
        public Complexo(double r, double i)
	{
		real = r;
		img = i;
	}
        public Complexo()
	{
            real = 0;
            img = 0;
        }
	
        public void ImprimeNumero()
        {
		if(img > 0)
			System.out.println(real + " + " + img + "i" );
		else if(img < 0)
			System.out.println(real + " + " + img + "i" );
		else
			System.out.println(real);
	}
        
        public boolean eIgual(Complexo b)
        {
		if((this.real == b.real)&&(this.img == b.img))
                {
			return(true);
		}
		else{
			return(false);
		}
	}
        
        public void Soma (Complexo b)   
        {
		this.real = this.real + b.real;
		this.img = this.img + b.img;
	}
        
	public void Subtrai (Complexo b)
        {
		this.real = this.real - b.real;
		this.img = this.img - b.img;
	}
        
        public void Multiplica (Complexo b)
        {
		Complexo a = new Complexo(this.real, this.img);
		this.real = (a.real * b.real)-(a.img * b.img);
		this.img = (a.real * b.img)+(b.real * a.img);
	}
	
        public void Divide (Complexo b)
        {
		if(b.real != 0 && b.img != 0)
                {
			Complexo a = new Complexo(this.real, this.img);
			this.real = ((a.real*b.real)+(a.img * b.img))/(Math.pow(b.real, 2) + Math.pow(b.img,2));
			this.img = ((b.real*a.img)-(a.real * b.img))/(Math.pow(b.real,2)+Math.pow(b.img,2));
		}
		else
                {
			System.out.println("impossivel divisao por zero");
		}
	}
}
