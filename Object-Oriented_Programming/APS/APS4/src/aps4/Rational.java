package aps4;

public class Rational
{
        private int numerador;
        private int denominador;
        
        private void redutor()
        {
            int a = numerador;
            int b = denominador;
            
            for(boolean i = false; i != true;)
            {
			if((a % 2 == 0)&&(b % 2 == 0))
                        {
				a = a/2;
				b = b/2;
			}
			else if((a % 3 == 0)&&(b % 3 == 0))
                        {
				a = a/3;
				b = b/3;
			}
			else if((a % 5 == 0)&&(b % 5 == 0))
                        {
				a = a/5;
				b = b/5;
			}
			else if(((a % a == 0)&&(b % a == 0))&& a != 1)
                        {
				a = a/a;
				b = b/a;
			}
			else if(((a % b == 0)&&(b % b == 0))&& b!= 1)
                        {
				a = a/b;
				b = b/b;
			}
			else
				i = true;
		}
		
                numerador = a;
		denominador = b;
        }
        
        public Rational(int num, int den)
        {
            this.numerador = num;
            this.denominador = den;
            redutor();
        }
        
        public Rational()
        {
		this.numerador = 1;
		this.denominador = 1;
	}
        
        public void Somar(Rational b)
        {
            Rational aux = new Rational(numerador, denominador);
            
            numerador = ((aux.numerador * b.denominador)+(b.numerador * aux.denominador));
            denominador = aux.denominador * b.denominador;
            this.redutor();
        }
        
        public void Subtrair(Rational b)
        {
            Rational aux = new Rational(numerador, denominador);
            
            numerador = ((aux.numerador * b.denominador)-(b.numerador * aux.denominador));
            denominador = aux.denominador * b.denominador;
            this.redutor();
	}
        
        public void Multiplicar(Rational b)
        {
		Rational aux = new Rational(numerador,denominador);
                
		numerador = aux.numerador * b.numerador;
		denominador = aux.denominador * b.denominador;
                this.redutor();
	}
	public void Dividir(Rational b)
        {
		Rational aux = new Rational(numerador,denominador);
                
		numerador = aux.numerador * b.denominador;
		denominador = aux.denominador * b.numerador;
		this.redutor();
	}
	public void ImprimirFloat(){
		float k =(float)(this.numerador/(float)this.denominador);
		System.out.println("Float " + k);
	}
        public void Imprimir()
        {
		System.out.println("Fracao "+this.numerador+"/"+this.denominador);
	}
}
