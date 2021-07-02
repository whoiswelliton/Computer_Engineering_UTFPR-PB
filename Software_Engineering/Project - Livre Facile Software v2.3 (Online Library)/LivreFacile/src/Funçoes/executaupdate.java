package Funçoes;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class executaupdate{
    public static void update(String sql){
        Connection con = conect.conectabd(); 
        try {
            Statement st = con.createStatement();
            st.executeUpdate(sql);
            con.close();

        } 
        catch (SQLException ex){
            Logger.getLogger(executaupdate.class.getName()).log(Level.SEVERE, null, ex);
            JOptionPane.showMessageDialog(null, "Erro SQLException em class executaupdate");
        }
    }
}