library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_comparador2bits is
end tb_comparador2bits;

architecture arq of tb_comparador2bits is
signal ta0, ta1, tb0, tb1, ty: std_logic;
begin
	uut: entity work.comparador2bits (arq)
	port map(
		a0 => ta0,
		a1 => ta1,
		b0 => tb0,
		b1 => tb1,
		x => ty);
		
		process begin
		ta0 <= '0'; ta1 <= '1'; tb0 <= '1'; tb1 <= '0'; wait for 10 ns;
		ta0 <= '0'; ta1 <= '1'; tb0 <= '1'; tb1 <= '1'; wait for 10 ns;
		ta0 <= '0'; ta1 <= '1'; tb0 <= '0'; tb1 <= '1'; wait for 10 ns;
		ta0 <= '1'; ta1 <= '0'; tb0 <= '0'; tb1 <= '1'; wait for 10 ns;	
		
	
		end process;
end arq;

