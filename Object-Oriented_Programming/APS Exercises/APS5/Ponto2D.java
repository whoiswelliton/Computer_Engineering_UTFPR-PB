public class Ponto2D 
{
  private double x,y; // as coordenadas do ponto no espaço bidimensional

  public Ponto2D(double x, double y){
	  this.x = x;
	  this.y = y;
  }
  public void inicializaPonto2D(double _x,double _y){ 
	x = _x;
    y = _y;
  } 
  
  public double getX(){
	  return x;	  
  }
  public double getY(){
	  return y;	  
  }
  public boolean eIgual(Ponto2D outroPonto2D){ 
	  if ((x == outroPonto2D.x) && (y == outroPonto2D.y)) 
	     return true; // o ponto é igual, retorna true
	  else
	      return false; // o ponto é diferente, retorna false
  } 
  
  public Ponto2D origem(){
	 Ponto2D temporario = new Ponto2D(0,0); // a inicialização da instância é feita aqui
	 temporario.inicializaPonto2D(0,0);
	 return temporario; // retornamos a referência inicializada
  } // fim do método origem
  
  public Ponto2D clona()
  {
     Ponto2D temporario = new Ponto2D(0,0); // a inicialização da instância é feita aqui
   	 temporario.inicializaPonto2D(x,y); // os valores encapsulados são usados
	 return temporario; // retornamos a referência inicializada
  }  // fim do método clona

  public String toString()
  {
	 String resultado = "("+x+","+y+")";
	 return resultado;
  } // fim do método toString

 } // fim da classe Ponto2D
