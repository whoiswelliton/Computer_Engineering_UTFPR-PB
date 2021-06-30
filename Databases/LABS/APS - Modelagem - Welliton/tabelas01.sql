CREATE TABLE Funcionario (
    id_func integer PRIMARY KEY,
    nome varchar,

    fk_id_financiamento integer,
    FOREIGN KEY (fk_id_financiamento) REFERENCES Financiamento (id_financiamento)
);

CREATE TABLE Concessionaria (
    cnpj integer PRIMARY KEY,
    nome varchar,
    endereco varchar, 
);

CREATE TABLE Financiamento (
    id_financiamento integer PRIMARY KEY,
    descricao varchar not null,
    endereco varchar,
    num_parcelas integer not null,
    valor_parcela integer not null,

    data_financiamento date not null,
	data_pagamento date not null,
	
	fk_cpf integer not null,
 	FOREIGN KEY (fk_cpf) REFERENCES Cliente (cpf_cliente)	
);

CREATE TABLE Cliente (
	cpf_cliente integer PRIMARY KEY,
	fone_1 varchar not null,
	fone_2 varchar,
	fone_3 varchar
);

CREATE TABLE Carro(
	id_carro integer PRIMARY KEY,
	modelo varchar not null,
	cor varchar not null,
	ano integer not null,
	marca varchar not null,
	importado boolean not null,
	valor integer,
	fk_id_concessionaria integer,
	fk_id_func integer,
	FOREIGN KEY (fk_id_concessionaria) REFERENCES Concessionaria (cnpj),
	FOREIGN KEY (fk_id_func) REFERENCES Funcionario (id_func)
);

CREATE TABLE VENDE(
	data_venda date not null,
	valor integer not null,

	fk_cpf_cliente integer not null,
	fk_id_funcionario integer not null,
	fk_id_carro integer not null PRIMARY KEY,

	FOREIGN KEY (fk_id_funcionario) REFERENCES Funcionario (id_func),
    FOREIGN KEY (fk_cpf_cliente) REFERENCES Cliente (cpf_cliente),
    FOREIGN KEY (fk_id_carro) REFERENCES Carro (id_carro)		
);


