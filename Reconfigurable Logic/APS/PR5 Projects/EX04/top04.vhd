library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;
use work.meupacote04.all;

entity top04 is
	port( mclk, reset: in std_logic;
			anodos: out std_logic_vector(3 downto 0);
			catodos: out std_logic_vector(0 to 7);
			aux4: INOUT std_logic_vector(3 downto 0));
end top04;

architecture Behavioral of top04 is

	TYPE array_integer IS ARRAY (3 DOWNTO 0) of integer range 0 to 15 ;
	TYPE array_integer2 IS ARRAY (1 DOWNTO 0) of integer range 0 to 15 ;
	signal inputNUM: array_integer := (12, 5, 9, 10); --Números arbitrários escolhidos
	signal s: array_integer2;
	signal clk1, clk2 : std_logic;
	signal aux3 : std_logic_vector(1 downto 0);
	signal binary : std_logic_vector(3 downto 0);
	signal outmux: integer range 0 to 15;
	
	begin
		map1 : entity work.clkgen2(Behavioral)
		port map(mclk, reset, clk1); 

		map2 : entity work.clkgen4(Behavioral)
		port map(mclk, reset, clk2); 

		aux3 <= clk2 & clk1;
		
		map3 : entity work.mux2x1(Behavioral)
		port map(clk1, inputNUM(0), inputNUM(1), s(0));
		
		map4: entity work.mux2x1(Behavioral)
		port map(clk1, inputNUM(2), inputNUM(3), s(1));
		
		map5 : entity work.mux2x1(Behavioral)
		port map(clk2, s(0), s(1), outmux);

		map6 : entity work.dem2x4(Behavioral)
		port map(aux3, aux4);
		
		binary <= std_logic_vector(to_unsigned( outmux, 4 ));
		
		map7 : entity work.decod7seg(Behavioral)
		port map(binary, aux4, anodos, catodos); 
		
end Behavioral;