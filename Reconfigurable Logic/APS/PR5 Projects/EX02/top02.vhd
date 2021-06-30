library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use work.meupacote02.all;

entity top02 is

port(mclk, reset: in std_logic;
		clk1, clk2, clk3, clk4 : out std_logic );
end top02;

architecture Behavioral of top02 is

begin
map1 : entity work.clkgen2(Behavioral)
port map(mclk, reset, clk1); 

map2 : entity work.clkgen4(Behavioral)
port map(mclk, reset, clk2); 

map3 : entity work.clkgen8(Behavioral)
port map(mclk, reset, clk3); 

map4 : entity work.clkgen16(Behavioral)
port map(mclk, reset, clk4); 

end Behavioral;