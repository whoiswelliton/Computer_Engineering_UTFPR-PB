create or replace function livrosmaisemprestados(a int)
returns table (Nº_emprestimos bigint, nomec varchar, nomel varchar) as $$
begin 
	return query select count(fk_cliente_cpf_cliente) as Nº_emprestimos, c.nome, l.nome from emprestimo e, livro l, cliente c
where cpf_cliente = fk_cliente_cpf_cliente 
and fk_livro_codigo_livro = codigo_livro
and data_emp > (current_date-a)
group by c.nome,l.nome
order by 1;
end
$$ language plpgsql;
--Funcao que retorna os clientes e seus livros mais emprestados em um periodo 'a' de tempo


-----------------------------------------------------------------------------

create or replace function verificalivro(cd integer)
returns setof boolean as $$
begin
return query select disponivel from livro 
where codigo_livro = cd;
end $$
language plpgsql;
--Funcao que verifica se um livro esta disponivel para emprestimo

select verificalivro(8);

-----------------------------------------------------------------------------


