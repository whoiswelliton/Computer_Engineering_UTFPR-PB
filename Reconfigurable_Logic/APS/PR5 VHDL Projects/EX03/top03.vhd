library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use work.meupacote03.all;

entity top03 is
	port( mclk, reset: in std_logic;
			anodos: out std_logic_vector(3 downto 0);
			catodos: out std_logic_vector(0 to 7));	
end top03;

architecture Behavioral of top03 is
	signal clk1, clk2, clk3, clk4 : std_logic;
	signal aux3 : std_logic_vector(3 downto 0);
	
	begin
		map1 : entity work.clkgen2(Behavioral)
		port map(mclk, reset, clk1); 

		map2 : entity work.clkgen4(Behavioral)
		port map(mclk, reset, clk2); 

		map3 : entity work.clkgen8(Behavioral)
		port map(mclk, reset, clk3); 

		map4 : entity work.clkgen16(Behavioral)
		port map(mclk, reset, clk4); 

		aux3 <= clk4 & clk3 & clk2 & clk1 ;

		map5 : entity work.decod7seg(Behavioral)
		port map(aux3, anodos, catodos); 
		
end Behavioral;