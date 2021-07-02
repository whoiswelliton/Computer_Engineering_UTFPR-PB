package Funçoes;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class conect {
    public static Connection conectabd(){
        try{
            try{
                Class.forName("org.postgresql.Driver");
            }
            catch (ClassNotFoundException ex){
                Logger.getLogger(conect.class.getName()).log(Level.SEVERE, null, ex);
                JOptionPane.showMessageDialog(null,"Erro ClassNotFoundException em class conect");
            }
            Connection con = DriverManager.getConnection("jdbc:postgresql://localhost:5432/Biblioteca","postgres","asrm7878");
            return con;
            }
        catch (SQLException ex) {
                Logger.getLogger(conect.class.getName()).log(Level.SEVERE, null, ex);
                JOptionPane.showMessageDialog(null,"Erro SQLException em class conect");
                return null;
        }
    }
}

