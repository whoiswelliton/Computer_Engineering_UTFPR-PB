package View.cliente;

import Funçoes.Dados;
import Funçoes.executaquery;
import Funçoes.executaupdate;
import View.TelaFuncionario;
import View.TelaGerente;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

public class BuscarCliente extends javax.swing.JInternalFrame {

    public BuscarCliente() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jtxtBusca = new javax.swing.JTextField();
        buscar = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        JCfiltro = new javax.swing.JComboBox<>();
        jPanel2 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jtablebusca = new javax.swing.JTable();
        Editar = new javax.swing.JButton();
        Remover = new javax.swing.JButton();
        Novo = new javax.swing.JButton();
        Debitos = new javax.swing.JButton();
        desbloqueiausuario = new javax.swing.JButton();

        setClosable(true);
        setTitle("Buscar Cliente");

        jtxtBusca.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jtxtBuscaActionPerformed(evt);
            }
        });

        buscar.setText("Buscar");
        buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarActionPerformed(evt);
            }
        });

        jLabel1.setText("Filtrar por:");

        JCfiltro.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Todos", "Nome", "Cpf" }));
        JCfiltro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                JCfiltroActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(JCfiltro, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jtxtBusca)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(buscar)
                .addGap(30, 30, 30))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(JCfiltro, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jtxtBusca, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(buscar))
                .addContainerGap(20, Short.MAX_VALUE))
        );

        jtablebusca.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Nome", "CPF"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(jtablebusca);

        Editar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/user_edit.png"))); // NOI18N
        Editar.setText("Editar");
        Editar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EditarActionPerformed(evt);
            }
        });

        Remover.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/user_delete.png"))); // NOI18N
        Remover.setText("Remover");
        Remover.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                RemoverActionPerformed(evt);
            }
        });

        Novo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/user_add.png"))); // NOI18N
        Novo.setText("Novo");
        Novo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NovoActionPerformed(evt);
            }
        });

        Debitos.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/report.png"))); // NOI18N
        Debitos.setText("Debitos");
        Debitos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DebitosActionPerformed(evt);
            }
        });

        desbloqueiausuario.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/user_delete.png"))); // NOI18N
        desbloqueiausuario.setText("Desbloquear");
        desbloqueiausuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                desbloqueiausuarioActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 477, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(Editar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Novo, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(desbloqueiausuario, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Debitos, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Remover, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(14, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 378, Short.MAX_VALUE)
                .addGap(20, 20, 20))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addComponent(Novo, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(Editar, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(Remover, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(Debitos, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(desbloqueiausuario, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jtxtBuscaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jtxtBuscaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jtxtBuscaActionPerformed

    private void buscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarActionPerformed
        try {
            DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
            String filtro = (String) JCfiltro.getSelectedItem();
            String SQL;
            tabelabusca.setNumRows(0);
            if(filtro.equals("Nome")){
                SQL="select nome,cpf_cliente from cliente where upper(nome) like upper('%" + jtxtBusca.getText() + "%') order by 1;";
            }
            else if(filtro.equals("Cpf")){
                SQL="select nome,cpf_cliente from cliente where cpf_cliente like upper('%" + jtxtBusca.getText() + "%') order by 1;";
            }
            else{
                SQL="select nome,cpf_cliente from cliente;";
            }
            ResultSet rs =executaquery.query(SQL);
            while(rs.next()){
                Object[] Dados = {rs.getString("nome"),rs.getString("cpf_cliente")};
                tabelabusca.addRow(Dados);
            }
            jtxtBusca.setText("");
        } catch (SQLException ex) {
            Logger.getLogger(BuscarCliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_buscarActionPerformed

    private void JCfiltroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_JCfiltroActionPerformed

    }//GEN-LAST:event_JCfiltroActionPerformed

    private void RemoverActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_RemoverActionPerformed

        if(jtablebusca.getSelectedRow() != -1)
        {
            DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
            String SQL= "delete from cliente where cpf_cliente ='" + tabelabusca.getValueAt(jtablebusca.getSelectedRow(),1) + "';";
            executaupdate.update(SQL);
            tabelabusca.removeRow(jtablebusca.getSelectedRow());
        }
        else {
            JOptionPane.showMessageDialog(null, "Nenhum Cliente foi selecionado!");
        }
    }//GEN-LAST:event_RemoverActionPerformed

    private void EditarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EditarActionPerformed

        if(jtablebusca.getSelectedRow() != -1)
        {
            DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
            String busca = "select * from cliente where cpf_cliente ='" + tabelabusca.getValueAt(jtablebusca.getSelectedRow(),1) + "';";
            ResultSet rs = executaquery.query(busca);
            try {
                rs.next();
                if(Dados.getCargo().equals("Gerente")){
                    Dados.setCpfEdit(rs.getString("cpf_cliente"));
                    TelaGerente a = Dados.getEndG();
                    a.setDPEditarCliente(rs.getString("cpf_cliente"),rs.getString("nome"),rs.getString("sexo"),rs.getString("email"),rs.getString("numero"),rs.getString("rua"),rs.getString("complemento"),rs.getString("bairro"),rs.getString("cep"),rs.getString("datanasc"),rs.getString("telefone"));
                    this.dispose();
                } 
                else{
                    Dados.setCpfEdit(rs.getString("cpf_cliente"));
                    TelaFuncionario a = Dados.getEndF();
                    a.setDPEditarCliente(rs.getString("cpf_cliente"),rs.getString("nome"),rs.getString("sexo"),rs.getString("email"),rs.getString("numero"),rs.getString("rua"),rs.getString("complemento"),rs.getString("bairro"),rs.getString("cep"),rs.getString("datanasc"),rs.getString("telefone"));
                    this.dispose();
                }
            }
            catch (SQLException ex) {
                Logger.getLogger(BuscarCliente.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        else {
            JOptionPane.showMessageDialog(null, "Nenhum Cliente foi selecionado!");
        }
    }//GEN-LAST:event_EditarActionPerformed

    private void NovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NovoActionPerformed
        if(Dados.getCargo().equals("Gerente")){
            this.dispose();
            TelaGerente a = Dados.getEndG();
            a.DesktopPaneNovoCliente();
        } 
        else{
            this.dispose();
            TelaFuncionario a = Dados.getEndF();
            a.DesktopPaneNovoCliente();
        }



    }//GEN-LAST:event_NovoActionPerformed

    private void DebitosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DebitosActionPerformed
        if(jtablebusca.getSelectedRow() != -1)
        {
            DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
            String multa = "select sum (multa) as multa from emprestimo where fk_cliente_cpf_cliente='" + tabelabusca.getValueAt(jtablebusca.getSelectedRow(),1) + "';";
            String nome = (String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0);
            String cpf = (String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),1);
            ResultSet rs_multa = executaquery.query(multa);
            try {
                rs_multa.next();
                int valor_multa = rs_multa.getInt("multa");
                if(valor_multa > 0){ 
                    if(Dados.getCargo().equals("Gerente")){
                        TelaGerente a =Dados.getEndG();
                        a.DesktopPaneDebitosUsuario(nome,cpf,valor_multa);
                    } 
                    else{
                        TelaFuncionario a =Dados.getEndF();
                        a.DesktopPaneDebitosUsuario(nome,cpf,valor_multa);
                    }
                }
                else{
                    if(Dados.getCargo().equals("Gerente")){
                        valor_multa = 0;
                        TelaGerente a =Dados.getEndG();
                        a.DesktopPaneDebitosUsuario(nome,cpf,valor_multa);
                    } 
                    else{
                        valor_multa = 0;
                        TelaFuncionario a =Dados.getEndF();
                        a.DesktopPaneDebitosUsuario(nome,cpf,valor_multa);
                    }
                }
            }
            catch (SQLException ex) {
                Logger.getLogger(BuscarCliente.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        else {
            JOptionPane.showMessageDialog(null, "Nenhum Cliente foi selecionado!");
        }
    }//GEN-LAST:event_DebitosActionPerformed

    private void desbloqueiausuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_desbloqueiausuarioActionPerformed
        DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
        String cpf = (String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),1);
        String SQL = "update cliente set disponivel = true where cpf_cliente = '" + cpf + "';";
        String SQL2 = "update emprestimo set multa = 0, data_devolvido = current_date where fk_cliente_cpf_cliente = '" + cpf+"';";
        executaupdate.update(SQL);
        executaupdate.update(SQL2);
        JOptionPane.showMessageDialog(null, "Cliente desbloqueado com sucesso");
        this.dispose();
        
    }//GEN-LAST:event_desbloqueiausuarioActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Debitos;
    private javax.swing.JButton Editar;
    private javax.swing.JComboBox<String> JCfiltro;
    private javax.swing.JButton Novo;
    private javax.swing.JButton Remover;
    private javax.swing.JButton buscar;
    private javax.swing.JButton desbloqueiausuario;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable jtablebusca;
    private javax.swing.JTextField jtxtBusca;
    // End of variables declaration//GEN-END:variables
}
