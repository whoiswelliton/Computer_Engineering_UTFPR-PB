CREATE TABLE Secao (
    id_secao serial primary key,
    nome_secao varchar,
    corredor INTEGER,
    prateleira INTEGER
);

	
CREATE TABLE Funcionario (
    cpf varchar PRIMARY KEY,
    senha VARCHAR,
    nome VARCHAR,
    cargo VARCHAR,
    cpf_Gerente varchar,
	foreign key(cpf_Gerente) references Funcionario (cpf)
);

CREATE TABLE Livro (
    codigo_livro serial PRIMARY KEY,
    nome VARCHAR,
    autor VARCHAR,
    edicao VARCHAR,
    disponivel boolean,
	fk_secao_id_secao integer,
	fk_funcionario_cpf varchar,
    FOREIGN KEY (fk_secao_id_secao) REFERENCES secao (id_secao),
    FOREIGN KEY (fk_funcionario_cpf)  REFERENCES Funcionario (cpf)
);

CREATE TABLE Cliente (
    cpf_cliente varchar PRIMARY KEY,
    nome VARCHAR,
    sexo VARCHAR,
    email VARCHAR,
    numero INTEGER,
    rua VARCHAR,
    complemento VARCHAR,
    bairro VARCHAR,
    cep varchar,
    disponivel BOOLEAN,
    datanasc DATE,
    senha varchar not null,
    telefone varchar
	
);


CREATE TABLE Emprestimo (
    id_emp serial PRIMARY KEY,
    data_emp DATE,
    data_dev DATE,
    multa INTEGER,
    data_devolvido DATE,
    fk_Funcionario_CPF varchar,
    fk_Cliente_CPF_cliente varchar,
    fk_livro_codigo_livro integer,
    FOREIGN KEY (fk_livro_codigo_livro) REFERENCES Livro (codigo_livro)   
    FOREIGN KEY (fk_funcionario_cpf) REFERENCES Funcionario (cpf),
    FOREIGN KEY (fk_Cliente_cpf_cliente) REFERENCES Cliente (cpf_cliente) 
);


CREATE TABLE funcionario_livro (
    fk_livro_codigo_livro INTEGER,
    fk_funcionario_CPF varchar,
    FOREIGN KEY (fk_Livro_codigo_livro) REFERENCES Livro (codigo_livro),
    FOREIGN KEY (fk_funcionario_cpf) REFERENCES Funcionario (cpf)	
);

CREATE TABLE Mantem (
    fk_cliente_CPF_cliente varchar,
    fk_funcionario_CPF varchar,
	FOREIGN KEY (fk_funcionario_cpf) REFERENCES Funcionario (cpf),
	FOREIGN KEY (fk_cliente_cpf_cliente) REFERENCES Cliente (cpf_cliente)
);

----------------------------------------------------------------------------------
APAGAR TODAS AS TABELAS DA BASE DE DADOS
----------------------------------------------------------------------------------

drop table mantem;
drop table funcionario_livro;
drop table emp_livro;
drop table emprestimo;
drop table cliente;
drop table livro;
drop table funcionario;
drop table secao;