package View.livro;

import View.cliente.*;
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

public class BuscarLivro extends javax.swing.JInternalFrame {

    public BuscarLivro() {
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
        Emprestar = new javax.swing.JButton();
        Remover = new javax.swing.JButton();
        Novo = new javax.swing.JButton();
        Devolucao = new javax.swing.JButton();

        setClosable(true);
        setTitle("Buscar Livros");

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

        JCfiltro.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Todos", "Nome", "Autor", "Codigo" }));
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
                .addGap(20, 20, 20))
        );

        jtablebusca.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Código", "Nome", "Autor", "Disponível"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(jtablebusca);

        Emprestar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/book_next.png"))); // NOI18N
        Emprestar.setText("Emprestimo");
        Emprestar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EmprestarActionPerformed(evt);
            }
        });

        Remover.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/book_delete.png"))); // NOI18N
        Remover.setText("Remover");
        Remover.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                RemoverActionPerformed(evt);
            }
        });

        Novo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/book_add.png"))); // NOI18N
        Novo.setText("Novo");
        Novo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NovoActionPerformed(evt);
            }
        });

        Devolucao.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/book_previous.png"))); // NOI18N
        Devolucao.setText("Devolulção");
        Devolucao.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DevolucaoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 514, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(20, 20, 20)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(Novo, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Remover, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Emprestar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Devolucao, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(20, 20, 20))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(Novo, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 18, Short.MAX_VALUE)
                        .addComponent(Remover, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(Emprestar, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(Devolucao, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(20, 20, 20))
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
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
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
                SQL="select nome,autor,codigo_livro,disponivel from livro where upper(nome) like upper('%" + jtxtBusca.getText() + "%') order by 1;";
                System.out.println(SQL);
            }
            else if(filtro.equals("Autor")){
                SQL="select nome,autor,codigo_livro,disponivel from livro where upper(autor) like upper('%" + jtxtBusca.getText() + "%') order by 2;";
            }
            else if(filtro.equals("Codigo")){
                SQL="select nome,autor,codigo_livro,disponivel from livro where codigo_livro =" + jtxtBusca.getText() + " order by 1;";
            }
            else{
                SQL="select nome,autor,codigo_livro,disponivel from livro order by 1;";
            }
            ResultSet rs =executaquery.query(SQL);
            while(rs.next()){
                Object[] Dados = {rs.getString("codigo_livro"),rs.getString("nome"),rs.getString("autor"),rs.getString("disponivel")};
                tabelabusca.addRow(Dados);
            }
            jtxtBusca.setText("");
        } catch (SQLException ex) {
            Logger.getLogger(BuscarLivro.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_buscarActionPerformed

    private void JCfiltroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_JCfiltroActionPerformed

    }//GEN-LAST:event_JCfiltroActionPerformed

    private void RemoverActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_RemoverActionPerformed
        if(jtablebusca.getSelectedRow() != -1)
        {
            DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
            String disponivel = (String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),3);
            if(disponivel.equals("t")){
                String SQL= "delete from livro where codigo_livro ='" + tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0) + "';";
                executaupdate.update(SQL);
                tabelabusca.removeRow(jtablebusca.getSelectedRow());
            }
            else{
                JOptionPane.showMessageDialog(null, "Não é possivel excluir esse livro no momento pois ele nao esta no acervo!");
            }
        }
        else {
            JOptionPane.showMessageDialog(null, "Nenhum livro foi selecionado!");
        }
    }//GEN-LAST:event_RemoverActionPerformed

    private void EmprestarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EmprestarActionPerformed
        if(jtablebusca.getSelectedRow() != -1)
        {
            DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
            String disponivel = (String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),3);
            if(disponivel.equals("t")){
                if(Dados.getCargo().equals("Gerente")){
                    TelaGerente a= Dados.getEndG();
                    String nome =(String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),1);
                    String codigo =(String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0);
                    a.setDPEmprestimo(nome,codigo);
                    this.dispose();
                    
                } 
                else{
                    TelaFuncionario a= Dados.getEndF();
                    String nome =(String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),1);
                    String codigo =(String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0);
                    a.setDPEmprestimo(nome,codigo);
                    this.dispose();
                }
            }
            else{
                JOptionPane.showMessageDialog(null, "Livro indisponivel para emprestimo!");
            }
        }
        else {
            JOptionPane.showMessageDialog(null, "Nenhum livro foi selecionado!");
        }
    }//GEN-LAST:event_EmprestarActionPerformed

    private void NovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NovoActionPerformed
        if(Dados.getCargo().equals("Gerente")){
            TelaGerente a = Dados.getEndG();
            a.DesktopPaneNovoLivro();
        } 
        else{
            TelaFuncionario a = Dados.getEndF();
            a.DesktopPaneNovoLivro();
        }
        this.dispose();
    }//GEN-LAST:event_NovoActionPerformed

    private void DevolucaoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DevolucaoActionPerformed
        if(jtablebusca.getSelectedRow() != -1)
        {
            DefaultTableModel tabelabusca = (DefaultTableModel) jtablebusca.getModel();
            String disponivel = (String) tabelabusca.getValueAt(jtablebusca.getSelectedRow(),3);
            if(disponivel.equals("f")){
                executaupdate.update("update livro set disponivel = true where codigo_livro = " +  tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0) + ";");
                executaupdate.update("update emprestimo set data_devolvido = (current_date) where fk_livro_codigo_livro =" + tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0) + " and data_devolvido is null");
                executaupdate.update("update emprestimo set multa = ((data_dev)-(data_devolvido)) * -1 where ((data_devolvido)>(data_dev)) and data_devolvido = (current_date) and  fk_livro_codigo_livro = "+ tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0) + ";");
                ResultSet rs = executaquery.query("select fk_cliente_cpf_cliente from emprestimo  where multa is not null and data_devolvido= (current_date) and fk_livro_codigo_livro ="+tabelabusca.getValueAt(jtablebusca.getSelectedRow(),0)+";");
                try {
                    // verificar se retornou algo, se retornou achou um cpf com multa, fazer update com o cpf do cara, colocando false em disponivel
                    if(rs.isBeforeFirst()){
                        rs.next();
                        executaupdate.update("update cliente set disponivel = false where cpf_cliente ='" + rs.getString("fk_cliente_cpf_cliente") + "';");
                        JOptionPane.showMessageDialog(null, "Devolução realizada, Aviso! Usuário com debitos");
                        this.dispose();
                    }
                    else{
                        JOptionPane.showMessageDialog(null, "Devolução realizada");
                        this.dispose();
                    }
                } catch (SQLException ex) {
                    Logger.getLogger(BuscarLivro.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            else{
                JOptionPane.showMessageDialog(null, "O livro não pode ser devolvido pois nao esta emprestado!");
            }
        }   
        else {
            JOptionPane.showMessageDialog(null, "Nenhum livro foi selecionado!");
        }
    }//GEN-LAST:event_DevolucaoActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Devolucao;
    private javax.swing.JButton Emprestar;
    private javax.swing.JComboBox<String> JCfiltro;
    private javax.swing.JButton Novo;
    private javax.swing.JButton Remover;
    private javax.swing.JButton buscar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable jtablebusca;
    private javax.swing.JTextField jtxtBusca;
    // End of variables declaration//GEN-END:variables
}
