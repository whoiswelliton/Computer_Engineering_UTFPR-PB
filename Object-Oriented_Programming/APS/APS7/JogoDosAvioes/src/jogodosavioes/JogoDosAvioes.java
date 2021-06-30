
package jogodosavioes;

/**
 *
 * @author WELLITON LEAL (W)
 */
public class JogoDosAvioes {

    public static void main(String[] args) {
       Avião Boing = new Avião(10000,2,40,4);
       Avião Bimotor = new Avião(8000,2,20,2);
       Avião Monomotor = new Avião(2000,2,6,1);
       
       
       Boing.setEstado(true);
       Bimotor.setEstado(true);
       Monomotor.setEstado(true);
       
       Boing.setDireção("Esquerda");
       
       
   }
    
}
