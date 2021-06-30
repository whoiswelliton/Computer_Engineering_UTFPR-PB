package aps7;

public class APS7 {

    public static void main(String[] args) {
         Pessoa[] p = new Pessoa[10];
         Aluno[] a = new Aluno[5];
         
         
        Aluno p1 = new Aluno (0.75f, true, 6, "Computacao", "Joao", 209122);
        p1.status2();
        p1.cargaHoraria(30);
        
        Professor p2 = new Professor (3500.75f, 3, "DAINF", "Bruno", 902423);
        p2.status2();
        p2.cargaHoraria(55);
        
    }
    
}
