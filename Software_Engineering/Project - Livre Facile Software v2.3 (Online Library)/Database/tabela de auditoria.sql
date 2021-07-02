CREATE TABLE Emprestimo_audit(
	opecacao char,
	data_log date,
    id_emp serial PRIMARY KEY,
    data_emp DATE,
    data_dev DATE,
    multa INTEGER,
    data_devolvido DATE,
    fk_Funcionario_CPF varchar,
    fk_Cliente_CPF_cliente varchar,
    fk_livro_codigo_livro integer
);

CREATE OR REPLACE FUNCTION process_emprestimo_audit()
RETURNS TRIGGER AS $$
BEGIN
IF (TG_OP = 'UPDATE') THEN
INSERT INTO Emprestimo_audit values ('U', current_date, old.id_emp, old.data_emp, old.data_dev, old.multa, old.data_devolvido, old.fk_Funcionario_CPF, old.fk_Cliente_CPF_cliente, old.fk_livro_codigo_livro);
RETURN NEW;
ELSIF (TG_OP = 'INSERT') THEN
INSERT INTO Emprestimo_audit values ('I', current_date, new.id_emp, new.data_emp, new.data_dev, new.multa, new.data_devolvido, new.fk_Funcionario_CPF, new.fk_Cliente_CPF_cliente, new.fk_livro_codigo_livro);
RETURN NEW;
END IF;
RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER emprestimo_audit
BEFORE  INSERT or update ON emprestimo
FOR EACH ROW
EXECUTE PROCEDURE process_emprestimo_audit();