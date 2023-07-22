/*
	Alunos: Geilso Faria Rodrigues da Silva
			Rodrigo Quinhone Veiga Durais
*/
create schema empresa;
use empresa;
create table loja
(
	nome_loja varchar(15) not null,
	CNPJ varchar(14) primary key
);
create table funcionarios
(
	cpf varchar(11) primary key,
	Pnome varchar(10) not null,
	Minical char,
	Unome varchar(10) not null,
	endereço_func varchar(50),
	sexo char check(sexo='F'or sexo='M'),
	Telefone varchar(15) not null,
	Salário decimal(6,2) not null,
	Cpf_gerente varchar(11),
	Loja_CNPJ varchar(14) not null,
	foreign key (Loja_CNPJ) references loja(CNPJ) on delete cascade on update cascade,
	foreign key (Cpf_gerente) references funcionarios(cpf) on delete set null on update cascade
);
create table clientes
(
	cpf_cliente varchar(11) primary key not null,
	nome varchar(40) not null,
	endereço varchar(50),
	sexo char check(sexo='F'or sexo='M')
);
create table telefones_clientes
(
	cpf_cliente varchar(11) not null,
	telefone varchar(15) not null,
	primary key (cpf_cliente,telefone),
	foreign key (cpf_cliente) references clientes (cpf_cliente) on delete cascade on update cascade
);
create table pecas
(
	Cod_produto int primary key,
	tipo_peça varchar(30),
	marca varchar(15),
	valor decimal(6,2),
	genero_peca char(1) check(genero_peca='M'or genero_peca='F' or genero_peca='U'),
	quant int,
	CNPJ_loja varchar(14),
	foreign key (CNPJ_loja) references loja(CNPJ) on delete cascade on update cascade
);
create table vendas
(
	cod_venda int not null,
	cpf_cliente varchar(11) not null,
	cpf_vendedor varchar(15) not null,
	primary key (cod_venda,cpf_cliente,cpf_vendedor),
	foreign key (cpf_cliente) references clientes (cpf_cliente) on delete cascade on update cascade,
	foreign key (cpf_vendedor) references funcionarios (cpf) on delete cascade on update cascade
);
create table produtos_vendidos
(
	codigo_venda int not null,
	cod_produtos int,
	quantidade int,
	primary key (codigo_venda,cod_produtos),
	foreign key (codigo_venda) references vendas (cod_venda) on delete cascade on update cascade,
	foreign key (cod_produtos) references pecas (Cod_produto) on delete cascade on update cascade
);
insert into loja values('LojaX','54712536610288');
insert into funcionarios values
('12345678966', 'Joao','M','Wong','Rua Sete de Setembro, 35, Dourados, MS','M','67992345678',5000.00,null,'54712536610288'),
('00012345678', 'Jorge','A','Silva','Rua São José, 34, Dourados, MS','M','67998256423',1900.00,'12345678966','54712536610288'),
('21345678911', 'Aline','B','Lima','Avenida Brasil, 20, Dourados, MS','F','67996022844',1900.00,'12345678966','54712536610288'),
('05165432199', 'Joice','T','Rodrigues','Rua Santo Antônio, 31, Dourados, MS','F','67991200103',1900.00,'12345678966','54712536610288'),
('66158746320', 'Lucas','O','Leite','Rua Cinco, 78, Dourados, MS','M','67994449821',1900.00,'12345678966','54712536610288'),
('85621035598', 'Maria','O','Conceicao','Rua das Gracas, 8, Dourados, MS','F','67990050127',1900.00,'12345678966','54712536610288');
insert into clientes values
('11875426510', 'Jonas Teixeira','Rua das Flores, 21, Dourados, MS','M'),
('00123485964', 'Renata Lima Faria','Rua Tiradentes, Dourados, MS','F'),
('76592225091', 'Maria da Conceicao', 'Avenida Dom Pedro, 96, Rio Brilhante, MS','F'),
('20022019653', 'Tom Rodrigues', 'Avenida Parana, 57, Ponta Pora, MS','M'),
('20091921052', 'Joana Pereira', 'Rua Mato Grosso, Dourados, MS','F'),
('29933356173', 'Eduarda Leite Faria','Rua Primeiro de Maio, Douradina, MS','F'),
('48972356110','Steve Silva', 'Rua Projetada 1, Dourados, MS','M'),
('88896532143','Paula Faria','Avenida Espirito Santo, Dourados, MS','F');
insert into telefones_clientes values
('11875426510','67991234567'),
('11875426510','67992353716'),
('00123485964','67999235106'),
('76592225091','67993270154'),
('20022019653','6796625487'),
('20022019653','6799900125'),
('20091921052','6798270102'),
('29933356173','6799039040'),
('29933356173','6799825345'),
('88896532143','6799925267');
insert into pecas values
(1234,'Camisa','Marca A',78.89,'M',50,'54712536610288'),
(4321,'Vestido','Marca B',99.99,'F',20,'54712536610288'),
(2199,'Blusa','Marca C',49.99,'F',56,'54712536610288'),
(3258,'Short','Marca A',39.99,'M',19,'54712536610288'),
(2193,'Moletom','Marca C',129.99,'U',9,'54712536610288'),
(3567,'Luva','Marca C',19.99,'U',33,'54712536610288'),
(2610,'Lencol Casal','Marca L',149.49,'F',6,'54712536610288'),
(1123,'Toalha de Banho','Marca L',29.99,'M',3,'54712536610288'),
(9851,'Cinto de Couro','Marca C',39.99,'M',5,'54712536610288'),
(7430,'Calca Jeans','Marca A',99.99,'M',41,'54712536610288'),
(7431,'Calca Jeans','Marca A',99.99,'F',35,'54712536610288'),
(3059,'Sapato Infantil','Marca D',89.99,'M',2,'54712536610288'),
(7899,'Roupa de Banho','Marca B',65.99,'F',6,'54712536610288'),
(2793,'Casaco','Marca C',199.99,'F',2,'54712536610288');
insert into vendas values
(001,'11875426510','00012345678'),
(002,'00123485964','00012345678'),
(003,'76592225091','21345678911'),
(004,'20022019653','05165432199'),
(005,'20091921052','66158746320'),
(006,'29933356173','05165432199'),
(007,'48972356110','21345678911'),
(008,'88896532143','00012345678'),
(009,'88896532143','00012345678'),
(010,'20091921052','05165432199'),
(011,'48972356110','21345678911');
insert into produtos_vendidos values
(001, 1234, 2),
(001, 4321, 1),
(001, 2199, 6),
(002, 3258, 1),
(003, 2193, 5),
(004, 3567, 1),
(005, 2610, 3),
(006, 1123, 2),
(007, 9851, 2),
(007, 7430, 5),
(008, 7431, 1),
(009, 3059, 2),
(010, 7899, 1),
(011, 2793, 3);
/*Consultas simples*/
-- 1
/*Selecione todos os funcionários que realizaram algum venda*/
select distinct Pnome, Minical,Unome
from funcionarios,vendas
where cpf=cpf_vendedor;
-- 2
/*Selecione todos os produtos que custam mais de R$20.00*/
select tipo_peça
from pecas
where valor>50.0;
/*Consultas aninhadas*/
-- 1
/*Selecione os nomes dos clientes que não compraram a peça de ID =2610 */
select nome
from clientes
where clientes.cpf_cliente not in
(
	select clientes.cpf_cliente
	from clientes,vendas,produtos_vendidos
	where clientes.cpf_cliente=vendas.cpf_cliente and cod_venda=codigo_venda and cod_produtos=2610
);
-- 2
/*Para cada venda realiza determine o codigo da venda, código do produto e o tipo da
peça*/
select cod_venda, cod_produtos,tipo_peça
from vendas, produtos_vendidos,pecas
where codigo_venda=cod_venda and cod_produtos=Cod_produto
group by cod_venda,cod_produtos
order by (cod_venda);
-- 3
/*Para cada venda recupere nome do cliente que realizou a compra, tipo da peça que o
cliente comprou e o codigo da venda*/
select nome,tipo_peça, cod_venda
from clientes,vendas, pecas, produtos_vendidos
where clientes.cpf_cliente=vendas.cpf_cliente and cod_venda=codigo_venda and
cod_produtos=Cod_produto
order by (cod_venda);
-- 4
/*Selecione o nome dos clientes que não compraram com a vendedora 'Joice' */
select nome
from clientes
where nome not in (select nome
from clientes,funcionarios,vendas
where clientes.cpf_cliente=vendas.cpf_cliente and
cpf=cpf_vendedor and Pnome='Joice');
/*VISÃO*/
/*Escreva uma visão que contenha o nome da peça, o seu gênero, sua marca a sua
quantidade atual e a soma de quantidade de peças vendidas*/
create view A as
select tipo_peça,quant,sum(quantidade),genero_peca,marca
from vendas, produtos_vendidos,pecas
where cod_venda=codigo_venda and cod_produtos=Cod_produto
group by cod_produto;
select * from A;

/*TRIGGER*/
/*Crie um gatilho para diminuir a quantidade de peças (na tabela peças), toda vez em que esta for vendida*/
delimiter $$
create trigger diminui_quant
after insert on produtos_vendidos
for each row
begin
update pecas set quant=quant - new.quantidade;
end $$
delimiter ;