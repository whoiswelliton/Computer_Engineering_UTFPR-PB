library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use work.meupacote01.all;

entity top01 is

port(mclk, reset: in std_logic;
		clk1, clk2: out std_logic );
end top01;

architecture Behavioral of top01 is

begin
map1 : entity work.clkgen1(Behavioral)
port map(mclk, reset, clk1); 

map2 : entity work.clkgen2(Behavioral)
port map(mclk, reset, clk2); 

end Behavioral;