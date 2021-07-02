package View;
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
import View.livro.Emprestimo;
import View.livro.NovoLivro;
import java.awt.Image;
import java.awt.Graphics;
import javax.swing.ImageIcon;

public class TelaFuncionario extends javax.swing.JFrame {
    public void DesktopPaneNovoCliente(){
        NovoCliente novoc = new NovoCliente();
        desktopPane.add(novoc);
        novoc.setVisible(true);
    }
    public void setDPEditarCliente(String cpf,String nome,String sexo,String email,String numero,String rua,String complemento,String bairro,String cep,String dataNasc,String telefone) {
        EditarCliente tela = new EditarCliente();
        desktopPane.add(tela);
        tela.setVisible(true);
        tela.setTela(cpf,nome,sexo,email,numero,rua,complemento,bairro,cep,dataNasc,telefone);
    }
    public void DesktopPaneNovoLivro() {
        NovoLivro livro = new NovoLivro();
        desktopPane.add(livro);
        livro.setVisible(true);
    }
    public void setDPEmprestimo(String nome,String codigo) {
        Emprestimo tela = new Emprestimo();
        desktopPane.add(tela);
        tela.setVisible(true);
        tela.setDados(nome,codigo);
    }  
    public void DesktopPaneDebitosUsuario(String nome,String cpf,int multa){
        DebitosUsuario tela = new DebitosUsuario();
        desktopPane.add(tela);
        tela.setTela(nome, cpf, multa);
        tela.setVisible(true);
    }
    public void DesktopPaneLME(String SQL){
        LivrosMaisEmprestados LME = new LivrosMaisEmprestados();
        desktopPane.add(LME);
        LME.setVisible(true);
        LME.setTela(SQL);
    }  
    public void DesktopPaneCME(String SQL){
        ClienteMaisEmprestou CME = new ClienteMaisEmprestou();
        desktopPane.add(CME);
        CME.setVisible(true);
        CME.setTela(SQL);
    }

    public TelaFuncionario() {
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
        novoLivro = new javax.swing.JMenuItem();
        ProcurarLivro = new javax.swing.JMenuItem();
        editMenu = new javax.swing.JMenu();
        NovoCliente = new javax.swing.JMenuItem();
        ProcurarCliente = new javax.swing.JMenuItem();
        Relatorios = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();

        jToolBar1.setRollover(true);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Funcionario");
        setExtendedState(6);
        setMinimumSize(new java.awt.Dimension(800, 600));

        fileMenu.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/book.png"))); // NOI18N
        fileMenu.setMnemonic('f');
        fileMenu.setText("Livros");

        novoLivro.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/book_add.png"))); // NOI18N
        novoLivro.setMnemonic('o');
        novoLivro.setText("Novo");
        novoLivro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                novoLivroActionPerformed(evt);
            }
        });
        fileMenu.add(novoLivro);

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

        NovoCliente.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/user_add.png"))); // NOI18N
        NovoCliente.setMnemonic('t');
        NovoCliente.setText("Novo");
        NovoCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NovoClienteActionPerformed(evt);
            }
        });
        editMenu.add(NovoCliente);

        ProcurarCliente.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/zoom.png"))); // NOI18N
        ProcurarCliente.setMnemonic('y');
        ProcurarCliente.setText("Procurar");
        ProcurarCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ProcurarClienteActionPerformed(evt);
            }
        });
        editMenu.add(ProcurarCliente);

        menuBar.add(editMenu);

        Relatorios.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/report.png"))); // NOI18N
        Relatorios.setText("Relatórios");
        Relatorios.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                RelatoriosActionPerformed(evt);
            }
        });

        jMenuItem1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/report.png"))); // NOI18N
        jMenuItem1.setText("Relatórios");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        Relatorios.add(jMenuItem1);

        menuBar.add(Relatorios);

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

    private void novoLivroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_novoLivroActionPerformed
        NovoLivro livro = new NovoLivro();
        desktopPane.add(livro);
        livro.setVisible(true);

    }//GEN-LAST:event_novoLivroActionPerformed

    private void ProcurarClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ProcurarClienteActionPerformed
        BuscarCliente busc = new BuscarCliente();
        desktopPane.add(busc);
        busc.setVisible(true);
    }//GEN-LAST:event_ProcurarClienteActionPerformed

    private void NovoClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NovoClienteActionPerformed
        NovoCliente novoc = new NovoCliente();
        desktopPane.add(novoc);
        novoc.setVisible(true);
    }//GEN-LAST:event_NovoClienteActionPerformed

    private void ProcurarLivroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ProcurarLivroActionPerformed
        BuscarLivro buscl = new BuscarLivro();
        desktopPane.add(buscl);
        buscl.setVisible(true);
    }//GEN-LAST:event_ProcurarLivroActionPerformed

    private void RelatoriosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_RelatoriosActionPerformed

    }//GEN-LAST:event_RelatoriosActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        RelatoriosLivro relL = new RelatoriosLivro();
        desktopPane.add(relL);
        relL.setVisible(true);
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TelaFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TelaFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TelaFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TelaFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
  
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaFuncionario().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem NovoCliente;
    private javax.swing.JMenuItem ProcurarCliente;
    private javax.swing.JMenuItem ProcurarLivro;
    private javax.swing.JMenu Relatorios;
    private javax.swing.JDesktopPane desktopPane;
    private javax.swing.JMenu editMenu;
    private javax.swing.JMenu fileMenu;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JMenuBar menuBar;
    private javax.swing.JMenuItem novoLivro;
    // End of variables declaration//GEN-END:variables

}
