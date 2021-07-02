create index idxfk_funcionario_cpf_e on emprestimo (fk_funcionario_cpf)
	explain select nome, cpf_gerente from funcionario
	where cpf_gerente = '01234567890'
		"Seq Scan on funcionario  (cost=0.00..1.15 rows=1 width=64)"
		"  Filter: ((cpf_gerente)::text = '01234567890'::text)"
		--Nao usou o indice pois a tabela tem poucos dados

create index idxfk_cliente_cpf_cliente_e on emprestimo (fk_cliente_cpf_cliente)
	explain select nome, cpf_gerente from funcionario
	where cpf_gerente = '01234567890'
		"Index Only Scan using idxfk_cliente_cpf_cliente_e on emprestimo  (cost=0.42..8.44 rows=1 width=12)"
		"  Index Cond: (fk_cliente_cpf_cliente = '100000000012'::text)"
		
create index idxfk_livro_codigo_livro_e on emprestimo (fk_livro_codigo_livro)
	explain select fk_livro_codigo_livro from emprestimo
	where fk_livro_codigo_livro < 300
		"Seq Scan on emprestimo  (cost=0.00..59247.76 rows=273174 width=4)"
		"  Filter: (fk_livro_codigo_livro < 300)"

create index idxfk_secao_id_secao on livro(fk_secao_id_secao)
	explain select fk_secao_id_secao from livro
	where fk_secao_id_secao = 1
		"Index Only Scan using idxfk_secao_id_secao on livro  (cost=0.28..5.87 rows=91 width=4)"
		"  Index Cond: (fk_secao_id_secao = 1)"

create index idxLivrosEmprestados on emprestimo(data_devolvido)
where data_devolvido is null
	explain select id_emp from emprestimo
	where data_devolvido is null;
		"Seq Scan on emprestimo  (cost=0.00..57345.01 rows=760974 width=4)"
		"  Filter: (data_devolvido IS NULL)"
--Facilita nas pesquisas de livros que ainda estao emprestados

create index idxautor on livro(autor)
	explain select codigo_livro, nome, disponivel from livro 
	where autor = 'Rosen';
		"Index Scan using idxautor on livro  (cost=0.28..8.29 rows=1 width=13)"
		"  Index Cond: ((autor)::text = 'Rosen'::text)"
--Facilita nas pesquisas dos autores ods livros

create index idxclientedisponivel on cliente(disponivel)
	explain analyze select nome, cpf_cliente, email from cliente
	where disponivel =false;
		"Seq Scan on cliente  (cost=0.00..498.02 rows=8474 width=47) (actual time=0.016..2.997 rows=8474 loops=1)"
		"  Filter: (NOT disponivel)"
--Facilita nas pesquisas dos clientes que nao estao permitidos para emprestimos

create index idxlivrodisponivel on livro(disponivel)

--facilita nas pesquisas para ver se o livro esta disponivel para emprestimo	