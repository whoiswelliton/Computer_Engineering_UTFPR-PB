package View;
import Funçoes.Dados;
import Funçoes.executaquery;
import Relatorios.ClienteMaisEmprestou;
import Relatorios.LivrosMaisEmprestados;
import Relatorios.RelatoriosLivro;
import View.cliente.NovoCliente;
import View.cliente.EditarCliente;
import View.cliente.BuscarCliente;
import View.cliente.DebitosUsuario;
import View.funcionario.NovoFunc;
import View.funcionario.EditarFunc;
import View.funcionario.BuscarFunc;
import View.livro.BuscarLivro;
import View.livro.BuscarLivroCliente;
import View.livro.Emprestimo;
import View.livro.NovoLivro;
import java.awt.Image;
import java.awt.Graphics;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;

public class TelaCliente extends javax.swing.JFrame {

    public TelaCliente() {
        initComponents();
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jToolBar1 = new javax.swing.JToolBar();
        ImageIcon icon = new ImageIcon(getClass().getResource("/Imagens/Fundo.jpg"));
        Image image = icon.getImage();
        desktopPane = new javax.swing.JDesktopPane(){
            public void paintComponent(Graphics g){
                g.drawImage(image,0,0,getWidth(),getHeight(),this);
            }
        };
        menuBar = new javax.swing.JMenuBar();
        fileMenu = new javax.swing.JMenu();
        ProcurarLivro = new javax.swing.JMenuItem();
        editMenu = new javax.swing.JMenu();
        Editar = new javax.swing.JMenuItem();
        Debitos = new javax.swing.JMenuItem();

        jToolBar1.setRollover(true);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Cliente");
        setExtendedState(6);
        setMinimumSize(new java.awt.Dimension(800, 600));

        fileMenu.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/book.png"))); // NOI18N
        fileMenu.setMnemonic('f');
        fileMenu.setText("Livros");

        ProcurarLivro.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/zoom.png"))); // NOI18N
        ProcurarLivro.setMnemonic('s');
        ProcurarLivro.setText("Procurar");
        ProcurarLivro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ProcurarLivroActionPerformed(evt);
            }
        });
        fileMenu.add(ProcurarLivro);

        menuBar.add(fileMenu);

        editMenu.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/user_green.png"))); // NOI18N
        editMenu.setMnemonic('e');
        editMenu.setText("Clientes");

        Editar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/zoom.png"))); // NOI18N
        Editar.setMnemonic('y');
        Editar.setText("Editar");
        Editar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EditarActionPerformed(evt);
            }
        });
        editMenu.add(Editar);

        Debitos.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/report.png"))); // NOI18N
        Debitos.setText("Debitos");
        Debitos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DebitosActionPerformed(evt);
            }
        });
        editMenu.add(Debitos);

        menuBar.add(editMenu);

        setJMenuBar(menuBar);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(desktopPane, javax.swing.GroupLayout.DEFAULT_SIZE, 454, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(desktopPane, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 412, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void EditarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EditarActionPerformed
        String sql = "select cpf_cliente,nome,sexo,email,numero,rua,complemento,bairro,cep,datanasc,telefone from cliente where cpf_cliente ='" + Dados.getCpf() + "';";
        ResultSet rs = executaquery.query(sql);
        EditarCliente a = new EditarCliente();
        try {
            while(rs.next()){
                a.setTela(rs.getString("cpf_cliente"),rs.getString("nome"),rs.getString("sexo"),rs.getString("email"),rs.getString("numero"),rs.getString("rua"),rs.getString("complemento"),rs.getString("bairro"),rs.getString("cep"),rs.getString("datanasc"),rs.getString("telefone"));
            }
        } catch (SQLException ex) {
            Logger.getLogger(TelaCliente.class.getName()).log(Level.SEVERE, null, ex);
        }
        desktopPane.add(a);
        a.setVisible(true);
    }//GEN-LAST:event_EditarActionPerformed

    private void ProcurarLivroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ProcurarLivroActionPerformed
        BuscarLivroCliente buscl = new BuscarLivroCliente();
        desktopPane.add(buscl);
        buscl.setVisible(true);
    }//GEN-LAST:event_ProcurarLivroActionPerformed

    private void DebitosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DebitosActionPerformed
        String multa = "select sum (multa) as multa from emprestimo where fk_cliente_cpf_cliente='" +Dados.getCpf()+"'"; 
        ResultSet rs_multa = executaquery.query(multa);
        String nome = "Select nome from cliente where cpf_cliente='"+Dados.getCpf()+"';";
        ResultSet rs_nome = executaquery.query(nome);
        String cpf = (String) Dados.getCpf();
        try {
            rs_multa.next();
            rs_nome.next();
            int valor_multa = rs_multa.getInt("multa");
            DebitosUsuario deb = new DebitosUsuario();
            if(valor_multa > 0){
                deb.setTela(rs_nome.getString("nome"),cpf,valor_multa);
                desktopPane.add(deb);
                deb.setVisible(true);
            }
            else{
                valor_multa = 0;
                deb.setTela(rs_nome.getString("nome"),cpf,valor_multa);
                desktopPane.add(deb);
                deb.setVisible(true);
            }
        } catch (SQLException ex) {
            Logger.getLogger(TelaCliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_DebitosActionPerformed

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TelaCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TelaCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TelaCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TelaCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
  
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaCliente().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem Debitos;
    private javax.swing.JMenuItem Editar;
    private javax.swing.JMenuItem ProcurarLivro;
    private javax.swing.JDesktopPane desktopPane;
    private javax.swing.JMenu editMenu;
    private javax.swing.JMenu fileMenu;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JMenuBar menuBar;
    // End of variables declaration//GEN-END:variables

}
