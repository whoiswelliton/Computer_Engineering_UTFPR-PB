package Funçoes;
import View.TelaCliente;
import View.TelaFuncionario;
import View.TelaGerente;

public class Dados {
    private static String cpf; // Cpf da pessoa que acessou o sistema
    private static String cargo; // cargo da pessoa que acessou o sistema
    private static TelaGerente EndG;
    private static TelaFuncionario EndF;
    private static TelaCliente EndC;
    private static String cpfEdit;
    
    public static String getCpf() {
        return cpf;
    }
   
    public static void setCpf(String aCpf) {
        cpf = aCpf;
    }
    
    public static String getCargo() {
        return cargo;
    }
    
    public static void setCargo(String aCargo) {
        cargo = aCargo;
    }
    
    public static TelaGerente getEndG() {
        return EndG;
    }
    
    public static void setEndG(TelaGerente aEnd) {
        EndG = aEnd;
    }
    public static TelaFuncionario getEndF() {
        return EndF;
    }
    
    public static void setEndF(TelaFuncionario aEnd) {
        EndF = aEnd;
    }
    public static TelaCliente getEndC() {
        return EndC;
    }
    
    public static void setEndC(TelaCliente aEnd) {
        EndC = aEnd;
    }
    public static String getCpfEdit() {
        return cpfEdit;
    }

    public static void setCpfEdit(String aCpfEdit) {
        cpfEdit = aCpfEdit;
    }
}
