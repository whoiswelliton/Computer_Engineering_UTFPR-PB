LIBRARY ieee;
USE IEEE.STD_LOGIC_1164.ALL;

entity tb_barrel_shifter is
end tb_barrel_shifter;

architecture arq of tb_barrel_shifter is
	signal entradas, saidas: bit_vector(3 downto 0);
	signal s : std_logic;
	signal numshift : std_logic_vector(1 downto 0);
	
begin
	uut:	entity work.bshifter(arq)		--work.arquivo_que_ira_simular(nome da arquitecture desse arquivo)
	port map(
		entrada => entradas,
		shift => s,
		saida => saidas,
		num_shift => numshift);
	process begin
	entradas <= "1001"; s <= '0'; numshift <= "01"; wait for 10 ns;
	entradas <= "1001"; s <= '1'; numshift <= "01"; wait for 10 ns;
	entradas <= "1111"; s <= '0'; numshift <= "01"; wait for 10 ns;
	entradas <= "1111"; s <= '1'; numshift <= "01"; wait for 10 ns;
	end process;
end arq;