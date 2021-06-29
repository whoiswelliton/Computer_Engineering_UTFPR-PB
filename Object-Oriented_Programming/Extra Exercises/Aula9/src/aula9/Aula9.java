
package aula9;

public class Aula9 {

    public static void main(String[] args)
    {
        //Pessoa p1 = new Pessoa();
        Aluno p2 = new Aluno(123123, "Eng Comp", "Joao",17,"Male");
        Professor p3 = new Professor("Teoria ", 5200.23f, "Marco", 43, "Male");
        Funcionario p4 = new Funcionario("Reitoria", true, "Idemir", 48, "Male");
        
        System.out.println(p2.toString());
        System.out.println(p3.toString());
        System.out.println(p4.toString());
                
        
    }
    
}
