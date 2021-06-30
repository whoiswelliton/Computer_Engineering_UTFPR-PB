library IEEE;
use IEEE.STD_LOGIC_1164.all;

package meupacote01 is

	component clkgen1 is
		port(mclk, reset: in std_logic;
			clk1: out std_logic );
	end component;

	component clkgen2 is
		port(mclk, reset: in std_logic;
			clk2: out std_logic );
	end component;
	
end package;