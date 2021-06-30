public class Complexo{
 private int real;
 private int imaginario;

 public Complexo(int a, int b){
     this.real = a; 
	 this.imaginario = b;
 }
 public void soma(Complexo c){
    this.real = this.real + c.real;
    this.imaginario = this.imaginario + c.imaginario;
 }
 public void imprimir(){
    System.out.println(this.real + "," + this.imaginario);
 }
}
