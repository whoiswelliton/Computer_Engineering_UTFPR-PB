
package aula7;

public class Aula7 {

    public static void main(String[] args) {
        Lutador l[] = new Lutador[4]; 
                
        l[0] = new Lutador("Pretty Boy", "França",31,11,2,1, 1.75f, 68.9f);
        
        
        l[1] = new Lutador("Putscript", "Brasil",25,15,1,3, 1.80f, 65.3f);
       
        
        Luta UEC = new Luta();
        UEC.marcarLuta(l[0], l[1]);
        UEC.lutar();
        
        l[0].status();
        l[1].status();
        
    }
    
}
