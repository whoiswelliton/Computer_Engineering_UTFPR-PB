library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_mux4x2 is
end tb_mux4x2;

architecture arq of tb_mux4x2 is
signal ta, tb, tc, td, te, ty: std_logic;
begin
	uut: entity work.mux4x2(arq)
	port map(
		a => ta,
		b => tb,
		c => tc,
		d => td,
		e => te,
		x => ty);
		
		process begin
		ta <= '0'; tb <= '0'; tc <= '0'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '0'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '0'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '0'; td <= '1'; te <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '1'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '1'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '1'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '0'; tc <= '1'; td <= '1'; te <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '0'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '0'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '0'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '0'; td <= '1'; te <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '1'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '1'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '1'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '0'; tb <= '1'; tc <= '1'; td <= '1'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '0'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '0'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '0'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '0'; td <= '1'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '1'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '1'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '1'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '0'; tc <= '1'; td <= '1'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '0'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '0'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '0'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '0'; td <= '1'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '1'; td <= '0'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '1'; td <= '0'; te <= '1'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '1'; td <= '1'; te <= '0'; wait for 10 ns;
		ta <= '1'; tb <= '1'; tc <= '1'; td <= '1'; te <= '1'; wait for 10 ns;
		end process;
end arq;

