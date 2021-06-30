LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use work.meupacote02.all;

entity tb_clk is
end tb_clk;

architecture tb_Behavioral of tb_clk is
signal mclk, reset, clk1, clk2, clk3, clk4 : std_logic := '0';  
constant mclk_period : time := 100 ms;
 
	begin
		uut: entity work.top02(Behavioral)
		port map (mclk, reset, clk1, clk2, clk3, clk4);
		
		process 
			begin
				mclk <= '0'; wait for mclk_period/2; --50ms Nível Baixo
				mclk <= '1'; wait for mclk_period/2; --50ms Nível Alto
		end process;
end;