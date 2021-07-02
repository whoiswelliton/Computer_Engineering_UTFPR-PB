package View.funcionario;
import Funçoes.Dados;
import View.*;
import static Funçoes.StringUtil.Cripto;
import Funçoes.executaupdate;
import javax.swing.JOptionPane;

public class NovoFunc extends javax.swing.JInternalFrame {

    public javax.swing.JTextField getCpffunc() {
        return cpf;
    }

    public void setCpffunc(String a) {
        this.cpf.setText(a);
    }

    public javax.swing.JTextField getNomefunc() {
        return nomefunc;
    }

    public void setNomefunc(String b) {
        this.nomefunc.setText(b);
    }

    public NovoFunc(){
        initComponents();
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        nomefunc = new javax.swing.JTextField();
        senha = new javax.swing.JPasswordField();
        confirmar = new javax.swing.JPasswordField();
        Salvar = new javax.swing.JButton();
        cpf = new javax.swing.JTextField();

        setClosable(true);
        setTitle("Cadastrar Funcionário");

        jLabel1.setText("Nome");

        jLabel2.setText("Cpf");

        jLabel3.setText("Senha");

        jLabel4.setText("Confirmar Senha");

        nomefunc.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nomefuncActionPerformed(evt);
            }
        });

        senha.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                senhaActionPerformed(evt);
            }
        });

        Salvar.setText("Salvar");
        Salvar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SalvarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(60, 60, 60)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(confirmar, javax.swing.GroupLayout.DEFAULT_SIZE, 233, Short.MAX_VALUE)
                    .addComponent(jLabel3)
                    .addComponent(jLabel2)
                    .addComponent(jLabel1)
                    .addComponent(jLabel4)
                    .addComponent(nomefunc)
                    .addComponent(senha)
                    .addComponent(Salvar, javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(cpf))
                .addContainerGap(60, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(nomefunc, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(cpf, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(11, 11, 11)
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(senha, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel4)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(confirmar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(Salvar)
                .addContainerGap(24, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void nomefuncActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nomefuncActionPerformed

    }//GEN-LAST:event_nomefuncActionPerformed

    private void SalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SalvarActionPerformed
        if(senha.getText().equals(confirmar.getText()) && !(senha.getText().equals("")) && !(cpf.getText().equals("")) && (cpf.getText().length()== 11)){
            String SQL;
            SQL = "insert into funcionario values ('" + getCpffunc().getText() + "', '" + senha.getText() + "', '" + getNomefunc().getText() +  "', 'funcionario', '" +Dados.getCpf() + "');";        
            executaupdate.update(SQL);
            JOptionPane.showMessageDialog(this, "Funcionário cadastrado com sucesso");
            this.dispose();
        }
        else{
            JOptionPane.showMessageDialog(this, "Por Favor preencha o formulario corretamente!");
            senha.setText("");
            confirmar.setText("");
            cpf.setText("");
        }
    }//GEN-LAST:event_SalvarActionPerformed

    private void senhaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_senhaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_senhaActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Salvar;
    private javax.swing.JPasswordField confirmar;
    private javax.swing.JTextField cpf;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JTextField nomefunc;
    private javax.swing.JPasswordField senha;
    // End of variables declaration//GEN-END:variables
}
