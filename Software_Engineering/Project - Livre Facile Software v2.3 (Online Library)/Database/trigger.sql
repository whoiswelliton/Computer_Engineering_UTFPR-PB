create or replace function bloqueialivro()
returns trigger as $$
begin
	--raise notice ' %' ,new.fk_livro_codigo_livro;
	update livro set disponivel = false where codigo_livro = new.fk_livro_codigo_livro;
	return null;
end;
$$
language plpgsql;

create trigger bloqueialivro
after insert on emprestimo
for each row
execute procedure bloqueialivro();

-----------------------------------------------------------------------

CREATE OR REPLACE FUNCTION calculaMulta ()
RETURNS trigger AS $$
declare multacalc integer;
BEGIN
 IF pg_trigger_depth() <> 1 THEN 
        RETURN NEW; 
  END IF;
if new.data_devolvido > old.data_dev then
	multacalc := (new.data_devolvido - old.data_dev)*2;
	--new.multa := multacalc;
	update emprestimo set multa = multacalc where id_emp = old.id_emp;
END if;
return null;
end;
$$ LANGUAGE plpgsql;


create trigger geramulta
after update on emprestimo
for each row
execute procedure calculaMulta();

-----------------------------------------------------------------------

CREATE or replace FUNCTION checaEmprestimo() RETURNS trigger AS $$
BEGIN
IF verificalivro(new.fk_livro_codigo_livro) = false THEN
	RAISE EXCEPTION 'livro com o codigo % livro ja emprestado', new.fk_livro_codigo_livro;
END IF;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER autorizaemprestimo
BEFORE  INSERT ON emprestimo
FOR EACH ROW
EXECUTE PROCEDURE checaemprestimo();

