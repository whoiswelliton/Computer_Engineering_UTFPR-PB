package Funçoes;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class executaquery {
    public static ResultSet query(String sql){
        Connection con = conect.conectabd();
        try {
            Statement st = con.createStatement();
            ResultSet rs= st.executeQuery(sql);
            con.close();
            return rs;
        } 
        catch (SQLException ex){
            Logger.getLogger(executaquery.class.getName()).log(Level.SEVERE, null, ex);
            JOptionPane.showMessageDialog(null,"Erro SQLException em class executaquery");
            return null;
        }
    }
}
